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
#include "ScriptedCreature.h"
#include "gundrak.h"

enum Spells
{
    SPELL_ECK_BERSERK                             = 55816,
    SPELL_ECK_BITE                                = 55813,
    SPELL_ECK_SPIT                                = 55814,
    SPELL_ECK_SPRING_1                            = 55815,
    SPELL_ECK_SPRING_2                            = 55837
};

static Position EckSpawnPoint = { 1643.877930f, 936.278015f, 107.204948f, 0.668432f };

class boss_eck : public CreatureScript
{
public:
    boss_eck() : CreatureScript("boss_eck") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_eckAI (creature);
    }

    struct boss_eckAI : public ScriptedAI
    {
        boss_eckAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 uiBerserkTimer;
        uint32 uiBiteTimer;
        uint32 uiSpitTimer;
        uint32 uiSpringTimer;

        bool bBerserk;

        InstanceScript* instance;

        void Reset()
        {
            uiBerserkTimer = urand(60*IN_MILLISECONDS, 90*IN_MILLISECONDS); //60-90 secs according to wowwiki
            uiBiteTimer = 5*IN_MILLISECONDS;
            uiSpitTimer = 10*IN_MILLISECONDS;
            uiSpringTimer = 8*IN_MILLISECONDS;

            bBerserk = false;

            if (instance)
                instance->SetData(DATA_ECK_THE_FEROCIOUS_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (instance)
                instance->SetData(DATA_ECK_THE_FEROCIOUS_EVENT, IN_PROGRESS);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiBiteTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_ECK_BITE);
                uiBiteTimer = urand(8*IN_MILLISECONDS, 12*IN_MILLISECONDS);
            } else uiBiteTimer -= diff;

            if (uiSpitTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_ECK_SPIT);
                uiSpitTimer = urand(6*IN_MILLISECONDS, 14*IN_MILLISECONDS);
            } else uiSpitTimer -= diff;

            if (uiSpringTimer <= diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1);
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                {
                    DoCast(target, RAND(SPELL_ECK_SPRING_1, SPELL_ECK_SPRING_2));
                    uiSpringTimer = urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS);
                }
            } else uiSpringTimer -= diff;

            if (!bBerserk)
            {
                if (uiBerserkTimer <= diff)
                {
                    DoCast(me, SPELL_ECK_BERSERK);
                    bBerserk = true;
                }
                else
                {
                    uiBerserkTimer -= diff;
                    if (HealthBelowPct(20))
                    {
                        DoCast(me, SPELL_ECK_BERSERK);
                        bBerserk = true;
                    }
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
                instance->SetData(DATA_ECK_THE_FEROCIOUS_EVENT, DONE);
        }
    };

};

class npc_ruins_dweller : public CreatureScript
{
public:
    npc_ruins_dweller() : CreatureScript("npc_ruins_dweller") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ruins_dwellerAI (creature);
    }

    struct npc_ruins_dwellerAI : public ScriptedAI
    {
        npc_ruins_dwellerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
            {
                instance->SetData64(DATA_RUIN_DWELLER_DIED, me->GetGUID());
                if (instance->GetData(DATA_ALIVE_RUIN_DWELLERS) == 0)
                    me->SummonCreature(CREATURE_ECK, EckSpawnPoint, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300*IN_MILLISECONDS);
            }
        }
    };

};

void AddSC_boss_eck()
{
    new boss_eck();
    new npc_ruins_dweller();
}
