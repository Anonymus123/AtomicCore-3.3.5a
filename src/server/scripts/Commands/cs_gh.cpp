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

#include "Chat.h"
#include "Player.h"
#include "World.h"
#include "SocialMgr.h"
#include "ScriptMgr.h"

class gh_commandscript : public CommandScript
{
    public:
        gh_commandscript() : CommandScript("gh_commandscript") { }
        
        ChatCommand* GetCommands() const
        {

            static ChatCommand commandTable[] =
            {
                { "gh",             SEC_PLAYER,      	true, &HandleGHCommand,				"", NULL },
                { NULL,             0,                  false, NULL,                        "", NULL }
            };
            return commandTable;
        }
        
        static bool HandleGHCommand(ChatHandler* handler, const char* args)
        {
            Player *chr = handler->GetSession()->GetPlayer();

            if(chr->isInFlight())
            {
                    handler->PSendSysMessage(LANG_YOU_IN_FLIGHT);
                    //SetSentErrorMessage(true);
                    return false;
            }

            if(chr->isInCombat())
            {
                    handler->PSendSysMessage(LANG_YOU_IN_COMBAT);
                    //SetSentErrorMessage(true);
                    return false;
            }

            if (chr->GetGuildId() == 0)
            {
                    return false;
            }

            QueryResult result;
            result = CharacterDatabase.PQuery("SELECT `x`, `y`, `z`, `map` FROM `guildhouses` WHERE `guildId` = %u", chr->GetGuildId());
            if(!result)
            {
                    handler->PSendSysMessage("GH Port");
                    return false;
            }


            float x, y, z;
            uint32 map;

            Field *fields = result->Fetch();
            x = fields[0].GetFloat();
            y = fields[1].GetFloat();
            z = fields[2].GetFloat();
            map = fields[3].GetUInt32();
            

            chr->SaveRecallPosition();
            chr->TeleportTo(map, x, y, z, 0);
            chr->SaveToDB();
            return true;
        }

};

void AddSC_gh_commandscript()
{
    new gh_commandscript();
}

            