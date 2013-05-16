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
*                              Copyright (c) Noxx Development                                 *
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
#include "ScriptMgr.h"

class cs_cmove : public CommandScript
{
    private:
        static void getParameter(char const* args, int index, int *begin, int *end)
        {
            int i;
            i = *begin = *end = 0;
            while(index >= 0)
            {
                index--;
                while(args[i] == ' ' && args[i] != '\0')
                {
                    i++;
                }
                *begin = i;
                while(args[i] != ' ' && args[i] != '\0')
                {
                    i++;
                }
                *end = i;
            }
        }
        
        static int getAccountID(char const* account)
        {
            QueryResult result = LoginDatabase.PQuery("SELECT id FROM account WHERE username = '%s'", account);
            if(result)
            {
                Field *fields = result->Fetch();
                return fields[0].GetInt32();
            }
            else
            {
                return 0;
            }
        }
        
        static int getCharacterID(char const* character)
        {
            QueryResult result = CharacterDatabase.PQuery("SELECT guid FROM characters WHERE name = '%s'", character);
            if(result)
            {
                Field *fields = result->Fetch();
                return fields[0].GetInt32();
            }
            else
            {
                return 0;
            }
        }
        
        static bool transferCharacter(int accountID, int characterID)
        {
            int countCharacter = 0;
            QueryResult result = CharacterDatabase.PQuery("SELECT guid FROM characters WHERE account = %i", accountID);
            if(result)
            {
                do
                {
                    countCharacter++;
                }
                while (result->NextRow());
            }
            if(countCharacter < 10)
                CharacterDatabase.PQuery("UPDATE characters SET account = %i WHERE guid = %i", accountID, characterID);
            else
                return false;
            return true;
        }

    public:
        cs_cmove() : CommandScript("cs_cmove") { }
        ChatCommand* GetCommands() const
        {
            static ChatCommand commandTable[] =
            {
                { "cmove",		            	SEC_ADMINISTRATOR,         true,	&transfer,		"", NULL },
                { NULL,							SEC_ADMINISTRATOR,         false,	NULL,			"", NULL }
            };
            return commandTable;
        }
        
        static bool transfer(ChatHandler* handler, char const* args)
        {
            int begin, end;
            char *parameter0 = (char *)0, *parameter1 = (char *)0;
            getParameter(args, 0, &begin, &end);
            if(end-begin > 0)
            {
                parameter0 = new char[end-begin+1];
                strncpy(parameter0, args+begin, end-begin);
                parameter0[end-begin] = '\0';
            }
            getParameter(args, 1, &begin, &end);
            if(end-begin > 0)
            {
                parameter1 = new char[end-begin+1];
                strncpy(parameter1, args+begin, end-begin);
                parameter1[end-begin] = '\0';
            }
            if(parameter1)
            {
                int accountID = getAccountID(parameter1), characterID = getCharacterID(parameter0);
                if(!accountID)
                {
                    handler->PSendSysMessage("Der Account existiert nicht.");
                    delete parameter0;
                    delete parameter1;
                    return true; 
                }
                if(!characterID)
                {	
                    handler->PSendSysMessage("Der Charakter existiert nicht.");
                    delete parameter0;
                    delete parameter1;
                    return true;
                }
                if(transferCharacter(accountID, characterID))
                    handler->PSendSysMessage("Der Charakter wurde erfolgreich auf den angegebenen Account verschoben!");
                else
                    handler->PSendSysMessage("Der Account hat die Maximalanzahl von Charakteren erreicht!");
            }
            else
            {
                if(!parameter0)
                {
                    handler->PSendSysMessage("Syntax: .cmove [$characterName]/[Charakter im Target] $accountName");
                    return true;
                }
                int accountID = getAccountID(parameter0);
                if(!accountID)
                {
                    handler->PSendSysMessage("Der Account existiert nicht.");
                    delete parameter0;
                    return true; 
                }
                Player *player = handler->getSelectedPlayer();
                if(player)
                {
                    if(transferCharacter(accountID, player->GetGUID()))
                        handler->PSendSysMessage("Der Charakter wurde erfolgreich auf den angegebenen Account verschoben!");
                    else
                        handler->PSendSysMessage("Der Account hat die Maximalanzahl von Charakteren erreicht !");
                }
                else
                {
                    handler->PSendSysMessage("Kein Spieler im Target verwende optional: .cmove [$characterName] $accountName.");
                }
            }
            if(parameter0)
                delete parameter0;
            if(parameter1)
                delete parameter1;
            return true;
        }
};

void AddSC_cs_cmove()
{
    new cs_cmove();
}
