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
#include "Channel.h"
#include "Guild.h"
#include "Group.h"

class custom_headhunter : public PlayerScript
{
public:
	custom_headhunter() : PlayerScript("custom_headhunter") { }
	virtual void OnPVPKill(Player* killer, Player* killed)
	{ 
		if(killer == killed)
			return;
		int totalmoney = 0;
		QueryResult result = WorldDatabase.PQuery("SELECT money FROM custom_headhunter WHERE client <> '%s' AND hunted = '%s';", killer->GetName(), killed->GetName());
		if(result)
		{
			do
			{
				Field *fields = result->Fetch();
				totalmoney += result->Fetch()[0].GetInt32();
			}
			while (result->NextRow());
		}
		if(totalmoney)
		{
			ChatHandler *killerChat = new ChatHandler(killer->GetSession());
			killerChat->PSendSysMessage("Du hast das auf %s ausgesetzte Kopfgeld erhalten (%i Gold).", killed->GetName(), totalmoney);
			delete killerChat;
			ChatHandler *killedChat = new ChatHandler(killed->GetSession());
			killerChat->PSendSysMessage("Das auf dich ausgesetzte Kopfgeld (%i Gold) geht an %s.", totalmoney, killer->GetName());
			delete killedChat;
			killer->SetMoney(killer->GetMoney()+totalmoney*10000);
		}
		WorldDatabase.PQuery("DELETE FROM custom_headhunter WHERE client <> '%s' AND hunted = '%s';", killer->GetName(), killed->GetName());
	}
};

void AddSC_custom_headhunter()
{
    new custom_headhunter();
}
