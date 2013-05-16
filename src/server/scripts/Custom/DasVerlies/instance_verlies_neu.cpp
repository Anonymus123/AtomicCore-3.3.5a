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
*            dieser hier enthaltenen Medien wird juristisch verfolgt. Diese                   *
*            Software darf nur vom Herausgeber Frozen Kingdom WoW verwendet bzw               *
*            weiterverwendet werden.                                                          *
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
#include "InstanceScript.h"
#include "verlies_neu.h"

#define ENCOUNTERS 3

class instance_verlies_neu : public InstanceMapScript
{
	public:
		instance_verlies_neu() : InstanceMapScript("instance_verlies_neu", 35) { }
        
        struct instance_verlies_neu_InstanceMapScript: public InstanceScript
        {
            instance_verlies_neu_InstanceMapScript(InstanceMap *map) : InstanceScript(map) { }
            
            uint32 uiEncounter[ENCOUNTERS];            
            uint64 AbbadonGUID;
            uint64 TeufelsdracheGUID;
            uint64 HauptmannLanzrathGUID;
            
            void Initialize()
            {
                AbbadonGUID = 0;
                TeufelsdracheGUID = 0;
                HauptmannLanzrathGUID = 0;
                
                for(uint8 i=0; i<ENCOUNTERS; ++i)
                    uiEncounter[i] = NOT_STARTED;
            }
            
            bool IsEncounterInProgress() const
            {
                for(uint8 i=0; i<ENCOUNTERS; ++i)
                {
                    if (uiEncounter[i] == IN_PROGRESS)
                        return true;
                } 
                return false;
            }
            
            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case NPC_ABBADON:
                        AbbadonGUID = creature->GetGUID();
                        break;
                    case NPC_HAUPTMANN_LANZRATH:
                        HauptmannLanzrathGUID = creature->GetGUID();
                        break;
                    case NPC_TEUFELSDRACHE:
                        TeufelsdracheGUID = creature->GetGUID();
                        break;
                }
            }
            
            uint64 GetData64(uint32 type) const
            {
                switch(type)
                {
                    case DATA_HAUPTMANN_LANZRATH:
                        return HauptmannLanzrathGUID;
                    case DATA_TEUFELSDRACHE:
                        return TeufelsdracheGUID;
                    case DATA_ABBADON:
                        return AbbadonGUID;
                }
                return 0;
            }
            
            void SetData(uint32 type, uint32 data)
            {
                switch(type)
                {
                    case DATA_HAUPTMANN_LANZRATH:
                        uiEncounter[0] = data;
                        break;
                    case DATA_TEUFELSDRACHE:
                        uiEncounter[1] = data;
                        break;
                    case DATA_ABBADON:
                        uiEncounter[2] = data;
                        break;
                }
                if (data == DONE)
                    SaveToDB();
            }
            
            uint32 GetData(uint32 type) const
            {
                switch(type)
                {
                    case DATA_HAUPTMANN_LANZRATH:
                        return uiEncounter[0];
                    case DATA_TEUFELSDRACHE:
                        return uiEncounter[1];
                    case DATA_ABBADON:
                        return uiEncounter[2];
                }
                return 0;
            }
 
            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;
 
                std::string str_data;
                std::ostringstream saveStream;
                saveStream << "H O" << uiEncounter[0] << " " << uiEncounter[1]  << " " << uiEncounter[2]  << " " << uiEncounter[3] << " " << uiEncounter[4] << " " << uiEncounter[5] << " " << uiEncounter[6];
                str_data = saveStream.str();
 
                OUT_SAVE_INST_DATA_COMPLETE;
                return str_data;
            }
 
            void Load(const char* in)
            {
                if (!in)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }
 
                OUT_LOAD_INST_DATA(in);
 
                char dataHead1, dataHead2;
                uint16 data0, data1, data2, data3, data4, data5, data6;
 
                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4 >> data5 >> data6;
 
                if (dataHead1 == 'H' && dataHead2 == 'O')
                {
                    uiEncounter[0] = data0;
                    uiEncounter[1] = data1;
                    uiEncounter[2] = data2;
                    uiEncounter[3] = data3;
                    uiEncounter[4] = data4;
                    uiEncounter[5] = data5;
                    uiEncounter[6] = data6;
 
                    for(uint8 i=0; i<ENCOUNTERS; ++i)
                        if (uiEncounter[i] == IN_PROGRESS)
                            uiEncounter[i] = NOT_STARTED;
                }
                else OUT_LOAD_INST_DATA_FAIL; 
                OUT_LOAD_INST_DATA_COMPLETE;
            }
        };
};

void AddSC_instance_verlies_neu()
{
    new instance_verlies_neu();
}