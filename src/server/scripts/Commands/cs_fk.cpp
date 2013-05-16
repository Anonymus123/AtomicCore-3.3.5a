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
#include "ScriptMgr.h"

class cs_fk : public CommandScript
{
    public:
        cs_fk() : CommandScript("cs_fk") { }
        
        ChatCommand* GetCommands() const
        {
            static ChatCommand commandTable[] =
            {
                //{ "setVIP",		                SEC_ADMINISTRATOR,         true,	&setPremium,	     "", NULL },
                // .setVIP [AccountName] [Dauer]
                //{ "deleteVIP",		            SEC_ADMINISTRATOR,         true,	&deletePremium,   	 "", NULL },
                // .deleteVIP [AccountName]
                //{ "infoVIP",		                SEC_ADMINISTRATOR,         true,	&infoPremium,	     "", NULL },
                // .infoVIP [AccountName] / [Target]
                //{ "dpadd",                        SEC_ADMINISTRATOR,         true,	&DonationPointsAdd,  "", NULL },
                // .dpadd [AccountName] [Anzahl]
                //{ "dpdel",                        SEC_ADMINISTRATOR,         true,	&DonationPointsDel,	 "", NULL },
                // .dpdel [AccountName] [Anzahl]
                //{ "dpinfo",                        SEC_ADMINISTRATOR,         true,	&DonationPointsInfo, "", NULL },
                // .dpinfo [AccountName]
                { NULL,							SEC_ADMINISTRATOR,         false,	NULL,			"", NULL }
            };
            return commandTable;
        }

        //static bool setPremium(ChatHandler* handler, char const* args)
        //{
        //}
        
        //static bool deletePremium(ChatHandler* handler, char const* args)
        //{
        //}
        
        //static bool infoPremium(ChatHandler* handler, char const* args)
        //{
        //}
        
        //static bool DonationPointsAdd(ChatHandler* handler, char const* args)
        //{
        //}
        
        //static bool DonationPointsDel(ChatHandler* handler, char const* args)
        //{
        //}
        
        //static bool DonationPointsInfo(ChatHandler* handler, char const* args)
        //{
        //}
};

void AddSC_cs_fk()
{
    new cs_fk();
}