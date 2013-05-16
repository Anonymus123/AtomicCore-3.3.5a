/********************************************************************************
*                                                                               *
*        Copyright (c) 2013 - AtomicScripting <http://atomiccore.de.ki/>        *
*                                                                               *
*        Verbreitung dieses Scriptes ist untersagt und darf nur nach            *
*        Absprache mit dem Author erfolgen.                                     *
*                                                                               *
********************************************************************************/

// Erklärung:   Dieses Script kann verwendet werden, um über bestimmte Codes
//              (welche in der Datenbank festgelegt werden müssen) zB ein bestimmtes
//              Item, Levelups oder anderes zu verschenken.



#include "ScriptPCH.h"

class npc_code_system : public CreatureScript
{
    public:
		npc_code_system() : CreatureScript("npc_code_system") { }
		
        bool OnGossipHello(Player* player, Creature* creature)
        {
            player->
        }

};

bool checkCode()
{

}

void AddSC_npc_code_system()
{
    new npc_code_system;
}