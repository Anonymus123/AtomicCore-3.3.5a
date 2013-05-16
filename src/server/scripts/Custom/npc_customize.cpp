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

enum ActNpcRename
{
    ACT_RENAME                	    = 1001,
    ACT_CUSTOMIZE             	    = 1002,
    ACT_CUSTOMIZE_RACE             	= 1003,	
    ACT_CUSTOMIZE_FACTION        	= 1004,	
    ACT_CONFIRM_RENAME        	    = 1005,
    ACT_CONFIRM_CUSTOMIZE     	    = 1006,
    ACT_CONFIRM_CUSTOMIZE_RACE     	= 1007,	
    ACT_CONFIRM_CUSTOMIZE_FACTION	= 1008,
};

enum Prices
{
	PRISE_RENAME_CHAR_AP            = 250000000,
	PRISE_CUSTOMIZE_CHAR_AP         = 250000000,
	PRISE_CUSTOMIZE_RACE_CHAR_AP    = 500000000,
	PRISE_CUSTOMIZE_FACTION_CHAR_AP = 1000000000
};

#define GOSSIP_RENAME_HELLO "Ich will den Namen meines Charakters anpassen."
#define GOSSIP_CUSTOMIZE_HELLO "Ich will das Aussehen oder das Geschlecht meines Charakters anpassen."
#define GOSSIP_CUSTOMIZE_RACE_HELLO "Ich will meine Rasse wechseln."
#define GOSSIP_CUSTOMIZE_FACTION_HELLO "Ich will meine Fraktion wechseln."
#define	GOSSIP_RENAME_CONFIRM "Willst du deinen Charakter wirklich umbenennen? (Kosten 25000 Gold)"
#define GOSSIP_CUSTOMIZE_CONFIRM "Willst du das Aussehen deines Charakters wirklich anpassen? (Kosten 25000 Gold)"
#define GOSSIP_CUSTOMIZE_FACTION_RACE "Willst du die Rasse deines Charakters wirklich anpassen? (Kosten 50000 Gold)"
#define GOSSIP_CUSTOMIZE_FACTION_CONFIRM "Willst du die Fraktion deines Charakters wirklich anpassen? (Kosten 100000 Gold)"
#define MSG_NOT_MONEY_FOR_RENAME "Du hast nicht genug Gold!"

class npc_customize : public CreatureScript
{
public:
    npc_customize() : CreatureScript("npc_customize") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_RENAME_HELLO, GOSSIP_SENDER_MAIN, ACT_RENAME);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CUSTOMIZE_HELLO, GOSSIP_SENDER_MAIN, ACT_CUSTOMIZE);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CUSTOMIZE_RACE_HELLO, GOSSIP_SENDER_MAIN, ACT_CUSTOMIZE_RACE);			
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CUSTOMIZE_FACTION_HELLO, GOSSIP_SENDER_MAIN, ACT_CUSTOMIZE_FACTION);		
        pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
    {
        if (uiSender != GOSSIP_SENDER_MAIN)
            return false;

        pPlayer->PlayerTalkClass->ClearMenus();

        switch (uiAction)
        {
        case ACT_RENAME:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_RENAME_CONFIRM, GOSSIP_SENDER_MAIN, ACT_CONFIRM_RENAME);
            pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
            break;
        case ACT_CUSTOMIZE:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CUSTOMIZE_CONFIRM, GOSSIP_SENDER_MAIN, ACT_CONFIRM_CUSTOMIZE);
            pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
            break;
        case ACT_CUSTOMIZE_RACE:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CUSTOMIZE_FACTION_RACE, GOSSIP_SENDER_MAIN, ACT_CONFIRM_CUSTOMIZE_RACE);
            pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
            break;				
        case ACT_CUSTOMIZE_FACTION:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CUSTOMIZE_FACTION_CONFIRM, GOSSIP_SENDER_MAIN, ACT_CONFIRM_CUSTOMIZE_FACTION);
            pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
            break;			
        case ACT_CONFIRM_RENAME:
            if (pPlayer->GetMoney() < PRISE_RENAME_CHAR_AP)
            {
                pCreature->MonsterWhisper(MSG_NOT_MONEY_FOR_RENAME, pPlayer->GetGUID());
            }else{
                pPlayer->ModifyMoney(-PRISE_RENAME_CHAR_AP);
                pPlayer->SetAtLoginFlag(AT_LOGIN_RENAME);
            }
            pPlayer->CLOSE_GOSSIP_MENU();
            break;
        case ACT_CONFIRM_CUSTOMIZE:
            if (pPlayer->GetMoney() < PRISE_CUSTOMIZE_CHAR_AP)
            {
                pCreature->MonsterWhisper(MSG_NOT_MONEY_FOR_RENAME, pPlayer->GetGUID());
            }else{
                pPlayer->ModifyMoney(-PRISE_CUSTOMIZE_CHAR_AP);
                pPlayer->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
            }
            pPlayer->CLOSE_GOSSIP_MENU();
            break;
        case ACT_CONFIRM_CUSTOMIZE_RACE:
            if (pPlayer->GetMoney() < PRISE_CUSTOMIZE_RACE_CHAR_AP)
            {
                pCreature->MonsterWhisper(MSG_NOT_MONEY_FOR_RENAME, pPlayer->GetGUID());
            }else{
                pPlayer->ModifyMoney(-PRISE_CUSTOMIZE_RACE_CHAR_AP);
                pPlayer->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
            }
            pPlayer->CLOSE_GOSSIP_MENU();
            break;				
        case ACT_CONFIRM_CUSTOMIZE_FACTION:
            if (pPlayer->GetMoney() < PRISE_CUSTOMIZE_FACTION_CHAR_AP)
            {
                pCreature->MonsterWhisper(MSG_NOT_MONEY_FOR_RENAME, pPlayer->GetGUID());
            }else{
                pPlayer->ModifyMoney(-PRISE_CUSTOMIZE_FACTION_CHAR_AP);
                pPlayer->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
            }
            pPlayer->CLOSE_GOSSIP_MENU();
            break;
		default:
            pPlayer->CLOSE_GOSSIP_MENU();
        }
        return true;
    }
};

void AddSC_npc_customize()
{
    new npc_customize;
}