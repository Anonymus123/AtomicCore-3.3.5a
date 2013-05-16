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

enum Spells
{
    SPELL_TRANSITUS_SHIELD_BEAM = 48310
};

enum NPCs
{
    NPC_TRANSITUS_SHIELD_DUMMY   = 27306,
    NPC_WARMAGE_SARINA           = 32369,
    NPC_WARMAGE_HALISTER         = 32371,
    NPC_WARMAGE_ILSUDRIA         = 32372
};

class npc_warmage_violetstand : public CreatureScript
{
public:
    npc_warmage_violetstand() : CreatureScript("npc_warmage_violetstand") { }

    struct npc_warmage_violetstandAI : public Scripted_NoMovementAI
    {
        npc_warmage_violetstandAI(Creature* creature) : Scripted_NoMovementAI(creature){}

        uint64 uiTargetGUID;

        void Reset()
        {
            uiTargetGUID = 0;
        }

        void UpdateAI(const uint32 /*uiDiff*/)
        {
            if (me->IsNonMeleeSpellCasted(false))
                return;

            if (me->GetEntry() == NPC_WARMAGE_SARINA)
            {
                if (!uiTargetGUID)
                {
                    std::list<Creature*> orbList;
                    GetCreatureListWithEntryInGrid(orbList, me, NPC_TRANSITUS_SHIELD_DUMMY, 32.0f);
                    if (!orbList.empty())
                    {
                        for (std::list<Creature*>::const_iterator itr = orbList.begin(); itr != orbList.end(); ++itr)
                        {
                            if (Creature* pOrb = *itr)
                            {
                                if (pOrb->GetPositionY() < 1000)
                                {
                                    uiTargetGUID = pOrb->GetGUID();
                                    break;
                                }
                            }
                        }
                    }
                }
            }else
            {
                if (!uiTargetGUID)
                    if (Creature* pOrb = GetClosestCreatureWithEntry(me, NPC_TRANSITUS_SHIELD_DUMMY, 32.0f))
                        uiTargetGUID = pOrb->GetGUID();

            }

            if (Creature* pOrb = me->GetCreature(*me, uiTargetGUID))
                DoCast(pOrb, SPELL_TRANSITUS_SHIELD_BEAM);

        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_warmage_violetstandAI(creature);
    }
};

void AddSC_crystalsong_forest()
{
    new npc_warmage_violetstand;
}