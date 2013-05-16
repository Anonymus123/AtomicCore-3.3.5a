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

class EventTeleporter : public CreatureScript
{
    public:
        EventTeleporter() : CreatureScript("EventTeleporter")  { }
    
		bool OnGossipHello(Player* pPlayer, Creature* pCreature)
		{
			MainMenu(pPlayer, pCreature);
			return true;
		}
       
		void MainMenu(Player *pPlayer, Creature *pCreature)
		{
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Bring mich zum Labyrinth Event!", GOSSIP_SENDER_MAIN, 1000);
			//pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Bring mich zum Stair Event!", GOSSIP_SENDER_MAIN, 2000);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Bring mich zum Hochzeits Event!", GOSSIP_SENDER_MAIN, 3000);
            //pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Bring mich zum heroischen Verlies!", GOSSIP_SENDER_MAIN, 4000);
			pPlayer->SEND_GOSSIP_MENU(907, pCreature->GetGUID());
		}
       
		bool OnGossipSelect(Player* Plr, Creature* pCrea, uint32 /*uiSender*/, uint32 uiAction)
		{
			if (Plr->isInCombat())
			{
				pCrea->MonsterWhisper("Ihr seid im Kampf!", Plr->GetGUID());
				Plr->CLOSE_GOSSIP_MENU();
				return true;
			}
           
			Plr->PlayerTalkClass->ClearMenus();
           
			switch (uiAction)
			{
				case 1000:
					Plr->CLOSE_GOSSIP_MENU();
					Plr->TeleportTo(0,-7486.84f,1339.62f,131.407f,4.76584f);
					break;
				case 2000:
					Plr->CLOSE_GOSSIP_MENU();
					Plr->TeleportTo(1,4618.59f,-2098.11f,1236.97f,1.77864f);
					break;
                case 3000:
					Plr->CLOSE_GOSSIP_MENU();
					Plr->TeleportTo(0,-8528.88f,-1571.4f,637.706f,0.303512f);
					break;
                case 4000:
					Plr->CLOSE_GOSSIP_MENU();
					Plr->TeleportTo(0,-8636.42f,585.335f,95.6902f,2.19344f);
					break;
				default:
					break;
			}
			Plr->CLOSE_GOSSIP_MENU();
			return true;
		}
};

void AddSC_EventTeleporter()
{
    new EventTeleporter();
}
                