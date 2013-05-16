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

enum NPCs
{
	NPC_DALARAN_SQUIRREL = 666666,
	NPC_DALARAN_SQUIRREL_SUMMON = 666667,
};

class npc_dalaran_squirrel : public CreatureScript
{
public:
    npc_dalaran_squirrel() : CreatureScript("npc_dalaran_squirrel") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_dalaran_squirrelAI (creature);
    }

    struct npc_dalaran_squirrelAI : public ScriptedAI
    {
		npc_dalaran_squirrelAI(Creature* c) : ScriptedAI(c), summons(c) {}

		Unit* attacker;
		SummonList summons;

		void Reset()
        {
			summons.DespawnAll();
		}

		void EnterCombat(Unit* /*who*/)
        {
			me->MonsterSay("Das hätte ich an eurer Stelle nicht getan...", LANG_UNIVERSAL, 0);
			for(int i = 0; i < 19; i++)
			{
				me->SummonCreature(NPC_DALARAN_SQUIRREL_SUMMON, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
			}
		}

		void JustDied(Unit* /*victim*/)
        {
			me->Respawn();				
			me->CombatStart(attacker);
		}
		
		void JustSummoned(Creature* summon)
            {
				summons.Summon(summon);
				if(Unit* target = me->getVictim())
				{
					if(target->isTotem() || target ->isPet())
					{
						target = target->GetOwner();
					}
					summon->AI()->AttackStart(target);
				}
			}

		 void UpdateAI(const uint32 diff)
        {
			if (!UpdateVictim())
				return;
			
			if(Unit* target = me->getVictim())
			{
				if(target->isTotem() || target->isPet())
				{
					target = target->GetOwner();
				}
				attacker = target;
				DoMeleeAttackIfReady();
			}
		}
	};
};

void AddSC_dalaran_squirrel()
{
	new npc_dalaran_squirrel();
}