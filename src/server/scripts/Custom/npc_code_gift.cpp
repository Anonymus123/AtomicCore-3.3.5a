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
#include <cstring>

#define C_GOSSIP_MENU 907
#define D_ENTER_CODE "Ich habe einen Code!"
#define D_CANCEL_CODE "Zurueck..."
#define SAY_INV_FULL "Inventar ist voll!"
#define SAY_EXPIRED "Es tut mir Leid, aber dein Code ist abgelaufen."
#define SAY_INVALID "Der angegebene Code ist nicht gültig!"
#define SAY_GIVE_PRESENT "Das ist für dich! Ich hoffe es gefällt dir."
#define SAY_EXTRA_BUFF "Du hast ein Item und einen Buff erhalten."
#define SAY_GIVE_BUFF "Ein spezieller Buff nur für dich!"
#define SAY_GOODBYE "Bye!"

class npc_codebox : public CreatureScript
{
public:
	npc_codebox() : CreatureScript("npc_codebox") { }

	bool checkCode(Player *player, Creature *_Creature, const char* sCode)
	{
		int32 item_id = 0;
		int32 aura_id = 0;
		uint32 quantity = 0;
		int32 uses = 0;
		bool check = false;
		uint32 creatureID = _Creature->GetEntry();

		QueryResult result = WorldDatabase.PQuery("SELECT `item_id`, `aura_id`, `quantity`, `uses`  FROM `npc_codes` WHERE `code` = '%s' AND npc_id = %i LIMIT 1",sCode,creatureID);
		if(result)
		{
			check = true;
			Field *fields = result->Fetch();

			item_id = fields[0].GetInt32();
			aura_id = fields[1].GetInt32();
			quantity = fields[2].GetUInt32();
			uses = fields[3].GetUInt32();

			if(uses != 0)
			{
				if(item_id > 0)
				{
					ItemPosCountVec dest;
					uint8 canStoreNewItem = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, item_id, quantity);
					if(canStoreNewItem == EQUIP_ERR_OK)
					{
						Item *newItem = NULL;
						newItem = player->StoreNewItem(dest,item_id,quantity,true);
						player->SendNewItem(newItem,quantity,true,false);
					}
					else
					{
						_Creature->MonsterWhisper(SAY_INV_FULL, player->GetGUID());
						check = false;
					}
				}
				else if(item_id < 0)
				{
					uint32 id = item_id * -1;
					uint32 num;
					uint32 item;
					QueryResult items = WorldDatabase.PQuery("SELECT `item_id` FROM `npc_codes_item_loot` WHERE `group_id` = '%i'",id);
					if(items)
					{
						num = rand()%items->GetRowCount();
						Field *i;
						uint32 count = 0;
						do
						{
							i = items->Fetch();
							item = i[0].GetUInt32();
							++count;
						}while((count < num) && (items->NextRow()));
						ItemPosCountVec dest;
						uint8 canStoreNewItem = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, item, quantity);
						if(canStoreNewItem == EQUIP_ERR_OK)
						{
							Item *newItem = NULL;
							newItem = player->StoreNewItem(dest,item,quantity,true);
							player->SendNewItem(newItem,quantity,true,false);
						}
						else
						{
							_Creature->MonsterWhisper(SAY_INV_FULL, player->GetGUID());
							check = false;
						}
					}
				}
				if(aura_id > 0 && check == true)
				{
					_Creature->CastSpell(player, aura_id, true);
				}
				else if(aura_id < 0 && check == true)
				{
					uint32 id = aura_id * -1;
					uint32 num;
					uint32 aura;
					QueryResult auras = WorldDatabase.PQuery("SELECT `aura_id` FROM `npc_codes_aura_loot` WHERE `group_id` = '%i'",id);
					if(auras)
					{
						num = rand()%auras->GetRowCount();
						Field *a;
						uint32 count = 0;
						do
						{
							a = auras->Fetch();
							aura = a[0].GetUInt32();
							++count;
						}while((count < num) && (auras->NextRow()));
						_Creature->CastSpell(player, aura, true);
					}
				}
			}
			else
			{
				check = false;
				_Creature->MonsterWhisper(SAY_EXPIRED, player->GetGUID());
			}
		}
		else
		{
			check = false;
			_Creature->MonsterWhisper(SAY_INVALID, player->GetGUID());
		}


		if(check == true)
		{
			if(uses > 0)
			{
				WorldDatabase.PExecute("UPDATE `npc_codes` SET `uses` = (`uses` - 1) WHERE `code` = '%s' LIMIT 1",sCode);
			}
			if(item_id != 0 && aura_id == 0)
				_Creature->MonsterSay(SAY_GIVE_PRESENT, LANG_UNIVERSAL, NULL);
			if(item_id != 0 && aura_id != 0)
				_Creature->MonsterSay(SAY_EXTRA_BUFF, LANG_UNIVERSAL, NULL);
			if(item_id == 0 && aura_id != 0)
				_Creature->MonsterSay(SAY_GIVE_BUFF, LANG_UNIVERSAL, NULL);
		}
		return check;
	}

	bool GossipHello_npc_codebox(Player *player, Creature *_Creature)
	{
		int32 text_id = C_GOSSIP_MENU;
		uint32 creatureID = _Creature->GetEntry();

		QueryResult result = WorldDatabase.PQuery("SELECT `npc_text_id` FROM `npc_codes_text` WHERE npc_id = %i LIMIT 1",creatureID);
		if(result)
		{
			Field *fields = result->Fetch();
			text_id = fields[0].GetInt32();
		}

		player->ADD_GOSSIP_ITEM_EXTENDED(0, D_ENTER_CODE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1, "", 0, true);
		player->ADD_GOSSIP_ITEM(0, D_CANCEL_CODE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

		player->PlayerTalkClass->SendGossipMenu(text_id,_Creature->GetGUID());
		return true;
	}

	bool GossipSelect_npc_codebox(Player *player, Creature *_Creature, uint32 sender, uint32 action )
	{
		if(action == GOSSIP_ACTION_INFO_DEF+2)
		{
			_Creature->MonsterSay(SAY_GOODBYE, LANG_UNIVERSAL, NULL); 
			player->CLOSE_GOSSIP_MENU();
		}
		return true;
	}

	bool GossipSelectWithCode_npc_codebox( Player *player, Creature *_Creature, uint32 sender, uint32 action, const char* sCode )
	{
		if(sender == GOSSIP_SENDER_MAIN)
		{
			if(action == GOSSIP_ACTION_INFO_DEF+1)
			{
				checkCode(player, _Creature, sCode);
				player->CLOSE_GOSSIP_MENU();
				return true;
			}
		}
		return false;
	}
};

void AddSC_npc_codebox()
{
    new npc_codebox();
}