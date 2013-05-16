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

#include "ScriptMgr.h"
#include <cstring>
#include <stdio.h>
#include <time.h>

#define OFFSET_THEME 30000 

int GetLastThemeTime()
{
  	QueryResult result;
	  result = WorldDatabase.PQuery("SELECT `time` FROM `gurubashi_lastspawned`");

	  if (result)
	  {
	   Field *fields = result->Fetch();
	   return fields[0].GetInt32();
	  }
	  else 
		  return 0;

}

void GossipObjects(Player *player, Creature *m_creature)
{
   if (GetLastThemeTime() + 600 <= time (NULL))
    {
        QueryResult result;
    	  result = WorldDatabase.PQuery("SELECT `id`, `name` FROM `gurubashi_themes`");
        if (result)
        {
        	do
          {
          	Field *fields = result->Fetch();
          	player->ADD_GOSSIP_ITEM(4, fields[1].GetString(), GOSSIP_SENDER_MAIN, OFFSET_THEME + fields[0].GetInt32());
          }
          while (result->NextRow());
        }
    }
    else
    {
        char msg[100];
      	int time2 = GetLastThemeTime() + 600 - time (NULL);
      	if (time2 < 60)
          sprintf(msg, "Nächster Wechsel in weniger als einer Minute möglich!");
        else
          sprintf(msg, "Nächster Wechsel in %u Minute/n möglich!", time2 / 60);		  
          player->ADD_GOSSIP_ITEM(0, msg, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    }
    player->ADD_GOSSIP_ITEM(0, "Auf Wiedersehen!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->SEND_GOSSIP_MENU(1,m_creature->GetGUID());
}


class Theme_NPC : public CreatureScript
{
	public:
		Theme_NPC() : CreatureScript("Theme_NPC") {}
		
		bool OnGossipHello(Player * pPlayer, Creature * pCreature)
        {
			GossipObjects(pPlayer, pCreature);
			return true;
		}
		
		bool OnGossipSelect(Player *player, Creature * m_creature, uint32 sender, uint32 action)
		{
			if (action > OFFSET_THEME)
			{
				QueryResult result;
				result = WorldDatabase.PQuery("DELETE FROM `gurubashi_lastspawned`");
				result = WorldDatabase.PQuery("INSERT INTO `gurubashi_lastspawned` VALUES (%u)", time (NULL));
				result = WorldDatabase.PQuery("SELECT `x`, `y`, `z`, `o`, `entry` FROM `gurubashi_spawns` WHERE `theme` = %u", action - OFFSET_THEME);
				if (result)
				{
					m_creature->MonsterSay("Platziere GameObjects...", LANG_UNIVERSAL, player->GetGUID());
					do
					{
						Field *fields = result->Fetch();
						m_creature->SummonGameObject(fields[4].GetInt32(), fields[0].GetFloat(), fields[1].GetFloat(), fields[2].GetFloat(), fields[3].GetFloat(), 0, 0, 0, 0, 600); 
					}
					while (result->NextRow());
				}
				else
				{
					m_creature->MonsterSay("Keine GameObject gefunden!", LANG_UNIVERSAL, player->GetGUID());
				}
				player->PlayerTalkClass->SendCloseGossip();
			}
			else
			{
				switch (action)
				{
				case GOSSIP_ACTION_INFO_DEF + 1:
					player->PlayerTalkClass->SendCloseGossip();
					break;
				case GOSSIP_ACTION_INFO_DEF + 2:
					GossipObjects(player, m_creature);
					break;
				}
			}
			return true;
		}
};


void AddSC_npc_gurubashi_theme()
{
	new Theme_NPC();
}