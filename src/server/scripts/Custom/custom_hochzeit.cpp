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

enum Spells
{
	SPELL_WAHRE_LIEBE  = 44460,
	SPELL_LIEBESRAKETE = 45153,
};

enum Objects
{
	OBJECT_FLAMME_DER_LIEBE  = 500000,
	OBJECT_FEUERWERK         = 191790,
};

enum Npcs
{
    NPC_FIREWORK_TRIGGER = 65009,
};

enum Text
{
	SAY1 = 12008,
	SAY2 = 12009,
	SAY3 = 12010,
	SAY4 = 12011,
	SAY5 = 12012,
	SAY6 = 12013,
	SAY7 = 12014,
	SAY8 = 12015,
};

class custom_hochzeit_npc : public CreatureScript
{
    public:
        custom_hochzeit_npc() : CreatureScript("custom_hochzeit_npc") { }
        
        bool OnGossipHello(Player* player, Creature* creature)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Was genau muessen wir machen?", GOSSIP_SENDER_MAIN, 5600);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Wir haben alles, wie du es uns gesagt hast!", GOSSIP_SENDER_MAIN, 5601);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Die Frau will!", GOSSIP_SENDER_MAIN, 5602);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Der Mann will!", GOSSIP_SENDER_MAIN, 5603);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Entzündet die Flammen der Liebe!", GOSSIP_SENDER_MAIN, 5604);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Lebt wohl!", GOSSIP_SENDER_MAIN, 5605);
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
            return true;
        }
        
        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            
            switch(action)
            {
                case 5600:
                    creature->MonsterWhisper("Ihr braucht zwei Ringe und natürlich die angemessene Kleidung für diesen Anlass. Ihr solltet alles was Ihr braucht bei meinem Lehrlich finden. Der sollte sich hier irgendwo herrumtreiben.", player->GetGUID());
                    creature->MonsterWhisper("Natürlich würden auch ein paar Freunde nicht Schaden, aber das ist natürlich kein muss.", player->GetGUID());
                    creature->MonsterWhisper("Wenn Ihr alles Habt könnt Ihr den zweiten Punkt anklicken und wir können mit der Zeremonie beginnen.", player->GetGUID());
                    player->CLOSE_GOSSIP_MENU();
                    break;
                case 5601:
					creature->Say(SAY1, LANG_UNIVERSAL, NULL);
					creature->Say(SAY2, LANG_UNIVERSAL, NULL);
					creature->Say(SAY3, LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
					break;
				case 5602:
					player->addSpell(SPELL_WAHRE_LIEBE, true, true, false, false, true);
					creature->Say(SAY4, LANG_UNIVERSAL, NULL);
					creature->Say(SAY5, LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
					break;
				case 5603:
					player->addSpell(SPELL_WAHRE_LIEBE, true, true, false, false, true);
					creature->Say(SAY6, LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
					break;
				case 5604:
					creature->SummonGameObject(OBJECT_FLAMME_DER_LIEBE, -8491.441406f, -1547.009033f, 635.898804f, 0, 0, 0, 0, 0, 120000);
					creature->SummonGameObject(OBJECT_FLAMME_DER_LIEBE, -8484.802734f, -1568.128906f, 635.893921f, 0, 0, 0, 0, 0, 120000);
					creature->Say(SAY7, LANG_UNIVERSAL, NULL);
                    player->CLOSE_GOSSIP_MENU();
					break;
				case 5605:
					creature->Say(SAY8, LANG_UNIVERSAL, NULL);
					creature->SummonGameObject(OBJECT_FEUERWERK, -8472.460938f, -1552.324463f, 635.004395f, 0, 0, 0, 0, 0, 120000);
					creature->SummonGameObject(OBJECT_FEUERWERK, -8468.510742f, -1564.503540f, 635.022461f, 0, 0, 0, 0, 0, 120000);
					creature->SummonGameObject(OBJECT_FEUERWERK, -8476.697266f, -1540.821655f, 635.020813f, 0, 0, 0, 0, 0, 120000);
					creature->SummonGameObject(OBJECT_FEUERWERK, -8512.757813f, -1553.657593f, 634.834290f, 0, 0, 0, 0, 0, 120000);
					creature->SummonGameObject(OBJECT_FEUERWERK, -8504.546875f, -1575.472534f, 634.897156f, 0, 0, 0, 0, 0, 120000);
					creature->SummonGameObject(OBJECT_FEUERWERK, -8550.034180f, -1578.708374f, 642.424438f, 0, 0, 0, 0, 0, 120000);
					creature->SummonCreature(NPC_FIREWORK_TRIGGER, -8472.460938f, -1552.324463f, 635.004395f, 0);
					creature->SummonCreature(NPC_FIREWORK_TRIGGER, -8468.510742f, -1564.503540f, 635.022461f, 0);
					creature->SummonCreature(NPC_FIREWORK_TRIGGER, -8476.697266f, -1540.821655f, 635.020813f, 0);
					creature->SummonCreature(NPC_FIREWORK_TRIGGER, -8512.757813f, -1553.657593f, 634.834290f, 0);
					creature->SummonCreature(NPC_FIREWORK_TRIGGER, -8504.546875f, -1575.472534f, 634.897156f, 0);
					creature->SummonCreature(NPC_FIREWORK_TRIGGER, -8550.034180f, -1578.708374f, 642.424438f, 0);
                    player->CLOSE_GOSSIP_MENU();
					break;
				default:
					break;
			}
			return true;
		}
};

class custom_hochzeit_npc_trigger : public CreatureScript
{
	public:
		custom_hochzeit_npc_trigger() : CreatureScript("custom_hochzeit_npc_trigger") { }

		void JustSummoned(Creature* summoned)
		{
			summoned->CastSpell(summoned, SPELL_LIEBESRAKETE, false, NULL, NULL, true);
		}
};

void AddSC_custom_hochzeit_npc()
{
	new custom_hochzeit_npc();
	new custom_hochzeit_npc_trigger();
}