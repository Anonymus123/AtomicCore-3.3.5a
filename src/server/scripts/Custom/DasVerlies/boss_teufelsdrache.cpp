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

enum Spells
{
    SPELL_ATEM     = 74806,
    SPELL_SPALTEN  = 31345,
    SPELL_SCHWANZ  = 43352,
    SPELL_BERSERK  = 41305,
};

enum Yells
{
    YELL_START       = 0,
    YELL_DIED        = 1,
    YELL_UNIT_KILLED = 2,
    YELL_SPELL_1     = 3,
    YELL_SPELL_2     = 4,
    YELL_SPELL_3     = 5,
};

enum Events
{
    EVENT_ATEM,
    EVENT_SPALTEN,
    EVENT_SCHWANZ,
    EVENT_BESERK,
};

#include "ScriptMgr.h"
#include "verlies_neu.h"

class boss_teufelsdrache : public CreatureScript
{
	public:
		boss_teufelsdrache() : CreatureScript("boss_teufelsdrache") { }
        
        struct boss_teufelsdracheAI : public BossAI
        {
            boss_teufelsdracheAI(Creature* pCreature) : BossAI(pCreature, DATA_TEUFELSDRACHE) {}
            
            void reset()
            {
            }
            
            void EnterCombat(Unit* /*who*/)
            {
                Talk(YELL_START);
                events.ScheduleEvent(EVENT_ATEM, 7500);
                events.ScheduleEvent(EVENT_SPALTEN, 11000);
                events.ScheduleEvent(EVENT_SCHWANZ, 25000);
                events.ScheduleEvent(EVENT_BESERK, 60000);
            }
            
            void JustDied(Unit* /*killer*/)
            {
                Talk(YELL_DIED);
                instance->SetBossState(DATA_TEUFELSDRACHE, DONE);
            }
            
            void KilledUnit(Unit* victim)
            {
                Talk(YELL_UNIT_KILLED);
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
                        case EVENT_ATEM:
                            Talk(YELL_SPELL_1);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_ATEM);
                            events.ScheduleEvent(EVENT_ATEM, 7500);
                            break;
                        case EVENT_SPALTEN:
                            Talk(YELL_SPELL_2);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_SPALTEN);
                            events.ScheduleEvent(EVENT_SCHWANZ, 25000);
                            break;
                        case EVENT_SCHWANZ:
                            Talk(YELL_SPELL_2);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_SCHWANZ);
                            events.ScheduleEvent(EVENT_SCHWANZ, 25000);
                            break;
                        case EVENT_BESERK:
                            Talk(YELL_SPELL_3);
                            DoCast(me, SPELL_BERSERK);
                            events.ScheduleEvent(EVENT_BESERK, 60000);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
        
        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_teufelsdracheAI(creature);
        }
};

void AddSC_boss_teufelsdrache()
{
    new boss_teufelsdrache();
}