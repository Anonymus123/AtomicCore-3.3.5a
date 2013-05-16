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
    SPELL_SHIELD_BASH             = 70964,
    SPELL_SABER_LASH              = 71021,
    SPELL_DISRUPTING_SHOUT        = 71022,
    SPELL_CRYPT_SCARABS           = 70965,
    SPELL_DARK_MENDING            = 71020,
    SPELL_WEB_WRAP                = 70980,
    SPELL_GLACIAL_BLAST           = 71029,
    SPELL_BONE_FLURRY             = 70960,
    SPELL_SHATTERED_BONES         = 70961,
    SPELL_SHATTERED_BONES_VISUAL  = 70963,
    SPELL_CHAOS_BOLT_10M          = 69576,    
    SPELL_CHAOS_BOLT_25M          = 71108,
    SPELL_CONSUMING_SHADOWS       = 69405,
    SPELL_CURSE_OF_AGONY_10M      = 69404,
    SPELL_CURSE_OF_AGONY_25M      = 71112,
    SPELL_SHADOW_BOLT_DEATHSPEAKER= 69387,
    SPELL_DARK_BLESSING           = 69391,
    SPELL_SHADOW_MEND_10M         = 69389,
    SPELL_SHADOW_MEND_25M         = 71107,
    SPELL_SHADOW_NOVA_10M         = 69355,
    SPELL_SHADOW_NOVA_25M         = 71106,
    SPELL_SHADOW_CLEAVE           = 69492,
    SPELL_DARK_RECKONING          = 69483,
    SPELL_AURA_OF_DARKNESS        = 69491,
    SPELL_SEVERED_ESSENCE_10M     = 71906,
    SPELL_SEVERED_ESSENCE_25M     = 71942,
    SPELL_CLEAVE                  = 40504,
    SPELL_PLAGUE_CLOUD            = 71150,
    SPELL_SCOURGE_HOOK            = 71140,
    SPELL_LEAPING_FACE_MAUL       = 71164,
    SPELL_DEVOUR_HUMANOID         = 71164,
    SPELL_PLAGUE_BLAST            = 73079,
    SPELL_PLAGUE_STREAM           = 69871,
    SPELL_COMBOBULATING_SPRAY     = 71103,
    SPELL_BLIGHT_BOMB             = 71088,
    SPELL_BUBBLING_PUS_10M        = 71089,
    SPELL_BUBBLING_PUS_25M        = 71090,
    SPELL_MASSIVE_STOMP_10M       = 71114,
    SPELL_MASSIVE_STOMP_25M       = 71115,
    SPELL_AMPLIFY_MAGIC_10M       = 70408,
    SPELL_AMPLIFY_MAGIC_25M       = 72336,
    SPELL_BLAST_WAVE_10M          = 70407,
    SPELL_BLAST_WAVE_25M          = 71151,
    SPELL_FIREBALL_10M            = 70409,
    SPELL_FIREBALL_25M            = 71153,
    SPELL_POLYMORPH_SPIDER        = 70410,
    SPELL_SIPHON_ESSENCE          = 70299,
    SPELL_VAMPIRIC_AURA           = 71736,
    SPELL_UNHOLY_STRIKE           = 70437,
    SPELL_BLOOD_MIRROR_DAMAGE     = 70445,
    SPELL_BLOOD_MIRROR_BUFF       = 70451,
    SPELL_BLOOD_MIRROR_DUMMY      = 70450,
    SPELL_CHAINS_OF_SHADOW        = 70645,
    SPELL_SHADOW_BOLT_10M         = 72960,
    SPELL_SHADOW_BOLT_25M         = 72961,
    SPELL_DISEASE_CLOUD           = 41290,
    SPELL_LEECHING_ROT            = 70671,
    SPELL_LICH_SLAP_10M           = 72057,
    SPELL_LICH_SLAP_25M           = 72421,
    SPELL_SHROUD_OF_PROTECTION    = 72065,
    SPELL_SHROUD_OF_SPELL_WARDING = 72066,
    SPELL_VAMPIRE_RUSH_10M        = 70449,
    SPELL_VAMPIRE_RUSH_25M        = 71155,
    SPELL_BATTLE_SHOUT            = 70750,
    SPELL_VAMPIRIC_CURSE          = 70423,
    SPELL_REND_FLESH_10M          = 70435,
    SPELL_REND_FLESH_25M          = 71154,
    SPELL_SHADOWSTEP              = 70431,
    SPELL_BLOOD_SAP               = 70432,
    SPELL_BANISH                  = 71298,
    SPELL_DEATHS_EMBRACE_10M      = 71299,
    SPELL_DEATHS_EMBRACE_25M      = 71300,
    SPELL_SHADOW_BOLT_YMIRJAR_10M = 71296,
    SPELL_SHADOW_BOLT_YMIRJAR_25M = 71297,
    SPELL_SUMMON_YMIRJAR          = 71303,
    SPELL_ARCTIC_CHILL            = 71270,
    SPELL_FROZEN_ORB              = 71274,
    SPELL_TWISTED_WINDS           = 71306,
    SPELL_SPIRIT_STREAM           = 69929,
    SPELL_ADRENALINE_RUSH         = 71258,
    SPELL_BARBARIC_STRIKE         = 71257,
    SPELL_ICE_TRAP                = 71249,
    SPELL_RAPID_SHOT              = 71251,
    SPELL_SHOOT                   = 71253,
    SPELL_VOLLEY                  = 71252,
    SPELL_SUMMON_WARHAWK          = 71705,
    SPELL_WHIRLWIND               = 41056,
    SPELL_SOUL_FEAST_ALL          = 71203
};

enum npcs
{
    NPC_DEATHBOUND_WARD          = 37007,
    NPC_SERVANT_OF_THE_THRONE    = 36724,
    NPC_ANCIENT_SKELETAL_SOLDIER = 37012,
    NPC_THE_DAMNED               = 37011,
    NPC_NERUBAR_BROODKEEPER      = 36725,
    NPC_DEATHSPEAKER_SERVANT     = 36805,
    NPC_DEATHSPEAKER_ZEALOT      = 36808,
    NPC_DEATHSPEAKER_DISCIPLE    = 36807,
    NPC_DEATHSPEAKER_ATTENDANT   = 36811,
    NPC_DEATHSPEAKER_HIGH_PRIEST = 36829,
    NPC_VALKYR_HERALD            = 37098,
    NPC_BLIGHTED_ABOMINATION     = 37022,
    NPC_VENGEFUL_FLESHREAPER     = 37038,
    NPC_PUSTULATING_HORROR       = 10404,
    NPC_PLAGUE_SCIENTIST         = 37023,
    NPC_DECAYING_COLOSSUS        = 36880,
    NPC_DARKFALLEN_ARCHMAGE      = 37664,
    NPC_DARKFALLEN_BLOOD_KNIGHT  = 37595,
    NPC_DARKFALLEN_NOBLE         = 37663,
    NPC_VAMPIRIC_FIEND           = 37901,
    NPC_DARKFALLEN_ADVISOR       = 37571,
    NPC_DARKFALLEN_COMMANDER     = 37662,
    NPC_DARKFALLEN_TACTICIAN     = 37666,
    NPC_DARKFALLEN_LIEUTENANT    = 37665,
    NPC_YMIRJAR_DEATHBRINGER     = 38125,
    NPC_YMIRJAR_FROSTBINDER      = 37127,
    NPC_YMIRJAR_BATTLE_MAIDEN    = 37132,
    NPC_YMIRJAR_HUNTRESS         = 37134,
    NPC_YMIRJAR_WARLORD          = 37133
};

class npc_ancient_skeletal_soldier_icc : public CreatureScript
{
    public:
        npc_ancient_skeletal_soldier_icc() : CreatureScript("npc_ancient_skeletal_soldier_icc") { }
 
        struct npc_ancient_skeletal_soldier_iccAI : public ScriptedAI
        {
            npc_ancient_skeletal_soldier_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiBASH_Timer;

            void Reset()
            {
                m_uiBASH_Timer = 5000;
            }
 
            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
            if (!UpdateVictim())
                return;
 
            if (m_uiBASH_Timer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_SHIELD_BASH);
                m_uiBASH_Timer = 10000;
            }
            else
               m_uiBASH_Timer -= uiDiff;
 
            DoMeleeAttackIfReady();
            }
        };
 
        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_ancient_skeletal_soldier_iccAI(creature);
        }
};

class npc_deathbound_ward_icc : public CreatureScript
{
    public:
        npc_deathbound_ward_icc() : CreatureScript("npc_deathbound_ward_icc") { }
 
        struct npc_deathbound_ward_iccAI : public ScriptedAI
        {
            npc_deathbound_ward_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiDisrupting_Shout_Timer;
            uint32 m_uiSaber_Lash_Timer;

            void Reset()
            {
                m_uiDisrupting_Shout_Timer = 10000;
                m_uiSaber_Lash_Timer = 7000;
            }
 
            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiDisrupting_Shout_Timer <= uiDiff)
                {
                    DoCastAOE(SPELL_DISRUPTING_SHOUT);
                    m_uiDisrupting_Shout_Timer = 15000;
                }
                else
                    m_uiDisrupting_Shout_Timer -= uiDiff;

                if (m_uiSaber_Lash_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_SABER_LASH);
                    m_uiSaber_Lash_Timer = 7000;
                }
                else
                    m_uiSaber_Lash_Timer -= uiDiff;
        
                DoMeleeAttackIfReady();   
            }
        };
 
        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_deathbound_ward_iccAI(creature);
        }
};

class npc_nerubar_broodkeeper_icc : public CreatureScript
{
    public:
        npc_nerubar_broodkeeper_icc() : CreatureScript("npc_nerubar_broodkeeper_icc") { }
 
        struct npc_nerubar_broodkeeper_iccAI : public ScriptedAI
        {
            npc_nerubar_broodkeeper_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiSCARABS_Timer;
            uint32 m_uiMENDING_Timer;
            uint32 m_uiWRAPS_Timer;

            void Reset()
            {
                m_uiSCARABS_Timer = 1000;
                m_uiMENDING_Timer = urand(5000, 8000);
                m_uiWRAPS_Timer = urand(5000, 8000);
            }
 
            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
            if (!UpdateVictim())
                return;
 
            if (m_uiWRAPS_Timer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                           DoCast(target, SPELL_WEB_WRAP);
                m_uiWRAPS_Timer = urand(5000, 8000);
            }
            else
               m_uiWRAPS_Timer -= uiDiff;
  
            if (m_uiMENDING_Timer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                           DoCast(target, SPELL_DARK_MENDING);
                m_uiMENDING_Timer = urand(5000, 8000);
            }
            else
               m_uiMENDING_Timer -= uiDiff;

            if (m_uiSCARABS_Timer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_CRYPT_SCARABS);
                m_uiSCARABS_Timer = 2000;
            }
            else
               m_uiSCARABS_Timer -= uiDiff;
 
            DoMeleeAttackIfReady();
            }
        };
 
        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_nerubar_broodkeeper_iccAI(creature);
        }
};

class npc_servant_of_the_throne_icc : public CreatureScript
{
    public:
        npc_servant_of_the_throne_icc() : CreatureScript("npc_servant_of_the_throne_icc") { }

        struct npc_servant_of_the_throne_iccAI : public ScriptedAI
        {
            npc_servant_of_the_throne_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiGlacial_Blast_Timer;

            void Reset()
            {
                m_uiGlacial_Blast_Timer = 1000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiGlacial_Blast_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                           DoCast(target, SPELL_GLACIAL_BLAST);
                    m_uiGlacial_Blast_Timer = 6000;
                }
                else
                   m_uiGlacial_Blast_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_servant_of_the_throne_iccAI(creature);
        }
};

class npc_the_damned_icc : public CreatureScript
{
    public:
        npc_the_damned_icc() : CreatureScript("npc_the_damned_icc") { }

        struct npc_the_damned_iccAI : public ScriptedAI
        {
            npc_the_damned_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}
        
            uint32 m_uiBone_Flurry_Timer;

            void Reset()
            {
                m_uiBone_Flurry_Timer = 20000;    
            }

            void JustDied(Unit * killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
                DoCastAOE(SPELL_SHATTERED_BONES);
                DoCast(me, SPELL_SHATTERED_BONES_VISUAL);
                DoCast(me, SPELL_SHATTERED_BONES_VISUAL);
                DoCast(me, SPELL_SHATTERED_BONES_VISUAL);
                DoCast(me, SPELL_SHATTERED_BONES_VISUAL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiBone_Flurry_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_BONE_FLURRY);
                    m_uiBone_Flurry_Timer = urand(20000, 30000);
                }
                else
                    m_uiBone_Flurry_Timer -= uiDiff;
 
                DoMeleeAttackIfReady();   
            }
        };
 
        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_the_damned_iccAI(creature);
        }
};

class npc_deathspeaker_servant_10man_icc : public CreatureScript
{
    public:
        npc_deathspeaker_servant_10man_icc() : CreatureScript("npc_deathspeaker_servant_10man_icc") { }

        struct npc_deathspeaker_servant_10man_iccAI : public ScriptedAI
        {
            npc_deathspeaker_servant_10man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiCHAOS_Timer;
            uint32 m_uiCONSUMING_Timer;
            uint32 m_uiCURSE_Timer;

            void Reset()
            {
                m_uiCHAOS_Timer = 2000;
                m_uiCONSUMING_Timer = urand(3000, 5000);
                m_uiCURSE_Timer = urand(3000, 5000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiCHAOS_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_CHAOS_BOLT_10M);
                    m_uiCHAOS_Timer = urand(3000, 4000);
                }
                else
                    m_uiCHAOS_Timer -= uiDiff;

                if (m_uiCONSUMING_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_CONSUMING_SHADOWS);
                    m_uiCONSUMING_Timer = urand(8000, 15000);
                }
                else
                    m_uiCONSUMING_Timer -= uiDiff;

                if (m_uiCURSE_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_CURSE_OF_AGONY_10M);
         
                    m_uiCURSE_Timer = urand(15000, 20000);
                }
                else
                    m_uiCURSE_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };
 
        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_deathspeaker_servant_10man_iccAI(creature);
        }
};

/*class npc_deathspeaker_servant_25man_icc : public CreatureScript
{
    public:
        npc_deathspeaker_servant_25man_icc() : CreatureScript("npc_deathspeaker_servant_25man_icc") { }

        struct npc_deathspeaker_servant_25man_iccAI : public ScriptedAI
        {
            npc_deathspeaker_servant_25man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiCHAOS_Timer;
            uint32 m_uiCONSUMING_Timer;
            uint32 m_uiCURSE_Timer;

            void Reset()
            {
                m_uiCHAOS_Timer = 2000;
                m_uiCONSUMING_Timer = urand(2000, 3000);
                m_uiCURSE_Timer = urand(2000, 3000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiCHAOS_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_CHAOS_BOLT_25M);
                    m_uiCHAOS_Timer = (4000, 6000);
                }
                else
                    m_uiCHAOS_Timer -= uiDiff;

                if (m_uiCONSUMING_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_CONSUMING_SHADOWS);
                    m_uiCONSUMING_Timer = urand(6000, 10000);
                }
                else
                    m_uiCONSUMING_Timer -= uiDiff;

                if (m_uiCURSE_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_CURSE_OF_AGONY_25M);
                    m_uiCURSE_Timer = urand(10000, 15500);
                }
                else
                    m_uiCURSE_Timer -= uiDiff;
 
                DoMeleeAttackIfReady();   
            }
        };
 
        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_deathspeaker_servant_25man_iccAI(creature);
        }
};
*/

class npc_deathspeaker_disciple_10man_icc : public CreatureScript
{
    public:
        npc_deathspeaker_disciple_10man_icc() : CreatureScript("npc_deathspeaker_disciple_10man_icc") { }

        struct npc_deathspeaker_disciple_10man_iccAI : public ScriptedAI
        {
            npc_deathspeaker_disciple_10man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}
 
            uint32 m_uiBOLT_Timer;
            uint32 m_uiBLESSING_Timer;
            uint32 m_uiMEND_Timer;

            void Reset()
            {
                m_uiBOLT_Timer = 2000;
                m_uiBLESSING_Timer = urand(3000, 5000);
                m_uiMEND_Timer = urand(5000, 10000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiBOLT_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_SHADOW_BOLT_DEATHSPEAKER);
                    m_uiBOLT_Timer = urand(3000, 7000);
                }
                else
                    m_uiBOLT_Timer -= uiDiff;

                if (m_uiBLESSING_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_DARK_BLESSING);
                    m_uiBLESSING_Timer = urand(8000, 15000);
                }
                else
                    m_uiBLESSING_Timer -= uiDiff;
 
                if (m_uiMEND_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_SHADOW_MEND_10M);
                    m_uiMEND_Timer = urand(8000, 10000);
                }
                else
                    m_uiMEND_Timer -= uiDiff;
 
                DoMeleeAttackIfReady();   
            }
        };
 
        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_deathspeaker_disciple_10man_iccAI(creature);
        }
};

/*class npc_deathspeaker_disciple_25man_icc : public CreatureScript
{
    public:
        npc_deathspeaker_disciple_25man_icc() : CreatureScript("npc_deathspeaker_disciple_25man_icc") { }

        struct npc_deathspeaker_disciple_25man_iccAI : public ScriptedAI
        {
            npc_deathspeaker_disciple_25man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiBOLT_Timer;
            uint32 m_uiBLESSING_Timer;
            uint32 m_uiMEND_Timer;

            void Reset()
            {
                m_uiBOLT_Timer = 2000;
                m_uiBLESSING_Timer = urand(1000, 3000);
                m_uiMEND_Timer = urand(3000, 5000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiBOLT_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_SHADOW_BOLT_DEATHSPEAKER);
                    m_uiBOLT_Timer = urand(2000, 3000);
                }
                else
                    m_uiBOLT_Timer -= uiDiff;

                if (m_uiBLESSING_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_DARK_BLESSING);
                    m_uiBLESSING_Timer = urand(8000, 10000);
                }
                else
                    m_uiBLESSING_Timer -= uiDiff;

                if (m_uiMEND_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_SHADOW_MEND_25M);
                    m_uiMEND_Timer = urand(5000, 8000);
                }
                else
                    m_uiMEND_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_deathspeaker_disciple_25man_iccAI(creature);
        }
};*/

class npc_deathspeaker_attendant_10man_icc : public CreatureScript
{
    public:
        npc_deathspeaker_attendant_10man_icc() : CreatureScript("npc_deathspeaker_attendant_10man_icc") { }

        struct npc_deathspeaker_attendant_10man_iccAI : public ScriptedAI
        {
            npc_deathspeaker_attendant_10man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiBOLT_Timer;
            uint32 m_uiNOVA_Timer;

            void Reset()
            {
                m_uiBOLT_Timer = 2000;
                m_uiNOVA_Timer = urand(5000, 10000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiBOLT_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_SHADOW_BOLT_DEATHSPEAKER);
                    m_uiBOLT_Timer = urand(3000, 5000);
                }
                else
                    m_uiBOLT_Timer -= uiDiff;

                if (m_uiNOVA_Timer <= uiDiff)
                {
                    DoCastAOE(SPELL_SHADOW_NOVA_10M);
                    m_uiNOVA_Timer = urand(5000, 10000);
                }
                else
                    m_uiNOVA_Timer -= uiDiff;
 
                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_deathspeaker_attendant_10man_iccAI(creature);
        }
};

/*class npc_deathspeaker_attendant_25man_icc : public CreatureScript
{
    public:
        npc_deathspeaker_attendant_25man_icc() : CreatureScript("npc_deathspeaker_attendant_25man_icc") { }

        struct npc_deathspeaker_attendant_25man_iccAI : public ScriptedAI
        {
            npc_deathspeaker_attendant_25man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiBOLT_Timer;
            uint32 m_uiNOVA_Timer;

            void Reset()
            {
                m_uiBOLT_Timer = 2000;
                m_uiNOVA_Timer = urand(5000, 8000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiBOLT_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_SHADOW_BOLT_DEATHSPEAKER);
                    m_uiBOLT_Timer = urand(2000, 3000);
                }
                else
                    m_uiBOLT_Timer -= uiDiff;

                if (m_uiNOVA_Timer <= uiDiff)
                {
                    DoCastAOE(SPELL_SHADOW_NOVA_25M);
                    m_uiNOVA_Timer = urand(5000, 10000);
                }
                else
                    m_uiNOVA_Timer -= uiDiff;
 
                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_deathspeaker_attendant_25man_iccAI(creature);
        }
};*/

class npc_deathspeaker_zealot_icc : public CreatureScript
{
    public:
        npc_deathspeaker_zealot_icc() : CreatureScript("npc_deathspeaker_zealot_icc") { }

        struct npc_deathspeaker_zealot_iccAI : public ScriptedAI
        {
            npc_deathspeaker_zealot_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiCLEAVE_Timer;

            void Reset()
            {
                m_uiCLEAVE_Timer = 6000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiCLEAVE_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_SHADOW_CLEAVE);
                    m_uiCLEAVE_Timer = 6000;
                }
                else
                    m_uiCLEAVE_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_deathspeaker_zealot_iccAI(creature);
        }
};

class npc_deathspeaker_high_priest_icc : public CreatureScript
{
    public:
        npc_deathspeaker_high_priest_icc() : CreatureScript("npc_deathspeaker_high_priest_icc") { }
 
        struct npc_deathspeaker_high_priest_iccAI : public ScriptedAI
        {
            npc_deathspeaker_high_priest_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiRECKONING_Timer;
            uint32 m_uiAURA_Timer;

            void Reset()
            {
                m_uiRECKONING_Timer = 2000;
                m_uiAURA_Timer = 1000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiAURA_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_AURA_OF_DARKNESS);
                    m_uiAURA_Timer = urand(12000, 18000);
                }
                else
                    m_uiAURA_Timer -= uiDiff;

                if (m_uiRECKONING_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_DARK_RECKONING);
                    m_uiRECKONING_Timer = urand(10000, 12000);
                }
                else
                    m_uiRECKONING_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_deathspeaker_high_priest_iccAI(creature);
        }
};

class npc_valkyr_herald_10man_icc : public CreatureScript
{
    public:
        npc_valkyr_herald_10man_icc() : CreatureScript("npc_valkyr_herald_10man_icc") { }
 
        struct npc_valkyr_herald_10man_iccAI : public ScriptedAI
        {
            npc_valkyr_herald_10man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiESSENCE_Timer;

            void Reset()
            {
                m_uiESSENCE_Timer = 1000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiESSENCE_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_SEVERED_ESSENCE_10M);
                    m_uiESSENCE_Timer = urand(2000, 8000);
                }
                else
                    m_uiESSENCE_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_valkyr_herald_10man_iccAI(creature);
        }
};

/*class npc_valkyr_herald_25man_icc : public CreatureScript
{
    public:
        npc_valkyr_herald_25man_icc() : CreatureScript("npc_valkyr_herald_25man_icc") { }
 
        struct npc_valkyr_herald_25man_iccAI : public ScriptedAI
        {
            npc_valkyr_herald_25man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiESSENCE_Timer;

            void Reset()
            {
                m_uiESSENCE_Timer = 1000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiESSENCE_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_SEVERED_ESSENCE_25M);
                    m_uiESSENCE_Timer = urand(2000, 8000);
                }
                else
                    m_uiESSENCE_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_valkyr_herald_25man_iccAI(creature);
        }
};*/

class npc_blighted_abomination_icc : public CreatureScript
{
    public:
        npc_blighted_abomination_icc() : CreatureScript("npc_blighted_abomination_icc") { }

        struct npc_blighted_abomination_iccAI : public ScriptedAI
        {
            npc_blighted_abomination_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiCLOUD_Timer;
            uint32 m_uiCLEAVE_Timer;
            uint32 m_uiHOOK_Timer;

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void Reset()
            {
                m_uiCLOUD_Timer = 10000;
                m_uiCLEAVE_Timer = 4000;
                m_uiHOOK_Timer = 5000;
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiCLOUD_Timer <= uiDiff)
                {
                    DoCastAOE(SPELL_PLAGUE_CLOUD);
                    m_uiCLOUD_Timer = 20000;
                }
                else
                    m_uiCLOUD_Timer -= uiDiff;

                if (m_uiHOOK_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_SCOURGE_HOOK);
                    m_uiHOOK_Timer = urand(12000, 20000);
                }
                else
                    m_uiHOOK_Timer -= uiDiff;
 
                if (m_uiCLEAVE_Timer <= uiDiff)
                {
                    m_uiCLEAVE_Timer = 6000;
                }
                else
                    m_uiCLEAVE_Timer -= uiDiff;
 
                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_blighted_abomination_iccAI(creature);
        }
};

class npc_vengeful_fleshreapert_icc : public CreatureScript
{
    public:
        npc_vengeful_fleshreapert_icc() : CreatureScript("npc_vengeful_fleshreapert_icc") { }

        struct npc_vengeful_fleshreapert_iccAI : public ScriptedAI
        {
            npc_vengeful_fleshreapert_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiJUMP_Timer;
            uint32 m_uiDEVOUR_Timer;

            void Reset()
            {
                m_uiJUMP_Timer = urand(3000, 20000);
                m_uiDEVOUR_Timer = urand(3000, 5000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiJUMP_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_LEAPING_FACE_MAUL);
                    m_uiJUMP_Timer = urand(20000,40000);
                }
                else
                    m_uiJUMP_Timer -= uiDiff;

                if (m_uiDEVOUR_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_DEVOUR_HUMANOID);
                    m_uiDEVOUR_Timer = urand(5000,8000);
                }
                else
                    m_uiDEVOUR_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_vengeful_fleshreapert_iccAI(creature);
        }
};

class npc_plague_scientist_icc : public CreatureScript
{
    public:
        npc_plague_scientist_icc() : CreatureScript("npc_plague_scientist_icc") { }
 
        struct npc_plague_scientist_iccAI : public ScriptedAI
        {
            npc_plague_scientist_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiBLAST_Timer;
            uint32 m_uiSTREAM_Timer;
            uint32 m_uiSTREAM_OUT_Timer;
            uint32 m_uiSPRAY_Timer;    

            void Reset()
            {
                m_uiBLAST_Timer = 2000;
                m_uiSTREAM_Timer = urand(8000, 12000);
                m_uiSTREAM_OUT_Timer = 24000;
                m_uiSPRAY_Timer = urand(5000, 8000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiSTREAM_Timer <= uiDiff)
                {
                    if (m_uiSTREAM_OUT_Timer > uiDiff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_PLAGUE_STREAM);
                        m_uiSTREAM_OUT_Timer -= uiDiff;
                    }
                    else
                    {
                        me->CastStop(SPELL_PLAGUE_STREAM);
                        m_uiSTREAM_OUT_Timer = urand(15000, 20000);
                    }
                }
                else
                    m_uiSTREAM_Timer -= uiDiff;

                if (m_uiSPRAY_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_COMBOBULATING_SPRAY);
                    m_uiSPRAY_Timer = urand(8000, 12000);
                }
                else
                    m_uiSPRAY_Timer -= uiDiff;
 
                if (m_uiBLAST_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_PLAGUE_BLAST);
                    m_uiBLAST_Timer = urand(2000, 3000);
                }
                else
                    m_uiBLAST_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_plague_scientist_iccAI(creature);
        }
};

class npc_pustulating_horror_10man_icc : public CreatureScript
{
    public:
        npc_pustulating_horror_10man_icc() : CreatureScript("npc_pustulating_horror_10man_icc") { }

        struct npc_pustulating_horror_10man_iccAI : public ScriptedAI
        {
            npc_pustulating_horror_10man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiPUS_Timer;

            void Reset()
            {
                m_uiPUS_Timer = 2000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (HealthBelowPct(15))
                {
                    DoCastAOE(SPELL_BLIGHT_BOMB);
                    m_uiPUS_Timer = 5000;
                }

                if (m_uiPUS_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0))
                        DoCast(target, SPELL_BUBBLING_PUS_10M);
                    if (HealthAbovePct(15))
                        m_uiPUS_Timer = urand(15000, 25000);
                }
                else
                    m_uiPUS_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };
 
        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_pustulating_horror_10man_iccAI(creature);
        }
};

/*class npc_pustulating_horror_25man_icc : public CreatureScript
{
    public:
        npc_pustulating_horror_25man_icc() : CreatureScript("npc_pustulating_horror_25man_icc") { }

        struct npc_pustulating_horror_25man_iccAI : public ScriptedAI
        {
            npc_pustulating_horror_25man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiPUS_Timer;

            void Reset()
            {
                m_uiPUS_Timer = 2000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (HealthBelowPct(15))
                {
                    DoCastAOE(SPELL_BLIGHT_BOMB);
                    m_uiPUS_Timer = 5000;
                }

                if (m_uiPUS_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0))
                        DoCast(target, SPELL_BUBBLING_PUS_25M);
                    if (HealthAbovePct(15))
                        m_uiPUS_Timer = urand(15000, 20000);
                }
                else
                    m_uiPUS_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_pustulating_horror_25man_iccAI(creature);
        }
};*/

class npc_decaying_colossus_10man_icc : public CreatureScript
{
    public:
        npc_decaying_colossus_10man_icc() : CreatureScript("npc_decaying_colossus_10man_icc") { }

        struct npc_decaying_colossus_10man_iccAI : public ScriptedAI
        {
            npc_decaying_colossus_10man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiSTOMP_Timer;

            void Reset()
            {
                m_uiSTOMP_Timer = 5000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiSTOMP_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_MASSIVE_STOMP_10M);
                    m_uiSTOMP_Timer = urand(15000, 25000);
                }
                else
                    m_uiSTOMP_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };
 
        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_decaying_colossus_10man_iccAI(creature);
        }
};

/*class npc_decaying_colossus_25man_icc : public CreatureScript
{
    public:
        npc_decaying_colossus_25man_icc() : CreatureScript("npc_decaying_colossus_25man_icc") { }

        struct npc_decaying_colossus_25man_iccAI : public ScriptedAI
        {
            npc_decaying_colossus_25man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiSTOMP_Timer;

            void Reset()
            {
                m_uiSTOMP_Timer = 5000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiSTOMP_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_MASSIVE_STOMP_25M);
                    m_uiSTOMP_Timer = urand(15000, 25000);
                }
                else
                    m_uiSTOMP_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };
 
        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_decaying_colossus_25man_iccAI(creature);
        }
};*/

class npc_darkfallen_archmage_10man_icc : public CreatureScript
{
    public:
        npc_darkfallen_archmage_10man_icc() : CreatureScript("npc_darkfallen_archmage_10man_icc") { }

        struct npc_darkfallen_archmage_10man_iccAI : public ScriptedAI
        {
            npc_darkfallen_archmage_10man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiAMPLIFY_Timer;
            uint32 m_uiBLAST_Timer;
            uint32 m_uiFIREBALL_Timer;
            uint32 m_uiPOLYMORPH_Timer;

            void Reset()
            {
                m_uiAMPLIFY_Timer = urand(10000, 15000);
                m_uiBLAST_Timer = urand(8000, 10000);
                m_uiFIREBALL_Timer = 2000;
                m_uiPOLYMORPH_Timer = urand(9000, 12000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiAMPLIFY_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_AMPLIFY_MAGIC_10M);
                    m_uiAMPLIFY_Timer = urand(15000, 20000);
                }
                else
                    m_uiAMPLIFY_Timer -= uiDiff;

                if (m_uiPOLYMORPH_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_POLYMORPH_SPIDER);
                    m_uiPOLYMORPH_Timer = urand(15000, 18000);
                }
                else
                    m_uiPOLYMORPH_Timer -= uiDiff;

                if (m_uiFIREBALL_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_FIREBALL_10M);
                    m_uiFIREBALL_Timer = urand(3000, 4000);
                }
                else
                    m_uiFIREBALL_Timer -= uiDiff;
 
                if (m_uiBLAST_Timer <= uiDiff)
                {
                    DoCastAOE(SPELL_BLAST_WAVE_10M);
                    m_uiBLAST_Timer = urand(10000, 20000);
                }
                else
                    m_uiBLAST_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_archmage_10man_iccAI(creature);
        }
};

/*class npc_darkfallen_archmage_25man_icc : public CreatureScript
{
    public:
        npc_darkfallen_archmage_25man_icc() : CreatureScript("npc_darkfallen_archmage_25man_icc") { }

        struct npc_darkfallen_archmage_25man_iccAI : public ScriptedAI
        {
            npc_darkfallen_archmage_25man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiAMPLIFY_Timer;
            uint32 m_uiBLAST_Timer;
            uint32 m_uiFIREBALL_Timer;
            uint32 m_uiPOLYMORPH_Timer;

            void Reset()
            {
                m_uiAMPLIFY_Timer = urand(10000, 15000);
                m_uiBLAST_Timer = urand(8000, 10000);
                m_uiFIREBALL_Timer = 2000;
                m_uiPOLYMORPH_Timer = urand(9000, 12000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiAMPLIFY_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_AMPLIFY_MAGIC_25M);
                    m_uiAMPLIFY_Timer = urand(10000, 15000);
                }
                else
                    m_uiAMPLIFY_Timer -= uiDiff;

                if (m_uiPOLYMORPH_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_POLYMORPH_SPIDER);
                    m_uiPOLYMORPH_Timer = urand(12000, 15000);
                }
                else
                    m_uiPOLYMORPH_Timer -= uiDiff;

                if (m_uiFIREBALL_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_FIREBALL_25M);
                    m_uiFIREBALL_Timer = urand(2000, 3000);
                }
                else
                    m_uiFIREBALL_Timer -= uiDiff;
 
                if (m_uiBLAST_Timer <= uiDiff)
                {
                    DoCastAOE(SPELL_BLAST_WAVE_25M);
                    m_uiBLAST_Timer = urand(10000, 20000);
                }
                else
                    m_uiBLAST_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_archmage_25man_iccAI(creature);
        }
};*/

class npc_darkfallen_blood_knight_icc : public CreatureScript
{
    public:
        npc_darkfallen_blood_knight_icc() : CreatureScript("npc_darkfallen_blood_knight_icc") { }

        struct npc_darkfallen_blood_knight_iccAI : public ScriptedAI
        {
            npc_darkfallen_blood_knight_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiAURA_Timer;
            uint32 m_uiSTRIKE_Timer;
            uint32 m_uiMIRROR_Timer;

            void Reset()
            {
                m_uiAURA_Timer = urand(12000, 15000);
                m_uiSTRIKE_Timer = urand(2000, 3000);
                m_uiMIRROR_Timer = urand(4000, 5000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiSTRIKE_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_UNHOLY_STRIKE);
                    m_uiSTRIKE_Timer = urand(3000, 4000);
                }
                else
                    m_uiSTRIKE_Timer -= uiDiff;

                if (m_uiAURA_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_VAMPIRIC_AURA);
                    m_uiAURA_Timer = urand(12000, 15000);
                }
                else
                    m_uiAURA_Timer -= uiDiff;

                if (m_uiMIRROR_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        DoCast(me->getVictim(),SPELL_BLOOD_MIRROR_DUMMY);
                        me->getVictim()->CastSpell(target,SPELL_BLOOD_MIRROR_DAMAGE,true);
                        me->CastSpell(me->getVictim(),SPELL_BLOOD_MIRROR_BUFF,true);
                        m_uiMIRROR_Timer = urand(32000, 37000);
                    }
                }
                else
                    m_uiMIRROR_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_blood_knight_iccAI(creature);
        }
};

class npc_darkfallen_noble_10man_icc : public CreatureScript
{
    public:
        npc_darkfallen_noble_10man_icc() : CreatureScript("npc_darkfallen_noble_10man_icc") { }
 
        struct npc_darkfallen_noble_10man_iccAI : public ScriptedAI
        {
            npc_darkfallen_noble_10man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiCHAINS_Timer;
            uint32 m_uiBOLT_Timer;
            uint32 m_uiFIEND_Timer;

            void Reset()
            {
                m_uiCHAINS_Timer = urand(2000, 4000);
                m_uiBOLT_Timer = urand(3000, 5000);
                m_uiFIEND_Timer = 15000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiBOLT_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_SHADOW_BOLT_10M);
                    m_uiBOLT_Timer = urand(4000, 5000);
                }
                else
                    m_uiBOLT_Timer -= uiDiff;

                if (m_uiCHAINS_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_CHAINS_OF_SHADOW);
                    m_uiCHAINS_Timer = urand(20000, 25000);
                }
                else
                    m_uiCHAINS_Timer -= uiDiff;

                if (m_uiFIEND_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        if (me->SummonCreature(NPC_VAMPIRIC_FIEND,target->GetPositionX(),target->GetPositionY(),target->GetPositionZ()))
                            m_uiFIEND_Timer = 60000;
                }
                else
                    m_uiFIEND_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_noble_10man_iccAI(creature);
        }
};

/*class npc_darkfallen_noble_25man_icc : public CreatureScript
{
    public:
        npc_darkfallen_noble_25man_icc() : CreatureScript("npc_darkfallen_noble_25man_icc") { }

        struct npc_darkfallen_noble_25man_iccAI : public ScriptedAI
        {
            npc_darkfallen_noble_25man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiCHAINS_Timer;
            uint32 m_uiBOLT_Timer;
            uint32 m_uiFIEND_Timer;

            void Reset()
            {
                m_uiCHAINS_Timer = urand(2000, 4000);
                m_uiBOLT_Timer = urand(3000, 5000);
                m_uiFIEND_Timer = 15000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiBOLT_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_SHADOW_BOLT_25M);
                    m_uiBOLT_Timer = urand(3000, 4000);
                }
                else
                    m_uiBOLT_Timer -= uiDiff;

                if (m_uiCHAINS_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_CHAINS_OF_SHADOW);
                    m_uiCHAINS_Timer = urand(15000, 20000);
                }
                else
                    m_uiCHAINS_Timer -= uiDiff;

                if (m_uiFIEND_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        if (me->SummonCreature(NPC_VAMPIRIC_FIEND,target->GetPositionX(),target->GetPositionY(),target->GetPositionZ()))
                            m_uiFIEND_Timer = 60000;
                }
                else
                    m_uiFIEND_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_noble_25man_iccAI(creature);
        }
};*/
 
class npc_vampiric_fiend_icc : public CreatureScript
{
    public:
        npc_vampiric_fiend_icc() : CreatureScript("npc_vampiric_fiend_icc") { }

        struct npc_vampiric_fiend_iccAI : public ScriptedAI
        {
            npc_vampiric_fiend_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiLEECHING_Timer;

            void Reset()
            {
                m_uiLEECHING_Timer = 10000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void EnterCombat(Unit* /*target*/)
            {
                DoCast(me, SPELL_DISEASE_CLOUD);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiLEECHING_Timer <= uiDiff)
                {
                    DoCastAOE(SPELL_LEECHING_ROT);
                    me->ForcedDespawn(3000); 
                    m_uiLEECHING_Timer = 10000;
                }
                else
                    m_uiLEECHING_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_vampiric_fiend_iccAI(creature);
        }
};

class npc_darkfallen_advisor_10man_icc : public CreatureScript
{
    public:
        npc_darkfallen_advisor_10man_icc() : CreatureScript("npc_darkfallen_advisor_10man_icc") { }
 
        struct npc_darkfallen_advisor_10man_iccAI : public ScriptedAI
        {
            npc_darkfallen_advisor_10man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiLICH_Timer;
            uint32 m_uiPROTECTION_Timer;

            void Reset()
            {
                m_uiLICH_Timer = urand(2000, 5000);
                m_uiPROTECTION_Timer = urand(10000, 15000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiLICH_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_LICH_SLAP_10M);
                    m_uiLICH_Timer = 10000;
                }
                else
                    m_uiLICH_Timer -= uiDiff;

                if (m_uiPROTECTION_Timer <= uiDiff)
                {
                    if (Unit* target = urand(0, 1) ? SelectTarget(SELECT_TARGET_RANDOM, 0) : DoSelectLowestHpFriendly(40.0f))
                    {
                        DoCast(target,SPELL_SHROUD_OF_PROTECTION);
                        DoCast(target,SPELL_SHROUD_OF_SPELL_WARDING);
                        m_uiPROTECTION_Timer = urand(15000, 20000);
                    }
                }
                else
                    m_uiPROTECTION_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_advisor_10man_iccAI(creature);
        }
};

/*class npc_darkfallen_advisor_25man_icc : public CreatureScript
{
    public:
        npc_darkfallen_advisor_25man_icc() : CreatureScript("npc_darkfallen_advisor_25man_icc") { }
 
        struct npc_darkfallen_advisor_25man_iccAI : public ScriptedAI
        {
            npc_darkfallen_advisor_25man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiLICH_Timer;
            uint32 m_uiPROTECTION_Timer;

            void Reset()
            {
                m_uiLICH_Timer = urand(2000, 5000);
                m_uiPROTECTION_Timer = urand(10000, 15000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiLICH_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_LICH_SLAP_25M);
                    m_uiLICH_Timer = urand(5000, 8000);
                }
                else
                    m_uiLICH_Timer -= uiDiff;

                if (m_uiPROTECTION_Timer <= uiDiff)
                {
                    if (Unit* target = urand(0, 1) ? SelectTarget(SELECT_TARGET_RANDOM, 0) : DoSelectLowestHpFriendly(40.0f))
                    {
                        DoCast(target,SPELL_SHROUD_OF_PROTECTION);
                        DoCast(target,SPELL_SHROUD_OF_SPELL_WARDING);
                        m_uiPROTECTION_Timer = urand(12000, 15000);
                    }
                }
                else
                    m_uiPROTECTION_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_advisor_25man_iccAI(creature);
        }
};*/

class npc_darkfallen_commander_10man_icc : public CreatureScript
{
    public:
        npc_darkfallen_commander_10man_icc() : CreatureScript("npc_darkfallen_commander_10man_icc") { }
 
        struct npc_darkfallen_commander_10man_iccAI : public ScriptedAI
        {
            npc_darkfallen_commander_10man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiRUSH_Timer;
            uint32 m_uiSHOUT_Timer;

            void Reset()
            {
                m_uiRUSH_Timer = urand(4000, 8000);
                m_uiSHOUT_Timer = urand(8000, 10000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiSHOUT_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_BATTLE_SHOUT);
                    m_uiSHOUT_Timer = urand(15000, 20000);
                }
                else
                    m_uiSHOUT_Timer -= uiDiff;

                if (m_uiRUSH_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_VAMPIRE_RUSH_10M);
                    m_uiRUSH_Timer = urand(10000, 15000);
                }
                else
                    m_uiRUSH_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_commander_10man_iccAI(creature);
        }
};

/*class npc_darkfallen_commander_25man_icc : public CreatureScript
{
    public:
        npc_darkfallen_commander_25man_icc() : CreatureScript("npc_darkfallen_commander_25man_icc") { }

        struct npc_darkfallen_commander_25man_iccAI : public ScriptedAI
        {
            npc_darkfallen_commander_25man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiRUSH_Timer;
            uint32 m_uiSHOUT_Timer;

            void Reset()
            {
                m_uiRUSH_Timer = urand(4000, 8000);
                m_uiSHOUT_Timer = urand(8000, 10000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiSHOUT_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_BATTLE_SHOUT);
                    m_uiSHOUT_Timer = urand(15000, 20000);
                }
                else
                    m_uiSHOUT_Timer -= uiDiff;

                if (m_uiRUSH_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_VAMPIRE_RUSH_25M);
                    m_uiRUSH_Timer = urand(10000, 15000);
                }
                else
                    m_uiRUSH_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_commander_25man_iccAI(creature);
        }
};*/

class npc_darkfallen_lieutenant_10man_icc : public CreatureScript
{
    public:
        npc_darkfallen_lieutenant_10man_icc() : CreatureScript("npc_darkfallen_lieutenant_10man_icc") { }

        struct npc_darkfallen_lieutenant_10man_iccAI : public ScriptedAI
        {
            npc_darkfallen_lieutenant_10man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiREND_Timer;
            uint32 m_uiCURSE_Timer;

            void Reset()
            {
                m_uiREND_Timer = urand(1000, 2000);
                m_uiCURSE_Timer = urand(8000, 15000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiREND_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_REND_FLESH_10M);
                    m_uiREND_Timer = 25000;
                }
                else
                    m_uiREND_Timer -= uiDiff;

                if (m_uiCURSE_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_VAMPIRIC_CURSE);
                    m_uiCURSE_Timer = urand(10000, 20000);
                }
                else
                    m_uiCURSE_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_lieutenant_10man_iccAI(creature);
        }
};

/*class npc_darkfallen_lieutenant_25man_icc : public CreatureScript
{
    public:
        npc_darkfallen_lieutenant_25man_icc() : CreatureScript("npc_darkfallen_lieutenant_25man_icc") { }

        struct npc_darkfallen_lieutenant_25man_iccAI : public ScriptedAI
        {
            npc_darkfallen_lieutenant_25man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiREND_Timer;
            uint32 m_uiCURSE_Timer;

            void Reset()
            {
                m_uiREND_Timer = urand(1000, 2000);
                m_uiCURSE_Timer = urand(8000, 15000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiREND_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_REND_FLESH_25M);
                    m_uiREND_Timer = 25000;
                }
                else
                    m_uiREND_Timer -= uiDiff;

                if (m_uiCURSE_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_VAMPIRIC_CURSE);
                    m_uiCURSE_Timer = urand(10000, 20000);
                }
                else
                    m_uiCURSE_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_lieutenant_25man_iccAI(creature);
        }
};*/

class npc_darkfallen_tactician_icc : public CreatureScript
{
    public:
        npc_darkfallen_tactician_icc() : CreatureScript("npc_darkfallen_tactician_icc") { }

        struct npc_darkfallen_tactician_iccAI : public ScriptedAI
        {
            npc_darkfallen_tactician_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiSHADOWSTEP_Timer;
            uint32 m_uiSAP_Timer;
            uint32 m_uiSTRIKE_Timer;

            void Reset()
            {
                m_uiSHADOWSTEP_Timer = urand(1000, 2000);
                m_uiSAP_Timer = urand(5000, 15000);
                m_uiSTRIKE_Timer = urand(2000, 3000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiSTRIKE_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_UNHOLY_STRIKE);
                    m_uiSTRIKE_Timer = 6000;
                }
                else
                    m_uiSTRIKE_Timer -= uiDiff;

                if (m_uiSAP_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_BLOOD_SAP);
                    m_uiSAP_Timer = urand(15000, 25000);
                }
                else
                    m_uiSAP_Timer -= uiDiff;

                if (m_uiSHADOWSTEP_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_SHADOWSTEP);
                    m_uiSHADOWSTEP_Timer = urand(15000, 20000);
                }
                else
                    m_uiSHADOWSTEP_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_darkfallen_tactician_iccAI(creature);
        }
};

class npc_ymirjar_deathbringer_10man_icc : public CreatureScript
{
    public:
        npc_ymirjar_deathbringer_10man_icc() : CreatureScript("npc_ymirjar_deathbringer_10man_icc") { }

        struct npc_ymirjar_deathbringer_10man_iccAI : public ScriptedAI
        {
            npc_ymirjar_deathbringer_10man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiBANISH_Timer;
            uint32 m_uiEMBRACE_Timer;
            uint32 m_uiBOLT_Timer;

            void Reset()
            {
                m_uiBANISH_Timer = urand(5000, 10000);
                m_uiEMBRACE_Timer = urand(10000, 15000);
                m_uiBOLT_Timer = urand(1000, 2000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiEMBRACE_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_DEATHS_EMBRACE_10M);
                    m_uiEMBRACE_Timer = urand(15000, 25000);
                }
                else
                    m_uiEMBRACE_Timer -= uiDiff;

                if (m_uiBANISH_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_BANISH);
                    m_uiBANISH_Timer = urand(15000, 25000);
                }
                else
                    m_uiBANISH_Timer -= uiDiff;

                if (m_uiBOLT_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(),SPELL_SHADOW_BOLT_YMIRJAR_10M);
                    m_uiBOLT_Timer = 2000;
                }
                else
                    m_uiBOLT_Timer -= uiDiff;
 
                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_ymirjar_deathbringer_10man_iccAI(creature);
        }
};

/*class npc_ymirjar_deathbringer_25man_icc : public CreatureScript
{
    public:
        npc_ymirjar_deathbringer_25man_icc() : CreatureScript("npc_ymirjar_deathbringer_25man_icc") { }

        struct npc_ymirjar_deathbringer_25man_iccAI : public ScriptedAI
        {
            npc_ymirjar_deathbringer_25man_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiBANISH_Timer;
            uint32 m_uiEMBRACE_Timer;
            uint32 m_uiBOLT_Timer;

            void Reset()
            {
                m_uiBANISH_Timer = urand(5000, 10000);
                m_uiEMBRACE_Timer = urand(5000, 10000);
                m_uiBOLT_Timer = urand(1000, 2000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiEMBRACE_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_DEATHS_EMBRACE_25M);
                    m_uiEMBRACE_Timer = urand(15000, 20000);
                }
                else
                    m_uiEMBRACE_Timer -= uiDiff;

                if (m_uiBANISH_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_BANISH);
                    m_uiBANISH_Timer = urand(15000, 20000);
                }
                else
                    m_uiBANISH_Timer -= uiDiff;

                if (m_uiBOLT_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(),SPELL_SHADOW_BOLT_YMIRJAR_25M);
                    m_uiBOLT_Timer = 2000;
                }
                else
                    m_uiBOLT_Timer -= uiDiff;
 
                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_ymirjar_deathbringer_25man_iccAI(creature);
        }
};*/

class npc_ymirjar_frostbinder_icc : public CreatureScript
{
    public:
        npc_ymirjar_frostbinder_icc() : CreatureScript("npc_ymirjar_frostbinder_icc") { }

        struct npc_ymirjar_frostbinder_iccAI : public ScriptedAI
        {
            npc_ymirjar_frostbinder_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiORB_Timer;

            void Reset()
            {
                m_uiORB_Timer = 1000;
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiORB_Timer <= uiDiff)
                {
                    DoCastAOE(SPELL_FROZEN_ORB);
                    m_uiORB_Timer = urand(3000, 5000);
                }
                else
                    m_uiORB_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_ymirjar_frostbinder_iccAI(creature);
        }
};

class npc_ymirjar_battlemaiden_icc : public CreatureScript
{
    public:
        npc_ymirjar_battlemaiden_icc() : CreatureScript("npc_ymirjar_battlemaiden_icc") { }

        struct npc_ymirjar_battlemaiden_iccAI : public ScriptedAI
        {
            npc_ymirjar_battlemaiden_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiRUSH_Timer;
            uint32 m_uiSTRIKE_Timer;

            void Reset()
            {
                m_uiRUSH_Timer = urand(10000, 15000);
                m_uiSTRIKE_Timer = urand(1000, 5000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiSTRIKE_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_BARBARIC_STRIKE);
                    m_uiSTRIKE_Timer = urand(2000, 3000);
                }
                else
                    m_uiSTRIKE_Timer -= uiDiff;

                if (m_uiRUSH_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_ADRENALINE_RUSH);
                    m_uiRUSH_Timer = urand(15000, 25000);
                }
                else
                    m_uiRUSH_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_ymirjar_battlemaiden_iccAI(creature);
        }
};

class npc_ymirjar_huntress_icc : public CreatureScript
{
    public:
        npc_ymirjar_huntress_icc() : CreatureScript("npc_ymirjar_huntress_icc") { }

        struct npc_ymirjar_huntress_iccAI : public ScriptedAI
        {
            npc_ymirjar_huntress_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiTRAP_Timer;
            uint32 m_uiRSHOT_Timer;
            uint32 m_uiSHOT_Timer;
            uint32 m_uiVOLLEY_Timer;

            void Reset()
            {
                m_uiTRAP_Timer = urand(5000, 15000);
                m_uiRSHOT_Timer = urand(10000, 15000);
                m_uiSHOT_Timer = urand(1000, 2000);
                m_uiVOLLEY_Timer = urand(5000, 15000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void EnterCombat(Unit* /*target*/)
            {
                if (Is25ManRaid())
                    DoCast(SPELL_SUMMON_WARHAWK);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiRSHOT_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_RAPID_SHOT);
                    m_uiRSHOT_Timer = urand(15000, 25000);
                }
                else
                    m_uiRSHOT_Timer -= uiDiff;

                if (m_uiVOLLEY_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target,SPELL_VOLLEY);
                    m_uiVOLLEY_Timer = urand(10000, 15000);
                }
                else
                    m_uiVOLLEY_Timer -= uiDiff;
 
                if (m_uiTRAP_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_ICE_TRAP);
                    m_uiTRAP_Timer = urand(30000, 35000);
                }
                else
                    m_uiTRAP_Timer -= uiDiff;

                if (me->isAttackReady())
                {
                    if (me->IsWithinMeleeRange(me->getVictim()))
                        DoMeleeAttackIfReady();
                    else if (m_uiSHOT_Timer <= uiDiff)
                    {
                        DoCast(me->getVictim(),SPELL_SHOOT);
                        m_uiSHOT_Timer = 1000;
                    }
                    else
                        m_uiSHOT_Timer -= uiDiff;
                }
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_ymirjar_huntress_iccAI(creature);
        }
};

class npc_ymirjar_warlord_icc : public CreatureScript
{
    public:
        npc_ymirjar_warlord_icc() : CreatureScript("npc_ymirjar_warlord_icc") { }

        struct npc_ymirjar_warlord_iccAI : public ScriptedAI
        {
            npc_ymirjar_warlord_iccAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            uint32 m_uiWHIRLWIND_Timer;

            void Reset()
            {
                m_uiWHIRLWIND_Timer = urand(5000, 15000);
            }

            void JustDied(Unit* killer)
            {
                DoCast(me,SPELL_SOUL_FEAST_ALL);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;

                if (m_uiWHIRLWIND_Timer <= uiDiff)
                {
                    DoCastAOE(SPELL_WHIRLWIND);
                    m_uiWHIRLWIND_Timer = urand(12000, 20000);
                }
                else
                    m_uiWHIRLWIND_Timer -= uiDiff;

                DoMeleeAttackIfReady();   
            }
        };

        CreatureAI *GetAI(Creature *creature) const
        {
            return new npc_ymirjar_warlord_iccAI(creature);
        }
};

void AddSC_icecrown_citadel_trashmobs()
{
        new npc_ancient_skeletal_soldier_icc();
        new npc_deathbound_ward_icc();
        new npc_servant_of_the_throne_icc();
        new npc_the_damned_icc();
        new npc_deathspeaker_servant_10man_icc();
        new npc_deathspeaker_disciple_10man_icc();
        new npc_deathspeaker_attendant_10man_icc();
        new npc_deathspeaker_zealot_icc();
        new npc_deathspeaker_high_priest_icc();
        new npc_valkyr_herald_10man_icc();
        new npc_blighted_abomination_icc();
        new npc_vengeful_fleshreapert_icc();
        new npc_plague_scientist_icc();
        new npc_pustulating_horror_10man_icc();
        new npc_decaying_colossus_10man_icc();
        new npc_darkfallen_archmage_10man_icc();
        new npc_darkfallen_blood_knight_icc();
        new npc_darkfallen_noble_10man_icc();
        new npc_vampiric_fiend_icc();
        new npc_darkfallen_advisor_10man_icc();
        new npc_darkfallen_commander_10man_icc();
        new npc_darkfallen_lieutenant_10man_icc();
        new npc_darkfallen_tactician_icc();
        new npc_ymirjar_deathbringer_10man_icc();
        new npc_ymirjar_frostbinder_icc();
        new npc_ymirjar_battlemaiden_icc();
        new npc_ymirjar_huntress_icc();
        new npc_ymirjar_warlord_icc();
}