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
#include "ahnkahet.h"

enum Spells
{
    SPELL_BASH                                    = 57094,
    SPELL_ENTANGLING_ROOTS                        = 57095,
    SPELL_MINI                                    = 57055,
    SPELL_VENOM_BOLT_VOLLEY                       = 57088,
    SPELL_HEALTHY_MUSHROOM_POTENT_FUNGUS          = 56648,
    SPELL_POISONOUS_MUSHROOM_POISON_CLOUD         = 57061,
    SPELL_POISONOUS_MUSHROOM_VISUAL_AREA          = 61566,
    SPELL_POISONOUS_MUSHROOM_VISUAL_AURA          = 56741,
    SPELL_PUTRID_MUSHROOM                         = 31690,
};

enum Creatures
{
    NPC_HEALTHY_MUSHROOM                          = 30391,
    NPC_POISONOUS_MUSHROOM                        = 30435
};

class boss_amanitar : public CreatureScript
{
public:
    boss_amanitar() : CreatureScript("boss_amanitar") { }

    struct boss_amanitarAI : public ScriptedAI
    {
        boss_amanitarAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            bFirstTime = true;
        }

        InstanceScript* instance;

        uint32 uiRootTimer;
        uint32 uiBashTimer;
        uint32 uiBoltTimer;
        uint32 uiSpawnTimer;

        bool bFirstTime;

        void Reset()
        {
            uiRootTimer = urand(5*IN_MILLISECONDS, 9*IN_MILLISECONDS);
            uiBashTimer = urand(10*IN_MILLISECONDS, 14*IN_MILLISECONDS);
            uiBoltTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
            uiSpawnTimer = 0;

            me->SetMeleeDamageSchool(SPELL_SCHOOL_NATURE);
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);

            if (instance)
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MINI);
                if (!bFirstTime)
                    instance->SetData(DATA_AMANITAR_EVENT, FAIL);
                else
                    bFirstTime = false;
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
            {
                instance->SetData(DATA_AMANITAR_EVENT, DONE);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MINI);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (instance)
                instance->SetData(DATA_AMANITAR_EVENT, IN_PROGRESS);

            DoCast(me, SPELL_MINI, false);
        }

        void SpawnAdds()
        {
            for (uint8 i = 0; i < 30; ++i)
            {
                Unit* victim = SelectTarget(SELECT_TARGET_RANDOM, 0);

                if (victim)
                {
                    Position pos;
                    victim->GetPosition(&pos);
                    me->GetRandomNearPosition(pos, float(urand(5, 80)));
                    me->SummonCreature(NPC_POISONOUS_MUSHROOM, pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30*IN_MILLISECONDS);
                    me->GetRandomNearPosition(pos, float(urand(5, 80)));
                    me->SummonCreature(NPC_HEALTHY_MUSHROOM, pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30*IN_MILLISECONDS);
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiSpawnTimer <= diff)
            {
                SpawnAdds();
                uiSpawnTimer = urand(35*IN_MILLISECONDS, 40*IN_MILLISECONDS);
            } else uiSpawnTimer -= diff;

            if (uiRootTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_ENTANGLING_ROOTS);
                uiRootTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
            } else uiRootTimer -= diff;

            if (uiBashTimer <= diff)
            {
                DoCastVictim(SPELL_BASH);
                uiBashTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
            } else uiBashTimer -= diff;

            if (uiBoltTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_VENOM_BOLT_VOLLEY);
                uiBoltTimer = urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS);
            } else uiBoltTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_amanitarAI(creature);
    }
};

class mob_amanitar_mushrooms : public CreatureScript
{
public:
    mob_amanitar_mushrooms() : CreatureScript("mob_amanitar_mushrooms") { }

    struct mob_amanitar_mushroomsAI : public Scripted_NoMovementAI
    {
        mob_amanitar_mushroomsAI(Creature* creature) : Scripted_NoMovementAI(creature) {}

        uint32 uiAuraTimer;
        uint32 uiDeathTimer;

        void Reset()
        {
            DoCast(me, SPELL_PUTRID_MUSHROOM, true);

            if (me->GetEntry() == NPC_POISONOUS_MUSHROOM)
                DoCast(me, SPELL_POISONOUS_MUSHROOM_VISUAL_AURA, true);

            uiAuraTimer = 0;
            uiDeathTimer = 30*IN_MILLISECONDS;
        }

        void JustDied(Unit* killer)
        {
            if (!killer)
                return;

            if (me->GetEntry() == NPC_HEALTHY_MUSHROOM && killer->GetTypeId() == TYPEID_PLAYER)
            {
                me->InterruptNonMeleeSpells(false);
                DoCast(killer, SPELL_HEALTHY_MUSHROOM_POTENT_FUNGUS, false);
            }
        }

        void EnterCombat(Unit* /*who*/) {}
        void AttackStart(Unit* /*victim*/) {}

        void UpdateAI(const uint32 diff)
        {
            if (me->GetEntry() == NPC_POISONOUS_MUSHROOM)
            {
                if (uiAuraTimer <= diff)
                {
                    DoCast(me, SPELL_POISONOUS_MUSHROOM_VISUAL_AREA, true);
                    DoCast(me, SPELL_POISONOUS_MUSHROOM_POISON_CLOUD, false);
                    uiAuraTimer = 7*IN_MILLISECONDS;
                } else uiAuraTimer -= diff;
            }
            if (uiDeathTimer <= diff)
                me->DisappearAndDie();
            else uiDeathTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_amanitar_mushroomsAI(creature);
    }
};

void AddSC_boss_amanitar()
{
    new boss_amanitar;
    new mob_amanitar_mushrooms;
}
