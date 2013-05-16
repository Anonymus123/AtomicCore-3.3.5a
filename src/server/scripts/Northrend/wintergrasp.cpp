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
#include "OutdoorPvPWG.h"
#include "OutdoorPvPMgr.h"
#include "Vehicle.h"

#define GOSSIP_HELLO_DEMO1  "Katapult bauen!"
#define GOSSIP_HELLO_DEMO2  "Zerst\x94 \brer bauen!"
#define GOSSIP_HELLO_DEMO3  "Belagerungsmaschiene bauen!"
#define GOSSIP_HELLO_DEMO4  "Ich kann nicht noch mehr bauen!"

class npc_demolisher_engineerer : public CreatureScript
{
public:
    npc_demolisher_engineerer() : CreatureScript("npc_demolisher_engineerer") { }

bool OnGossipHello(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if(pPlayer->isGameMaster() || pCreature->GetZoneScript() && pCreature->GetZoneScript()->GetData(pCreature->GetDBTableGUIDLow()))
    {
        if (pPlayer->HasAura(SPELL_CORPORAL))
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO1, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF);
        else if (pPlayer->HasAura(SPELL_LIEUTENANT))
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO1, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO2, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO3, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+2);
        }
    }
    else
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO4, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+9);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    pPlayer->CLOSE_GOSSIP_MENU();
    if(pPlayer->isGameMaster() || pCreature->GetZoneScript() && pCreature->GetZoneScript()->GetData(pCreature->GetDBTableGUIDLow()))
    {
        switch(uiAction - GOSSIP_ACTION_INFO_DEF)
        {
            case 0: pPlayer->CastSpell(pPlayer, 56663, false, NULL, NULL, pCreature->GetGUID()); break;
            case 1: pPlayer->CastSpell(pPlayer, 56575, false, NULL, NULL, pCreature->GetGUID()); break;
            case 2: pPlayer->CastSpell(pPlayer, pPlayer->GetTeamId() ? 61408 : 56661, false, NULL, NULL, pCreature->GetGUID()); break;
        }
    }

    return true;
}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_demolisher_engineererAI(pCreature);
    }

    struct npc_demolisher_engineererAI : public ScriptedAI
    {
        npc_demolisher_engineererAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->SetReactState(REACT_PASSIVE);
        }
    };

};

enum eWintergraspBattleMage
{
    SPELL_PORTAL_VISUAL        = 60223,
    GO_WINTERGRASP_PORTAL      = 193772
};

class npc_wg_ally_battle_mage : public CreatureScript
{
public:
    npc_wg_ally_battle_mage() : CreatureScript("npc_wg_ally_battle_mage") { }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_wg_ally_battle_mageAI(creature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (!sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
            return false;

        if (OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197))
        {
            if (pvpWG->isWarTime())
            {
                if (pvpWG->getDefenderTeam() == TEAM_HORDE)
                    pPlayer->SEND_GOSSIP_MENU(14777, pCreature->GetGUID());
                else
                    pPlayer->SEND_GOSSIP_MENU(14781, pCreature->GetGUID());
            }
            else
            {
                if (pvpWG->getDefenderTeam() == TEAM_HORDE)
                    pPlayer->SEND_GOSSIP_MENU(14775, pCreature->GetGUID());
                else
                    pPlayer->SEND_GOSSIP_MENU(14782, pCreature->GetGUID());
            }
        }
        return true;
    }

    struct npc_wg_ally_battle_mageAI : public ScriptedAI
    {
        npc_wg_ally_battle_mageAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            uiPortalTimer = 0;
            uiPortalPhase = 0;
            Check = true;
        }

        uint32 uiPortalTimer;
        uint8 uiPortalPhase;
        GameObject* WintergraspPortal;
        bool Player;
        bool Check;
        bool Check2;

        void UpdateAI(const uint32 diff)
        {
            if (!sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
                return;

            if (OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197))
            {
                if (pvpWG->isWarTime() && Check == true)
                {
                    Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if (!PlayerList.isEmpty())
                        {
                            if (i->getSource()->GetDistance2d(me) <= 75)
                            {
                                Player = true;
                                Check = false;
                            }
                            else
                            {
                                Player = false;
                                Check = false;
                                Check2 = true;
                            }
                        }
                        else
                        {
                            Player = false;
                            Check = false;
                            Check2 = true;
                        }
                    }
                }

                if (pvpWG->m_changeAlly != true)
                {
                    if (pvpWG->isWarTime())
                    {
                        if (Player == true)
                        {
                            if (uiPortalTimer <= diff)
                            {
                                switch (uiPortalPhase)
                                {
                                case 0:
                                    me->SetOrientation(4.037271f);
                                    me->SendMovementFlagUpdate();
                                    ++uiPortalPhase;
                                    uiPortalTimer = 100;
                                    break;
                                case 1:
                                    me->AI()->DoCast(SPELL_PORTAL_VISUAL);
                                    ++uiPortalPhase;
                                    uiPortalTimer = 900;
                                    break;
                                case 2:
                                    WintergraspPortal = me->SummonGameObject(GO_WINTERGRASP_PORTAL, 5686.974609f, 773.303711f, 647.753235f, 5.572729f, 0, 0, 0.324484f, -0.945891f, 0);
                                    me->SetOrientation(5.515240f);
                                    me->SendMovementFlagUpdate();
                                    me->MonsterYell("Auf dem Tausendwinter Schlachtfeld wird Verst\x84 \brkung ben\x94 \btigt! Ich habe ein Portal ge\x94 \bffnet, damit Ihr schnneller dorthin reisen könnt!", LANG_UNIVERSAL, 0);
                                    ++uiPortalPhase;
                                    uiPortalTimer = 1000;
                                    break;
                                }
                            }else uiPortalTimer -= diff;
                        }
                        else
                        {
                            if (Check2 == true)
                            {
                                WintergraspPortal = me->SummonGameObject(GO_WINTERGRASP_PORTAL, 5686.974609f, 773.303711f, 647.753235f, 5.572729f, 0, 0, 0.324484f, -0.945891f, 0);
                                Check2 = false;
                            }
                        }
                    }
                    else
                    {
                        if (pvpWG->getDefenderTeam() == TEAM_ALLIANCE)
                        {
                            if (pvpWG->m_timer <= 3600000)
                            {
                                uiPortalTimer = 0;
                                uiPortalPhase = 0;
                                Check = true;
                                Check2 = false;
                                if (GameObject* WintergraspPortal = me->FindNearestGameObject(GO_WINTERGRASP_PORTAL, 5.0f))
                                    WintergraspPortal->RemoveFromWorld();
                            }
                        }
                        else
                        {
                            uiPortalTimer = 0;
                            uiPortalPhase = 0;
                            Check = true;
                            Check2 = false;
                            if (GameObject* WintergraspPortal = me->FindNearestGameObject(GO_WINTERGRASP_PORTAL, 5.0f))
                                WintergraspPortal->RemoveFromWorld();
                        }
                    }
                }
            }
        }
    };
};

class npc_wg_horde_battle_mage : public CreatureScript
{
public:
    npc_wg_horde_battle_mage() : CreatureScript("npc_wg_horde_battle_mage") { }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_wg_horde_battle_mageAI(creature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (!sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
            return false;

        if (OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197))
        {
            if (pvpWG->isWarTime())
            {
                if (pvpWG->getDefenderTeam() == TEAM_HORDE)
                    pPlayer->SEND_GOSSIP_MENU(14777, pCreature->GetGUID());
                else
                    pPlayer->SEND_GOSSIP_MENU(14781, pCreature->GetGUID());
            }
            else
            {
                if (pvpWG->getDefenderTeam() == TEAM_HORDE)
                    pPlayer->SEND_GOSSIP_MENU(14775, pCreature->GetGUID());
                else
                    pPlayer->SEND_GOSSIP_MENU(14782, pCreature->GetGUID());
            }
        }
        return true;
    }

    struct npc_wg_horde_battle_mageAI : public ScriptedAI
    {
        npc_wg_horde_battle_mageAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            uiPortalTimer = 0;
            uiPortalPhase = 0;
            Check = true;
        }

        uint32 uiPortalTimer;
        uint8 uiPortalPhase;
        GameObject* WintergraspPortal;
        bool Player;
        bool Check;
        bool Check2;

        void UpdateAI(const uint32 diff)
        {
            if (!sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
                return;

            if (OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197))
            {
                if (pvpWG->isWarTime() && Check == true)
                {
                    Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if (!PlayerList.isEmpty())
                        {
                            if (i->getSource()->GetDistance2d(me) <= 75)
                            {
                                Player = true;
                                Check = false;
                            }
                            else
                            {
                                Player = false;
                                Check = false;
                                Check2 = true;
                            }
                        }
                        else
                        {
                            Player = false;
                            Check = false;
                            Check2 = true;
                        }
                    }
                }

                if (pvpWG->m_changeHorde != true)
                {
                    if (pvpWG->isWarTime())
                    {
                        if (Player == true)
                        {
                            if (uiPortalTimer <= diff)
                            {
                                switch (uiPortalPhase)
                                {
                                case 0:
                                    me->SetOrientation(4.356160f);
                                    me->SendMovementFlagUpdate();
                                    ++uiPortalPhase;
                                    uiPortalTimer = 100;
                                    break;
                                case 1:
                                    me->AI()->DoCast(SPELL_PORTAL_VISUAL);
                                    ++uiPortalPhase;
                                    uiPortalTimer = 900;
                                    break;
                                case 2:
                                    WintergraspPortal = me->SummonGameObject(GO_WINTERGRASP_PORTAL, 5924.042969f, 570.354492f, 661.087280f, 5.930885f, 0, 0, 0.324484f, -0.945891f, 0);
                                    me->SetOrientation(6.003930f);
                                    me->SendMovementFlagUpdate();
                                    ++uiPortalPhase;
                                    uiPortalTimer = 1000;
                                    break;
                                }
                            }else uiPortalTimer -= diff;
                        }
                        else
                        {
                            if (Check2 == true)
                            {
                                WintergraspPortal = me->SummonGameObject(GO_WINTERGRASP_PORTAL, 5686.974609f, 773.303711f, 647.753235f, 5.572729f, 0, 0, 0.324484f, -0.945891f, 0);
                                Check2 = false;
                            }
                        }
                    }
                    else
                    {
                        if (pvpWG->getDefenderTeam() == TEAM_HORDE)
                        {
                            if (pvpWG->m_timer <= 3600000)
                            {
                                uiPortalTimer = 0;
                                uiPortalPhase = 0;
                                Check = true;
                                Check2 = false;
                                if (GameObject* WintergraspPortal = me->FindNearestGameObject(GO_WINTERGRASP_PORTAL, 5.0f))
                                    WintergraspPortal->RemoveFromWorld();
                            }
                        }
                        else
                        {
                            uiPortalTimer = 0;
                            uiPortalPhase = 0;
                            Check = true;
                            Check2 = false;
                            if (GameObject* WintergraspPortal = me->FindNearestGameObject(GO_WINTERGRASP_PORTAL, 5.0f))
                                WintergraspPortal->RemoveFromWorld();
                        }
                    }
                }
            }
        }
    };
};

class go_wg_veh_teleporter : public GameObjectScript
{
public:
    go_wg_veh_teleporter() : GameObjectScript("go_wg_veh_teleporter") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (GameObject* trigger = go->FindNearestGameObject(190375, 500))
        {
            if (Vehicle* vehicle = player->GetVehicle())
            {
                Position triggerPos;
                trigger->GetPosition(&triggerPos);
                triggerPos.m_positionX -= 30;
                vehicle->Relocate(triggerPos);
            }
        }
        return true;
    }
};

void AddSC_wintergrasp()
{
    new npc_demolisher_engineerer();
    new npc_wg_ally_battle_mage();
    new npc_wg_horde_battle_mage();
    new go_wg_veh_teleporter();
}