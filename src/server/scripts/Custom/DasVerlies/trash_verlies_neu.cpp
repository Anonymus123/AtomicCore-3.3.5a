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

/*******************/
/*  Magier Daemon  */
/*******************/

class npc_magierdaemon : public CreatureScript
{
    public:
        npc_magierdaemon() : CreatureScript("npc_magierdaemon") { }
        
        struct npc_magierdaemonAI : public ScriptedAI
        {
            npc_magierdaemonAI(Creature* pCreature) : ScriptedAI(pCreature) {}
            
            void reset()
            {
            }
            
            void EnterCombat(Unit* /*who*/)
            {
            }
            
            void JustDied(Unit* /*killer*/)
            {
            }
            
            void KilledUnit(Unit* victim)
            {
            }
            
            void UpdateAI(uint32 const diff)
            {
//                if (!UpdateVictim() || !CheckInRoom())
//                    return;
//                    
//                events.Update(diff);
//                
//                if (me->HasUnitState(UNIT_STATE_CASTING))
//                    return;
//                    
//                while (uint32 eventId = events.ExecuteEvent())
//                {
//                    switch (eventId)
//                    {
//                    }
//                }
                DoMeleeAttackIfReady();
            }
        };
        
        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_magierdaemonAI(creature);
        }
};

/********************/
/*  Krieger Daemon  */
/********************/

class npc_kriegerdaemon : public CreatureScript
{
    public:
        npc_kriegerdaemon() : CreatureScript("npc_kriegerdaemon") { }
        
        struct npc_kriegerdaemonAI : public ScriptedAI
        {
            npc_kriegerdaemonAI(Creature* pCreature) : ScriptedAI(pCreature) {}
            
            void reset()
            {
            }
            
            void EnterCombat(Unit* /*who*/)
            {
            }
            
            void JustDied(Unit* /*killer*/)
            {
            }
            
            void KilledUnit(Unit* victim)
            {
            }
            
            void UpdateAI(uint32 const diff)
            {
//                if (!UpdateVictim() || !CheckInRoom())
//                    return;
//                    
//                events.Update(diff);
//                
//                if (me->HasUnitState(UNIT_STATE_CASTING))
//                    return;
//                    
//                while (uint32 eventId = events.ExecuteEvent())
//                {
//                    switch (eventId)
//                    {
//                    }
//                }
                DoMeleeAttackIfReady();
            }
        };
        
        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_kriegerdaemonAI(creature);
        }
};

/********************/
/*  Paladin Daemon  */
/********************/

class npc_paladindaemon : public CreatureScript
{
    public:
        npc_paladindaemon() : CreatureScript("npc_paladindaemon") { }
        
        struct npc_paladindaemonAI : public ScriptedAI
        {
            npc_paladindaemonAI(Creature* pCreature) : ScriptedAI(pCreature) {}
            
            void reset()
            {
            }
            
            void EnterCombat(Unit* /*who*/)
            {
            }
            
            void JustDied(Unit* /*killer*/)
            {
            }
            
            void KilledUnit(Unit* victim)
            {
            }
            
            void UpdateAI(uint32 const diff)
            {
//                if (!UpdateVictim() || !CheckInRoom())
//                    return;
//                    
//                events.Update(diff);
//                
//                if (me->HasUnitState(UNIT_STATE_CASTING))
//                    return;
//                    
//                while (uint32 eventId = events.ExecuteEvent())
//                {
//                    switch (eventId)
//                    {
//                    }
//                }
                DoMeleeAttackIfReady();
            }
        };
        
        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_paladindaemonAI(creature);
        }
};

/******************************/
/*  Zerfleischter Gefangener  */
/******************************/

//class npc_zerfleischtergefangener : public CreatureScript
//{
//    public:
//        npc_zerfleischtergefangener() : CreatureScript("npc_zerfleischtergefangener") { }
//        
//        struct npc_zerfleischtergefangenerAI : public ScriptedAI
//        {
//            npc_zerfleischtergefangenerAI(Creature* pCreature) : ScriptedAI(pCreature) {}
//            
//            void reset()
//            {
//            }
//            
//            void EnterCombat(Unit* /*who*/)
//            {
//            }
//            
//            void JustDied(Unit* /*killer*/)
//            {
//            }
//            
//            void KilledUnit(Unit* victim)
//            {
//            }
//            
//            void UpdateAI(uint32 const diff)
//            {
//                if (!UpdateVictim() || !CheckInRoom())
//                    return;
//                    
//                events.Update(diff);
//                
//                if (me->HasUnitState(UNIT_STATE_CASTING))
//                    return;
//                    
//                while (uint32 eventId = events.ExecuteEvent())
//                {
//                    switch (eventId)
//                    {
//                    }
//                }
//                DoMeleeAttackIfReady();
//            }
//       };
//        
//        CreatureAI* GetAI(Creature* creature) const
//        {
//            return new npc_zerfleischtergefangenerAI(creature);
//        }
//};         
            
/******************************/
/*   Verletzter Gefangener    */
/******************************/

//class npc_verletztergefangener : public CreatureScript
//{
//    public:
//        npc_verletztergefangener() : CreatureScript("npc_verletztergefangener") { }
//        
//        struct npc_verletztergefangenerAI : public ScriptedAI
//        {
//            npc_verletztergefangenerAI(Creature* pCreature) : ScriptedAI(pCreature) {}
//            
//            void reset()
//            {
//            }
//            
//            void EnterCombat(Unit* /*who*/)
//            {
//            }
//            
//            void JustDied(Unit* /*killer*/)
//            {
//            }
//            
//            void KilledUnit(Unit* victim)
//            {
//            }
//            
//            void UpdateAI(uint32 const diff)
//            {
//                if (!UpdateVictim() || !CheckInRoom())
//                    return;
//                    
//                events.Update(diff);
//                
//                if (me->HasUnitState(UNIT_STATE_CASTING))
//                    return;
//                    
//                while (uint32 eventId = events.ExecuteEvent())
//                {
//                    switch (eventId)
//                    {
//                    }
//                }
//                DoMeleeAttackIfReady();
//            }
//       };
//        
//        CreatureAI* GetAI(Creature* creature) const
//        {
//            return new npc_verletztergefangenerAI(creature);
//        }
//};   

/******************************/
/*    Mutierter Gefangener    */
/******************************/

//class npc_mutiertergefangener : public CreatureScript
//{
//    public:
//        npc_mutiertergefangener() : CreatureScript("npc_mutiertergefangener") { }
//        
//        struct npc_mutiertergefangenerAI : public ScriptedAI
//        {
//            npc_mutiertergefangenerAI(Creature* pCreature) : ScriptedAI(pCreature) {}
//            
//            void reset()
//            {
//            }
//            
//            void EnterCombat(Unit* /*who*/)
//            {
//            }
//            
//            void JustDied(Unit* /*killer*/)
//            {
//            }
//            
//            void KilledUnit(Unit* victim)
//            {
//            }
//            
//            void UpdateAI(uint32 const diff)
//            {
//                if (!UpdateVictim() || !CheckInRoom())
//                    return;
//                    
//                events.Update(diff);
//                
//                if (me->HasUnitState(UNIT_STATE_CASTING))
//                    return;
//                    
//                while (uint32 eventId = events.ExecuteEvent())
//                {
//                    switch (eventId)
//                    {
//                    }
//                }
//                DoMeleeAttackIfReady();
//            }
//       };
//        
//        CreatureAI* GetAI(Creature* creature) const
//        {
//            return new npc_mutiertergefangenerAI(creature);
//        }
//}; 

/******************************/
/*    Hilfloser Gefangener    */
/******************************/

//class npc_hilflosergefangener : public CreatureScript
//{
//    public:
//        npc_hilflosergefangener() : CreatureScript("npc_hilflosergefangener") { }
//        
//        struct npc_hilflosergefangenerAI : public ScriptedAI
//        {
//            npc_hilflosergefangenerAI(Creature* pCreature) : ScriptedAI(pCreature) {}
//            
//            void reset()
//            {
//            }
//            
//            void EnterCombat(Unit* /*who*/)
//            {
//            }
//            
//            void JustDied(Unit* /*killer*/)
//            {
//            }
//            
//            void KilledUnit(Unit* victim)
//            {
//            }
//            
//            void UpdateAI(uint32 const diff)
//            {
//                if (!UpdateVictim() || !CheckInRoom())
//                    return;
//                    
//                events.Update(diff);
//                
//                if (me->HasUnitState(UNIT_STATE_CASTING))
//                    return;
//                    
//                while (uint32 eventId = events.ExecuteEvent())
//                {
//                    switch (eventId)
//                    {
//                    }
//                }
//                DoMeleeAttackIfReady();
//            }
//       };
//        
//        CreatureAI* GetAI(Creature* creature) const
//        {
//            return new npc_hilflosergefangenerAI(creature);
//        }
//}; 

/******************************/
/*    Diener der Unterwelt    */
/******************************/

//class npc_diener_der_unterwelt : public CreatureScript
//{
//    public:
//        npc_diener_der_unterwelt() : CreatureScript("npc_diener_der_unterwelt") { }
//        
//        struct npc_diener_der_unterweltAI : public ScriptedAI
//        {
//            npc_diener_der_unterweltAI(Creature* pCreature) : ScriptedAI(pCreature) {}
//            
//            void reset()
//            {
//            }
//            
//            void EnterCombat(Unit* /*who*/)
//            {
//            }
//            
//            void JustDied(Unit* /*killer*/)
//            {
//            }
//            
//            void KilledUnit(Unit* victim)
//            {
//            }
//            
//            void UpdateAI(uint32 const diff)
//            {
//                if (!UpdateVictim() || !CheckInRoom())
//                    return;
//                    
//                events.Update(diff);
//                
//                if (me->HasUnitState(UNIT_STATE_CASTING))
//                    return;
//                    
//                while (uint32 eventId = events.ExecuteEvent())
//                {
//                    switch (eventId)
//                    {
//                    }
//                }
//                DoMeleeAttackIfReady();
//            }
//       };
//        
//        CreatureAI* GetAI(Creature* creature) const
//        {
//            return new npc_diener_der_unterweltAI(creature);
//        }
//}; 

void AddSC_trash_verlies_neu()
{
    new npc_magierdaemon();
    new npc_kriegerdaemon();
    new npc_paladindaemon();
    //new npc_zerfleischtergefangener();
    //new npc_verletztergefangener();
    //new npc_mutiertergefangener();
    //new npc_hilflosergefangener();
    //new npc_diener_der_unterwelt();
}