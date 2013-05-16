#include "AccountMgr.h"
#include "Chat.h"
#include "Language.h"
#include "Player.h"
#include "ScriptPCH.h"
#include <string.h>

class custom_cs_headhunter : public CommandScript
{
public:
    custom_cs_headhunter() : CommandScript("custom_cs_headhunter") { }
    ChatCommand* GetCommands() const
    {
        static ChatCommand kopfgeldTable[] =
        {
            { "setzen",         SEC_PLAYER,			true,  &add,                              "", NULL },
            { "info",    SEC_PLAYER,         true,  &info,                             "", NULL },
            { "topliste",		SEC_PLAYER,         true,  &top,							  "", NULL },
            { NULL,				SEC_PLAYER,         false, NULL,                              "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "kopfgeld",       SEC_PLAYER,         true,  NULL,					 "", kopfgeldTable },
            { NULL,             SEC_PLAYER,         false, NULL,                     "", NULL          }
        };
        return commandTable;
    }
    static bool add(ChatHandler* handler, char const* args)
	{
		Player *hunted = handler->getSelectedPlayer();
		if(!hunted)
		{
			handler->PSendSysMessage("Du hast kein Ziel.");
			return true;
		}
		if(!strlen(args))
		{
			handler->PSendSysMessage("Du musst einen Goldbetrag eingeben.");
			return true;
		}
		if(strcmp(handler->GetSession()->GetPlayer()->GetName(), hunted->GetName()))
		{
			handler->PSendSysMessage("Du kannst nur Kopfgeld auf andere Spieler setzen.");
			return true;
		}
		if(hunted->isGameMaster())
		{
			handler->PSendSysMessage("Du kannst kein Kopfgeld auf GameMaster aussetzen!");
			return true;
		}
		if(hunted->getLevel()+10 < handler->GetSession()->GetPlayer()->getLevel())
		{
			handler->PSendSysMessage("Das Ziel auf das du das Kopfgeld setzen willst darf maximal 10 Level niedriger sein als du.");
			return true;
		}
		unsigned int money = atoi(args);
		if(money == 0)
		{
			handler->PSendSysMessage("Deine Eingabe war nicht richtig.");
			return true;
		}
		if(handler->GetSession()->GetPlayer()->GetMoney() < money*10000)
		{
			handler->PSendSysMessage("Du hast nicht genug Gold.");
			return true;
		}
		QueryResult result = WorldDatabase.PQuery("SELECT money FROM custom_headhunter WHERE client = '%s' AND hunted = '%s';", handler->GetSession()->GetPlayer()->GetName(), hunted->GetName());
		if(result)
		{
			Field *field = result->Fetch();
			WorldDatabase.PQuery("UPDATE custom_headhunter SET money = money + %i WHERE client = '%s' AND hunted = '%s';", money, handler->GetSession()->GetPlayer()->GetName(), hunted->GetName());
			handler->GetSession()->GetPlayer()->SetMoney(handler->GetSession()->GetPlayer()->GetMoney() - money*10000);
			handler->PSendSysMessage("Das Kopfgeld wurde von %i Gold auf %i (+%i Gold) Gold angehoben.", result->Fetch()[0].GetInt32(), result->Fetch()[0].GetInt32()+money, money);
			ChatHandler *huntedChat = new ChatHandler(hunted->GetSession());
			huntedChat->PSendSysMessage("%s hat dein Kopfgeld von %i Gold auf %i (+%i Gold) Gold angehoben.", handler->GetSession()->GetPlayer()->GetName(), result->Fetch()[0].GetInt32(), result->Fetch()[0].GetInt32()+money, money);
			delete huntedChat;
			return true;
		}
		handler->GetSession()->GetPlayer()->SetMoney(handler->GetSession()->GetPlayer()->GetMoney() - money*10000);
		handler->PSendSysMessage("Du hast ein Kopfgeld von %i Gold auf %s ausgesetzt.", money, hunted->GetName());
		WorldDatabase.PQuery("INSERT INTO custom_headhunter (client, hunted, money) VALUES ('%s', '%s', %i)", handler->GetSession()->GetPlayer()->GetName(), hunted->GetName(), money);
		ChatHandler *huntedChat = new ChatHandler(hunted->GetSession());
		huntedChat->PSendSysMessage("Es wurde ein Kopfgeld von %s auf dich ausgesetzt (%i Gold)", handler->GetSession()->GetPlayer()->GetName(), money);
		delete huntedChat;
		return true;
    }
	static bool info(ChatHandler* handler, char const* args)
	{
		Player *infoPlayer = handler->getSelectedPlayer();
		if(!infoPlayer)
		{
			handler->PSendSysMessage("Du hast kein Ziel.");
			return true;
		}
		bool kopfgeld = false;
		int moneyTotal = 0;
		QueryResult result = WorldDatabase.PQuery("SELECT client, money FROM custom_headhunter WHERE hunted = '%s';", infoPlayer->GetName());
		if(result)
		{
			do
			{
				kopfgeld = true;
				handler->PSendSysMessage("Kopfgeld von %i Gold ausgesetzt von %s.", result->Fetch()[1].GetInt32(), result->Fetch()[0].GetCString());
				moneyTotal += result->Fetch()[1].GetInt32();
			}
			while (result->NextRow());
		}
		if(kopfgeld)
			handler->PSendSysMessage("Gesamt Kopfgeld von %i Gold.", moneyTotal);
		else
			handler->PSendSysMessage("Kein Kopfgeld ausgesetzt.");
		return true;
    }
	static bool top(ChatHandler* handler, char const* args)
	{
		QueryResult result = WorldDatabase.PQuery("SELECT * FROM custom_headhunter ORDER BY money DESC LIMIT 10;");
		if(result)
		{
			int platz = 1;
			Field *fields = result->Fetch();
			do
			{
				handler->PSendSysMessage("Platz %i Kopfgeld von %s ausgesetzt auf %s (%i Gold).", platz , fields[0].GetCString(), fields[1].GetCString(), fields[2].GetInt32());
				platz++;
			}
			while (result->NextRow());
		}
		else
		{
			handler->PSendSysMessage("Es sind keine Kopfgelder ausgesetzt.");
		}
		return true;
    }
};

void AddSC_custom_cs_headhunter()
{
    new custom_cs_headhunter();
}
