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
#include "Config.h"

class npc_vip : public CreatureScript
{
public:
    npc_vip() : CreatureScript("npc_vip") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (!player->GetSession()->IsPremium() && !player->isGameMaster())
        {
            player->CLOSE_GOSSIP_MENU();
            creature->MonsterWhisper("Es tut mir leid $N, Du bist kein Premium Mitglied.", player->GetGUID(), false);
            return true;
        }

        if (creature->isVendor())
        {
            player->CLOSE_GOSSIP_MENU();
            player->GetSession()->SendListInventory(creature->GetGUID());
            return true;
        }

        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Buffs", GOSSIP_SENDER_MAIN, 1201);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Traenke / Elixiere", GOSSIP_SENDER_MAIN, 1202);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Teleporter", GOSSIP_SENDER_MAIN, 1203);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Event Teleporter", GOSSIP_SENDER_MAIN, 1204);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Talente Resetten", GOSSIP_SENDER_MAIN, 1205);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Manastrudel", GOSSIP_SENDER_MAIN, 1206);		
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Seelensplitter", GOSSIP_SENDER_MAIN, 1207);		
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Mana Stein", GOSSIP_SENDER_MAIN, 1208);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Betrinken", GOSSIP_SENDER_MAIN, 1209);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Ausnuechtern", GOSSIP_SENDER_MAIN, 1210);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Todesnachwirkungen entfernen", GOSSIP_SENDER_MAIN, 1211);		
        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
		uint8 level = player->getLevel();

        switch(action)
        {
            case 1201:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Mal der Wildnis", GOSSIP_SENDER_MAIN, 2002);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Arkane Brillanz", GOSSIP_SENDER_MAIN, 2003);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Segen der Koenige", GOSSIP_SENDER_MAIN, 2004);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Segen der Macht", GOSSIP_SENDER_MAIN, 2005);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Segen der Weisheit", GOSSIP_SENDER_MAIN, 2006);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Segen des Refugiums", GOSSIP_SENDER_MAIN, 2007);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Furchtzauberschutz", GOSSIP_SENDER_MAIN, 2008);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Machtwort: Seelenstaerke", GOSSIP_SENDER_MAIN, 2009);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Goettlicher Wille", GOSSIP_SENDER_MAIN, 2010);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Schattenschutz", GOSSIP_SENDER_MAIN, 2011);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Dornen", GOSSIP_SENDER_MAIN, 2012);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Horn des Winters", GOSSIP_SENDER_MAIN, 2013);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Seelensteinauferstehung", GOSSIP_SENDER_MAIN, 2014);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                break;	
            case 1202:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Flaeschchen des reinen Mojo", GOSSIP_SENDER_MAIN, 2015);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Flaeschchen des Steinbluts", GOSSIP_SENDER_MAIN, 2016);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Flaeschchen des Frostwyrms", GOSSIP_SENDER_MAIN, 2017);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Flaeschchen der endlosen Wut", GOSSIP_SENDER_MAIN, 2018);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Flaeschchen des Nordens", GOSSIP_SENDER_MAIN, 2019);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                break;
            case 1203:
                if (player->GetTeam() == ALLIANCE)
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Sturmwind", GOSSIP_SENDER_MAIN, 9500);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Eisenschmiede", GOSSIP_SENDER_MAIN, 9501);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Darnassus", GOSSIP_SENDER_MAIN, 9502);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Exodar", GOSSIP_SENDER_MAIN, 9503);
                }
                else
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Orgrimmar", GOSSIP_SENDER_MAIN, 8500);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Silbermond", GOSSIP_SENDER_MAIN, 8501);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Donnerfels", GOSSIP_SENDER_MAIN, 8502);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Unterstadt", GOSSIP_SENDER_MAIN, 8503);
                }
                if(player->getLevel() >= 58)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Shattrath", GOSSIP_SENDER_MAIN, 9750);
                if(player->getLevel() >= 68)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Dalaran", GOSSIP_SENDER_MAIN, 9751);
                player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                break;
            case 1204:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Bring mich zum Labyrinth Event!", GOSSIP_SENDER_MAIN, 9900);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Bring mich zum Stair Event!", GOSSIP_SENDER_MAIN, 9901);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Bring mich zum Hochzeits Event!", GOSSIP_SENDER_MAIN, 9902);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Bring mich zur neuen Verlies Instanz!", GOSSIP_SENDER_MAIN, 9903);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                break;
            case 1205:
                player->CLOSE_GOSSIP_MENU();
                player->SendTalentWipeConfirm(creature->GetGUID());
                break;
            case 1206:
                player->CLOSE_GOSSIP_MENU();
				player->CastSpell(player, 42956, false);
                break;
            case 1207:
                player->CLOSE_GOSSIP_MENU();
				player->CastSpell(player, 24827, false);
                break;
            case 1208:
                player->CLOSE_GOSSIP_MENU();
				player->CastSpell(player, 42985, false);
                break;
            case 1209:
                player->CLOSE_GOSSIP_MENU();
				player->CastSpell(player, 46876, false);
				creature->MonsterWhisper("Prost!", LANG_UNIVERSAL, NULL);
                break;
            case 1210:
                player->CLOSE_GOSSIP_MENU();
				player->SetDrunkValue(0, 9);
                creature->MonsterWhisper("Leicht schwindelig, hm?", LANG_UNIVERSAL, NULL);
            case 1211:
                if (!player->HasAura(15007, 0))
				{
					creature->MonsterWhisper("Du hast keine Todesnachwirkungen.", player->GetGUID());
					OnGossipHello(player, creature);
				}
                else
                {
                    creature->CastSpell(player, 38588, false);
                    player->RemoveAurasDueToSpell(15007, 0);
                }
				player->CLOSE_GOSSIP_MENU();
                break;      
            case 2002:
				if(level >= 80)
                    player->CastSpell(player, 48469, false);
				else if(level >= 70)
                    player->CastSpell(player, 26990, false);
				else if(level >= 60)
                    player->CastSpell(player, 9885, false);
				else if(level >= 50)
                    player->CastSpell(player, 9884, false);
				else if(level >= 40)
                    player->CastSpell(player, 8907, false);
				else if(level >= 30)
                    player->CastSpell(player, 5234, false);
				else if(level >= 20)
                    player->CastSpell(player, 6756, false);
				else if(level >= 10)
                    player->CastSpell(player, 5232, false);
                else if(level >= 1)
                    player->CastSpell(player, 1126, false);             
                break;   
            case 2003:
				if(level >= 80)    
                    player->CastSpell(player, 42995, false);
				else if(level >= 70)
                    player->CastSpell(player, 27126, false);
				else if(level >= 56)
                    player->CastSpell(player, 10157, false);
				else if(level >= 42)
                    player->CastSpell(player, 10156, false);
				else if(level >= 28)
                    player->CastSpell(player, 1461, false);
				else if(level >= 14)
                    player->CastSpell(player, 1460, false);
                else if(level >= 1)
                    player->CastSpell(player, 1459, false);
				break;
            case 2004:
				if(level >= 60)
                    player->CastSpell(player, 25898, false);
				else if(level >= 20) 
                    player->CastSpell(player, 20217, false);
                else if(level < 20)
                {
                    creature->MonsterWhisper("Der Segen der Könige, ist erst ab Level 20 erhältlich.", LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
                }
                break;
            case 2005:
				if(player->getLevel() >= 79)
                    player->CastSpell(player, 48934, false);
				else if(player->getLevel() >= 73)
                    player->CastSpell(player, 48933, false);
				else if(player->getLevel() >= 70)
                    player->CastSpell(player, 27141, false);
				else if(player->getLevel() >= 60)
                    player->CastSpell(player, 25916, false);
				else if(player->getLevel() >= 52)
                    player->CastSpell(player, 25782, false);
				else if(player->getLevel() >= 42)
                    player->CastSpell(player, 19837, false);
				else if(player->getLevel() >= 32)
                    player->CastSpell(player, 19836, false);
				else if(player->getLevel() >= 22)    
                    player->CastSpell(player, 19835, false);
				else if(player->getLevel() >= 12) 
                    player->CastSpell(player, 19834, false);
				else if(player->getLevel() >= 4) 
                    player->CastSpell(player, 19740, false);
				else if(player->getLevel() < 4)
                {
                    creature->MonsterWhisper("Der Segen der Macht, ist erst ab Level 4 erhältlich.", LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
                }
                break;
            case 2006:
				if(player->getLevel() >= 77) 
                    player->CastSpell(player, 48938, false); 
				else if(player->getLevel() >= 71)  
                    player->CastSpell(player, 48937, false); 
				else if(player->getLevel() >= 65)
                    player->CastSpell(player, 27143, false); 
				else if(player->getLevel() >= 60)
                    player->CastSpell(player, 25918, false); 
				else if(player->getLevel() >= 54)
                    player->CastSpell(player, 25894, false); 
				else if(player->getLevel() >= 44)
                    player->CastSpell(player, 19853, false); 
				else if(player->getLevel() >= 34)
                    player->CastSpell(player, 19852, false); 
				else if(player->getLevel() >= 24)
                    player->CastSpell(player, 19850, false); 
				else if(player->getLevel() >= 14) 
                    player->CastSpell(player, 19742, false);    
                else if(player->getLevel() < 14)
                {
                    creature->MonsterWhisper("Der Segen der Weisheit, ist erst ab Level 14 erhältlich.", LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
                }
                break;
            case 2007:
				if(level >= 60)
					player->CastSpell(player, 25899, false); 
				else
				{
					creature->MonsterWhisper("Der Segen des Refugiums, ist erst ab Level 60 erhältlich.", LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
				}
                break;
            case 2008:
				if(level >= 20)
					player->CastSpell(player, 6346, false);  
				else
				{
					creature->MonsterWhisper("Der Furchtzauberschutz, ist erst ab Level 20 erhältlich.", LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
				}
                break;
            case 2009:
				if(player->getLevel() >= 80)
                    player->CastSpell(player, 48161, false); 
				else if(player->getLevel() >= 70)
                    player->CastSpell(player, 25389, false); 
				else if(player->getLevel() >= 60)
                    player->CastSpell(player, 10938, false); 
				else if(player->getLevel() >= 48)
                    player->CastSpell(player, 10937, false); 
				else if(player->getLevel() >= 36)
                    player->CastSpell(player, 2791, false); 
				else if(player->getLevel() >= 24)
                    player->CastSpell(player, 1245, false); 
				else if(player->getLevel() >= 12)
                    player->CastSpell(player, 1244, false); 
                else if(player->getLevel() >= 1)
                    player->CastSpell(player, 1243, false);  
                break;
            case 2010:
				if(player->getLevel() >= 80)
                    player->CastSpell(player, 48073, false);
				else if(player->getLevel() >= 70)
                    player->CastSpell(player, 25312, false);
				else if(player->getLevel() >= 60)
                    player->CastSpell(player, 27841, false);
				else if(player->getLevel() >= 50)
                    player->CastSpell(player, 14819, false);
				else if(player->getLevel() >= 40)
                    player->CastSpell(player, 14818, false);
				else if(player->getLevel() >= 30)
                    player->CastSpell(player, 14752, false); 
                if(player->getLevel() < 30)
                {
                    creature->MonsterWhisper("Der Göttliche Wille, ist erst ab Level 30 erhältlich.", LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
                }
                break;
            case 2011:
				if(player->getLevel() >= 76)
                    player->CastSpell(player, 48169, false); 
				else if(player->getLevel() >= 68)
                    player->CastSpell(player, 25433, false); 
				else if(player->getLevel() >= 56)
                    player->CastSpell(player, 10958, false); 
				else if(player->getLevel() >= 42)
                    player->CastSpell(player, 10957, false); 
				else if(player->getLevel() >= 30)
                    player->CastSpell(player, 976, false); 
                else if(player->getLevel() < 30)
                {
                    creature->MonsterWhisper("Der Schattenschutz, ist erst ab Level 30 erhältlich.", LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
                }
                break;
            case 2012:
				if(player->getLevel() >= 74)
                    player->CastSpell(player, 53307, false);
				else if(player->getLevel() >= 64)
                    player->CastSpell(player, 26992, false);
				else if(player->getLevel() >= 44)
                    player->CastSpell(player, 9756, false);
				else if(player->getLevel() >= 34)
                    player->CastSpell(player, 8914, false);
				else if(player->getLevel() >= 24)
                    player->CastSpell(player, 1075, false);
				else if(player->getLevel() >= 14) 
                    player->CastSpell(player, 782, false); 
				else if(player->getLevel() >= 6)   
                    player->CastSpell(player, 467, false);
                else if(player->getLevel() < 6)
                {
                    creature->MonsterWhisper("Die Dornen, sind erst ab Level 6 erhältlich.", LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
                }
                break;
            case 2013:
				if(level >= 65)
					player->CastSpell(player, 57330, false);
				else
				{
					creature->MonsterWhisper("Das Horn des Winters, ist erst ab Level 65 erhältlich.", LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
				}
                break;
            case 2014:
				if(player->getLevel() >= 60)
                    player->CastSpell(player, 20765, false); 
				else if(player->getLevel() >= 50)
                    player->CastSpell(player, 20764, false); 
				else if(player->getLevel() >= 40)
                    player->CastSpell(player, 20763, false); 
				else if(player->getLevel() >= 30)
                    player->CastSpell(player, 20762, false); 
				else if(player->getLevel() >= 18)
                    player->CastSpell(player, 20707, false); 
                else if(player->getLevel() < 18)
                {
                    creature->MonsterWhisper("Die Seelensteinauferstehung ist erst ab Level 18 erhältlich.", LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
                }
                break;
            case 2015:
				if(level >= 75)
					player->CastSpell(player, 54212, false); 
				else
				{
					creature->MonsterWhisper("Das Fläschchen des reinen Mojo kann erst ab Level 75 benutzt werden!", LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
                }
                break;
            case 2016:
				if(level >= 75)
					player->CastSpell(player, 53758, false); 
				else
				{
					creature->MonsterWhisper("Das Fläschchen des Steinbluts kann erst ab Level 75 benutzt werden!", LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
				}
                break;
            case 2017:
				if(level >= 75)
					player->CastSpell(player, 53755, false); 
				else
				{
					creature->MonsterWhisper("Das Fläschchen des Frostwyrms kann erst ab Level 75 benutzt werden!", LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
				}
                break;
            case 2018:
				if(level >= 75)
					player->CastSpell(player, 53760, false); 
				else
				{
					creature->MonsterWhisper("Das Fläschchen der endlosen Wut kann erst ab Level 75 benutzt werden!", LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
				}
                break;
            case 2019:
				if(level >= 15)
					player->CastSpell(player, 67019, false); 
				else
				{
					creature->MonsterWhisper("Das Fläschchen des Nordens kann erst ab Level 15 benutzt werden!", LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
				}
                break;
            case 9500:
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0,-8833.38f,628.628f,94.0066f,1.06535f);
                break;
            case 9501:
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0,-4918.88f,-940.406f,501.564f,5.42347f);
                break;
            case 9502:
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1,9921.22f,2346.78f,1330.78f,6.12055f);
                break;
             case 9503:
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530,-3965.7f,-11653.6f,-138.844f,0.852154f);
                break;
            case 8500:
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1,1629.36f,-4373.39f,31.2564f,3.54839f);
                break;
            case 8501:
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530,9487.69f,-7279.2f,14.2866f,6.16478f);
                break;
            case 8502:
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1,-1277.37f,124.804f,131.287f,5.22274f);
                break;
            case 8503:
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0,1584.07f,241.987f,-52.1534f,0.049647f);
                break;
            case 9750:
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530,-1838.16f,5301.79f,-12.428f,5.9517f);
                break; 
            case 9751:
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571,5804.15f,624.771f,647.767f,1.64f);
                break;
            case 9900:
                player->CLOSE_GOSSIP_MENU();
				player->TeleportTo(0,-7486.84f,1339.62f,131.407f,4.76584f);
				break;
            case 9901:
                player->CLOSE_GOSSIP_MENU();
				player->TeleportTo(1,4618.59f,-2098.11f,1236.97f,1.77864f);
				break;
            case 9902:
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0,-8528.88f,-1571.4f,637.706f,0.303512f);
                break;
            case 9903:
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0,-8636.42f,585.335f,95.6902f,2.19344f);
                break;                    
            default:
                break;
        }
        return true;
    }
};

void AddSC_npc_vip()
{
    new npc_vip;
}