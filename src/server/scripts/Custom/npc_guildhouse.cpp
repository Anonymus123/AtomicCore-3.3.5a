/**********************************************************************************************
*                                                                                             *
*                          ______ _  __   _____ ____  _____  ______                           *
*                         |  ____| |/ /  / ____/ __ \|  __ \|  ____|                          *
*                         | |__  | ' /  | |   | |  | | |__) | |__                             *
*                         |  __| |  <   | |   | |  | |  _  /|  __|                            *
*                         | |    | . \  | |___| |__| | | \ \| |____                           *
*                         |_|    |_|\_\  \_____\____/|_|  \_\______|                          *
*                                                                                             *
*                              Copyright (c) Frozen Kingdom WoW                               *
*                                                                                             *
*                                                                                             *
*            Diese Emulation unterliegt vollständig dem Copyright / Kopierschutz              *
*            von Frozen Kingdom WoW. Sämtliche Vervielfältigung oder Verbreitung              *
*            dieser hier enthaltenen Medien wird juristisch bestraft. Diese                   *
*            Software darf nur vom Herausgeber Frozen Kingdom WoW verwendet bzw               *
*            Weiterverwendet werden.                                                          *
*                                                                                             *
*                                                                                             *
*            This emulation is subject to the law of copyright from "The Frozen               *
*            Kingdom World of Warcraft" servers. All copying of these here contained          *
*            content, will be legitimate punished. This software must only used by            *
*            the publisher.                                                                   *
*                                                                                             *
**********************************************************************************************/

#include "ScriptPCH.h"

extern WorldDatabaseWorkerPool WorldDatabase;


//Texte
#define MSG_GOSSIP_TELE          "Teleportiere mich zu unserem Gildenhaus."
#define MSG_GOSSIP_BUY           "Kaufe Gildenhaus (50000 Gold)"
#define MSG_GOSSIP_SELL          "Verkaufe Gildenhaus (25000 Gold)"
#define MSG_GOSSIP_NEXTPAGE      "Weiter..."
#define MSG_INCOMBAT             "Du bist im Kampf."
#define MSG_NOGUILDHOUSE         "Deine Gilde besitzt kein Gildenhaus."
#define MSG_NOFREEGH             "Leider sind alle Gildenhaeuser verkauft."
#define MSG_ALREADYHAVEGH        "Tut mir Leid, aber du besitzt bereits ein Gildenhaus (%s)."
#define MSG_NOTENOUGHMONEY       "Du hast nicht die benötigten 50000 Gold um ein Gildenhaus zu kaufen."
#define MSG_GHOCCUPIED           "Dieses Gildenhaus kann nicht gekauft werden, da es bereits in Benutzung ist."
#define MSG_CONGRATULATIONS      "Du hast erfolgreich ein Gildenhaus gekauft!"
#define MSG_SOLD                 "Du hast dein Gildenhaus verkauft und %s Gold erhalten."
#define MSG_NOTINGUILD           "Du musst in einer Gilde sein um ein Gildenhaus zu kaufen."
#define CODE_SELL                "VERKAUFEN"
#define MSG_CODEBOX_SELL         "Bitte gebe nun \"" CODE_SELL "\" in das Textfeld ein um den Verkauf deines Gildenhauses zu authorisieren."

//Kosten
#define COST_GH_BUY 500000000
#define COST_GH_SELL 250000000

//Sonstiges
#define OFFSET_GH_ID_TO_ACTION 1500
#define OFFSET_SHOWBUY_FROM 10000
#define ACTION_TELE 1001
#define ACTION_SHOW_BUYLIST 1002
#define ACTION_SELL_GUILDHOUSE 1003
#define GOSSIP_COUNT_MAX 10

bool isPlayerGuildLeader(Player *player)
{
    return (player->GetRank() == 0) && (player->GetGuildId() != 0);
}

bool getGuildHouseCoords(uint32 guildId, float &x, float &y, float &z, uint32 &map)
{
    if (guildId == 0)
    {
        return false;
    }

    QueryResult result;
	result = CharacterDatabase.PQuery("SELECT `x`, `y`, `z`, `map` FROM `guildhouses` WHERE `guildId` = %u", guildId);
    if (result)
    {
        Field *fields = result->Fetch();
        x = fields[0].GetFloat();
        y = fields[1].GetFloat();
        z = fields[2].GetFloat();
        map = fields[3].GetUInt32();
        return true;
    }
    return false;
}

void teleportPlayerToGuildHouse(Player *player, Creature *_creature)
{
    if (player->GetGuildId() == 0)
    {
        _creature->MonsterWhisper(MSG_NOTINGUILD, player->GetGUID());
        return;
    }

    if (!player->getAttackers().empty())
    {
        _creature->MonsterSay(MSG_INCOMBAT, LANG_UNIVERSAL, player->GetGUID());
        return;
    }

    float x, y, z;
    uint32 map;

    if (getGuildHouseCoords(player->GetGuildId(), x, y, z, map))
    {
        player->TeleportTo(map, x, y, z, 0.0f);
    }
    else
        _creature->MonsterWhisper(MSG_NOGUILDHOUSE, player->GetGUID());
}

bool showBuyList(Player *player, Creature *_creature, uint32 showFromId = 0)
{
    QueryResult result;
    result = CharacterDatabase.PQuery("SELECT `id`, `comment` FROM `guildhouses` WHERE `guildId` = 0 AND `id` > %u ORDER BY `id` ASC LIMIT %u",
    showFromId, GOSSIP_COUNT_MAX);

    if (result)
    {
        uint32 guildhouseId = 0;
        std::string comment = "";
        do
        {
            Field *fields = result->Fetch();
            guildhouseId = fields[0].GetInt32();
            comment = fields[1].GetString();
            player->ADD_GOSSIP_ITEM(ICON_GOSSIP_TABARD, comment, GOSSIP_SENDER_MAIN,
            guildhouseId + OFFSET_GH_ID_TO_ACTION);
        }
        while (result->NextRow());

        if (result->GetRowCount() == GOSSIP_COUNT_MAX)
        {
            player->ADD_GOSSIP_ITEM(ICON_GOSSIP_BALOONDOTS, MSG_GOSSIP_NEXTPAGE, GOSSIP_SENDER_MAIN,
            guildhouseId + OFFSET_SHOWBUY_FROM);
        }
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
        return true;
    }
    else
    {
        if (showFromId = 0)
        {
            _creature->MonsterWhisper(MSG_NOFREEGH, player->GetGUID());
            player->CLOSE_GOSSIP_MENU();
        }
        else
        {
            showBuyList(player, _creature, 0);
        }
    }
    return false;
}

bool isPlayerHasGuildhouse(Player *player, Creature *_creature, bool whisper = false)
{
    QueryResult result;
    result = CharacterDatabase.PQuery("SELECT `comment` FROM `guildhouses` WHERE `guildId` = %u",
    player->GetGuildId());

    if (result)
    {
        if (whisper)
        {
            Field *fields = result->Fetch();
            char msg[100];
            sprintf(msg, MSG_ALREADYHAVEGH, fields[0].GetString());
            _creature->MonsterWhisper(msg, player->GetGUID());
        }
        return true;
    }
    return false;
}

void buyGuildhouse(Player *player, Creature *_creature, uint32 guildhouseId)
{
    if (player->GetMoney() < COST_GH_BUY)
    {
        char msg[100];
        sprintf(msg, MSG_NOTENOUGHMONEY, COST_GH_BUY / 10000);
        _creature->MonsterWhisper(msg, player->GetGUID());
        return;
    }

    if (isPlayerHasGuildhouse(player, _creature, true))
    {
        return;
    }

    QueryResult result;
    result = CharacterDatabase.PQuery("SELECT `id` FROM `guildhouses` WHERE `id` = %u AND `guildId` <> 0", guildhouseId);

    if (result)
    {
    _creature->MonsterWhisper(MSG_GHOCCUPIED, player->GetGUID());
    return;
    }

    result = CharacterDatabase.PQuery("UPDATE `guildhouses` SET `guildId` = %u WHERE `id` = %u",
    player->GetGuildId(), guildhouseId);

    if (result)
        player->ModifyMoney(-COST_GH_BUY);
    _creature->MonsterSay(MSG_CONGRATULATIONS, LANG_UNIVERSAL, player->GetGUID());
}

void sellGuildhouse(Player *player, Creature *_creature)
{
    if (isPlayerHasGuildhouse(player, _creature))
    {
        QueryResult result;
        result = CharacterDatabase.PQuery("UPDATE `guildhouses` SET `guildId` = 0 WHERE `guildId` = %u",
        player->GetGuildId());

        if (result)
            player->ModifyMoney(COST_GH_SELL);

        char msg[100];
        sprintf(msg, MSG_SOLD, COST_GH_SELL / 10000);
        _creature->MonsterWhisper(msg, player->GetGUID());
    }
}

class guildmaster : public CreatureScript
{
    public:
        guildmaster() : CreatureScript("guildmaster") { }

    bool GossipSelectWithCode(Player *player, Creature *_creature, uint32 sender, uint32 action, const char* sCode)
    {
        if (sender == GOSSIP_SENDER_MAIN)
        {
            if (action == ACTION_SELL_GUILDHOUSE)
            {
                int i = -1;
                try
                {
                    if (strlen(sCode) + 1 == sizeof CODE_SELL)
                    i = strcmp(CODE_SELL, sCode);
                }
                    catch(char *str) {sLog->outErrorDb(str);
                }
                if (i == 0)
                {
                    sellGuildhouse(player, _creature);
                }
                player->CLOSE_GOSSIP_MENU();
                    return true;
            }
        }
        return false;
    }

    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (sender != GOSSIP_SENDER_MAIN)
            return false;

        switch (action)
        {
            case ACTION_TELE:
                player->CLOSE_GOSSIP_MENU();
                teleportPlayerToGuildHouse(player, _creature);
                break;
            case ACTION_SHOW_BUYLIST:
                showBuyList(player, _creature);
                break;
            default:
                if (action > OFFSET_SHOWBUY_FROM)
                {
                    showBuyList(player, _creature, action - OFFSET_SHOWBUY_FROM);
                }
                else if (action > OFFSET_GH_ID_TO_ACTION)
                {
                    player->CLOSE_GOSSIP_MENU();
                    buyGuildhouse(player, _creature, action - OFFSET_GH_ID_TO_ACTION);
                }
                break;
        }
        return true;
    }
    
    bool OnGossipHello(Player *player, Creature *_creature)
    {
        player->ADD_GOSSIP_ITEM(ICON_GOSSIP_BALOON, MSG_GOSSIP_TELE,
        GOSSIP_SENDER_MAIN, ACTION_TELE);
        if (isPlayerGuildLeader(player))
        {
            if (isPlayerHasGuildhouse(player, _creature))
            {
                player->PlayerTalkClass->GetGossipMenu().AddMenuItem(ICON_GOSSIP_GOLD, MSG_GOSSIP_SELL, GOSSIP_SENDER_MAIN, ACTION_SELL_GUILDHOUSE, MSG_CODEBOX_SELL, 0, true);
            }
            else
            {
                player->ADD_GOSSIP_ITEM(ICON_GOSSIP_GOLD, MSG_GOSSIP_BUY,
                GOSSIP_SENDER_MAIN, ACTION_SHOW_BUYLIST);
            }
        }
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
            return true;
    }
};

void AddSC_guildmaster()
{
    new guildmaster();
}