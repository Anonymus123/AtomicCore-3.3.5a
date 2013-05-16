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
#include "verlies_neu.h"

enum Yells
{
    YELL_START               = 0,
    YELL_1                   = 1,
    YELL_2                   = 2,
    YELL_3                   = 3,
    YELL_JUST_DIED           = 4,
    YELL_BESERK              = 5,
};

enum Events
{
    EVENT_PHASE_1            = 1,
    EVENT_PHASE_2            = 2,
    EVENT_PHASE_3            = 3,
    EVENT_ENRAGE             = 4,
};

enum Spells
{
    SPELL_SUMMON_MAGE        = 49105,
    SPELL_SCHATTENBLITZSALVE = 14297,
    SPELL_SEELENSAUER        = 41303,
    SPELL_AURA_DES_LEIDENS   = 41292,
    SPELL_BESERK             = 41305,
};

class boss_hauptmann_lanzrath : public CreatureScript
{
    public:
        boss_hauptmann_lanzrath() : CreatureScript("boss_hauptmann_lanzrath") { }
        
        struct boss_hauptmann_lanzrathAI : public BossAI
        {
            boss_hauptmann_lanzrathAI(Creature* creature) : BossAI(creature, DATA_HAUPTMANN_LANZRATH){}
        
            void reset()
            {
            }
            
            void EnterCombat(Unit* /*who*/)
            {
                Talk(YELL_START);
                DoCast(me, SPELL_SUMMON_MAGE, true);
                DoCast(me, SPELL_SUMMON_MAGE, true);
                events.ScheduleEvent(EVENT_PHASE_1, 10000);
                events.ScheduleEvent(EVENT_PHASE_2, 25000);
                events.ScheduleEvent(EVENT_PHASE_3, 35000);
                events.ScheduleEvent(EVENT_ENRAGE, 60000);
            }
            
            void JustDied(Unit* /*killer*/)
            {
                Talk(YELL_JUST_DIED);
                instance->SetBossState(DATA_HAUPTMANN_LANZRATH, DONE);
            }
            
            void KilledUnit(Unit* victim)
            {
            }
            
            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;
                    
                events.Update(diff);
                
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
                    
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PHASE_1:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_SCHATTENBLITZSALVE);
                            Talk(YELL_1);
                            events.ScheduleEvent(EVENT_PHASE_1, 10000);
                            break;
                        case EVENT_PHASE_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_SEELENSAUER);
                            Talk(YELL_2);
                            events.ScheduleEvent(EVENT_PHASE_2, 25000);
                            break;
						case EVENT_PHASE_3:
                            DoCast(SPELL_AURA_DES_LEIDENS);
                            Talk(YELL_3);
                            events.ScheduleEvent(EVENT_PHASE_3, 35000);
                            break;
                        case EVENT_ENRAGE:
                            DoCast(me, SPELL_BESERK);
                            Talk(YELL_BESERK);
                            events.ScheduleEvent(EVENT_ENRAGE, 60000);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
        
        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_hauptmann_lanzrathAI(creature);
        }
};

void AddSC_boss_hauptmann_lanzrath()
{
    new boss_hauptmann_lanzrath();
}