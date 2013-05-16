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
#include "verlies_neu.h"

enum Spells
{
    SPELL_WELLE      = 51820,
    SPELL_FEUERREGEN = 57757,
    SPELL_FROSTBLITZ = 61594,
    SPELL_ARMEE      = 67761,
    SPELL_METEOR     = 28884,
    SPELL_BERSERK    = 41305,
};

enum Yells
{
    YELL_START    = 0,
    YELL_KILLED   = 1,
    YELL_DIED     = 2,
    YELL_SPELL_1  = 3,
    YELL_SPELL_2  = 4,
    YELL_SPELL_3  = 5,
    YELL_SPELL_4  = 6,
    YELL_BESERK   = 7,
};

enum Events
{
    EVENT_SPELL_1,
    EVENT_SPELL_2,
    EVENT_SPELL_3,
    EVENT_SPELL_4,
    EVENT_SPELL_5,
};

class boss_abbadon : public CreatureScript
{
	public:
		boss_abbadon() : CreatureScript("boss_abbadon") { }
        
        struct boss_abbadonAI : public BossAI
        {
            boss_abbadonAI(Creature* creature) : BossAI(creature, DATA_ABBADON){}
        
            void reset()
            {
            }
            
            void EnterCombat(Unit* /*who*/)
            {
                Talk(YELL_START);
                DoCast(SPELL_ARMEE);
                events.ScheduleEvent(EVENT_SPELL_1, 10000);
                events.ScheduleEvent(EVENT_SPELL_2, 25000);
                events.ScheduleEvent(EVENT_SPELL_3, 35000);
                events.ScheduleEvent(EVENT_SPELL_4, 45000);
                events.ScheduleEvent(EVENT_SPELL_5, 60000);
            }
            
            void JustDied(Unit* /*killer*/)
            {
                Talk(YELL_DIED);
                instance->SetBossState(DATA_ABBADON, DONE);
            }
            
            void KilledUnit(Unit* victim)
            {
                Talk(YELL_KILLED);
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
                        case EVENT_SPELL_1:
                            Talk(YELL_SPELL_1);
                            DoCast(me, SPELL_WELLE);
                            DoCast(me, SPELL_WELLE);
                            DoCast(me, SPELL_WELLE);
                            DoCast(me, SPELL_WELLE);
                            events.ScheduleEvent(EVENT_SPELL_1, 10000);
                            break;
                        case EVENT_SPELL_2:
                            Talk(YELL_SPELL_2);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_FEUERREGEN);
                            events.ScheduleEvent(EVENT_SPELL_2, 25000);
                            break;
                        case EVENT_SPELL_3:
                            Talk(YELL_SPELL_3);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_FROSTBLITZ);
                            events.ScheduleEvent(EVENT_SPELL_3, 35000);
                            break;
                        case EVENT_SPELL_4:
                            Talk(YELL_SPELL_4);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_METEOR);
                            events.ScheduleEvent(EVENT_SPELL_4, 45000);
                            break;
                        case EVENT_SPELL_5:
                            Talk(YELL_SPELL_4);
                            DoCast(me, SPELL_BERSERK);
                            events.ScheduleEvent(EVENT_SPELL_5, 60000);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
        
        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_abbadonAI(creature);
        }                            
};              

void AddSC_boss_abbadon()
{
    new boss_abbadon();
}