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
#include "PassiveAI.h"
#include "BattlegroundIC.h"

class npc_four_car_garage : public CreatureScript
{
    public:
        npc_four_car_garage() : CreatureScript("npc_four_car_garage") {}

        struct npc_four_car_garageAI : public NullCreatureAI
        {
            npc_four_car_garageAI(Creature* creature) : NullCreatureAI(creature) { }

            void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply)
            {
                if (apply)
                {
                    uint32 spellId = 0;

                    switch (me->GetEntry())
                    {
                        case NPC_DEMOLISHER:
                            spellId = SPELL_DRIVING_CREDIT_DEMOLISHER;
                            break;
                        case NPC_GLAIVE_THROWER_A:
                        case NPC_GLAIVE_THROWER_H:
                            spellId = SPELL_DRIVING_CREDIT_GLAIVE;
                            break;
                        case NPC_SIEGE_ENGINE_H:
                        case NPC_SIEGE_ENGINE_A:
                            spellId = SPELL_DRIVING_CREDIT_SIEGE;
                            break;
                        case NPC_CATAPULT:
                            spellId = SPELL_DRIVING_CREDIT_CATAPULT;
                            break;
                        default:
                            return;
                    }

                    me->CastSpell(who, spellId, true);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_four_car_garageAI(creature);
        }
};

enum SpellsBosses
{
  SPELL_DAGGER_THROW_1    = 67280,
  SPELL_DAGGER_THROW_2    = 67881,
  SPELL_CRUSHING_LEAP     = 60895,
  SPELL_MORTAL_STRIKE     = 39171,
  SPELL_RAGE              = 66776
};

class bosses_isle_of_conquest : public CreatureScript
{
public:
  bosses_isle_of_conquest() : CreatureScript("bosses_isle_of_conquest") { }
  
  CreatureAI *GetAI(Creature *creature) const
  {
      return new bosses_isle_of_conquestAI(creature);
  }

  struct bosses_isle_of_conquestAI : public ScriptedAI
  {
      bosses_isle_of_conquestAI(Creature *c) : ScriptedAI(c) 
      { 
          if (level != 0)
              level += m_MaxLevel - 60;
          c->SetLevel(level);      
      }

      uint8 m_MaxLevel;
      uint8 level;
      uint32 uiMortalStrikeTimer;
      uint32 uiDaggerThrowTimer;
      uint32 uiCrushingLeapTimer;
      uint32 uiResetTimer;
      uint32 uiRage;

      void Reset()
      {
          uiMortalStrikeTimer = 8*IN_MILLISECONDS;
          uiDaggerThrowTimer  = 2*IN_MILLISECONDS;
          uiCrushingLeapTimer = 6*IN_MILLISECONDS;
          uiResetTimer        = 5*IN_MILLISECONDS;
      }
      
      void EnterCombat(Unit * who)
      {
          if (!me->IsWithinLOSInMap(who))
          {
              EnterEvadeMode();
          }
      }

      void JustRespawned()
      {
          Reset();
      }

      void UpdateAI(const uint32 diff)
      {
          if (!UpdateVictim())
              return;

          if (uiMortalStrikeTimer < diff)
          {
              if (Unit *pVictim = me->getVictim())
                  DoCast(pVictim, SPELL_MORTAL_STRIKE);
              uiMortalStrikeTimer = urand(10*IN_MILLISECONDS,20*IN_MILLISECONDS);
          }
          else
              uiMortalStrikeTimer -= diff;

          if (uiDaggerThrowTimer < diff)
          {
              if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                  DoCast(pTarget, RAID_MODE(SPELL_DAGGER_THROW_1, SPELL_DAGGER_THROW_2));
              uiDaggerThrowTimer = urand(7*IN_MILLISECONDS,12*IN_MILLISECONDS);
          }
          else
              uiDaggerThrowTimer -= diff;

          if (uiCrushingLeapTimer < diff)
          {
              if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                  DoCast(pTarget, SPELL_CRUSHING_LEAP);
              uiCrushingLeapTimer = urand(12*IN_MILLISECONDS,16*IN_MILLISECONDS);
          }
          else
              uiCrushingLeapTimer -= diff;
          
          if (uiRage <= diff)
          {
              if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 50)
                  DoCast(me->getVictim(), SPELL_RAGE);                  
          } else uiRage -= diff;
          
          if (uiResetTimer < diff)
          {
              float x,y;
              me->GetPosition(x,y);

              if (me->GetEntry()== NPC_OVERLORD_AGMAR && (x > 1348 || x < 1283 || y < -800 || y > -730))
              {
                  if (Unit *pVictim = me->getVictim())
                      me->Kill(pVictim);
                  me->MonsterSay("Antibugers:$N, No querias bugear rqlo :)", LANG_UNIVERSAL, me->GetGUID());
                  EnterEvadeMode();
              }

              if (me->GetEntry()== NPC_HIGH_COMMANDER_HALFORD_WYRMBANE && (x > 288 || x < 216 || y < -863 || y > -800))
              {
                  EnterEvadeMode();
                  me->MonsterSay("Antibugers:$N, No querias bugear rqlo :)", LANG_UNIVERSAL, me->GetGUID());
                  if (Unit *pVictim = me->getVictim())
                      me->Kill(pVictim);                   
              }
              uiResetTimer = 200;
          }
          else   
              uiResetTimer -= diff;

          DoMeleeAttackIfReady();
      }
  };
};

void AddSC_isle_of_conquest()
{
    new npc_four_car_garage();
    new bosses_isle_of_conquest();
}
