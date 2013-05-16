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

#ifndef DEF_GUNDRAK_H
#define DEF_GUNDRAK_H

enum Data
{
    DATA_SLAD_RAN_EVENT,
    DATA_MOORABI_EVENT,
    DATA_DRAKKARI_COLOSSUS_EVENT,
    DATA_GAL_DARAH_EVENT,
    DATA_ECK_THE_FEROCIOUS_EVENT,
    DATA_ALIVE_RUIN_DWELLERS
};

enum Data64
{
    DATA_SLAD_RAN_ALTAR,
    DATA_MOORABI_ALTAR,
    DATA_DRAKKARI_COLOSSUS_ALTAR,
    DATA_SLAD_RAN_STATUE,
    DATA_MOORABI_STATUE,
    DATA_DRAKKARI_COLOSSUS_STATUE,
    DATA_DRAKKARI_COLOSSUS,
    DATA_RUIN_DWELLER_DIED,
    DATA_STATUE_ACTIVATE,
};

enum mainCreatures
{
    CREATURE_RUIN_DWELLER                         = 29920,
    CREATURE_SLAD_RAN                             = 29304,
    CREATURE_MOORABI                              = 29305,
    CREATURE_GALDARAH                             = 29306,
    CREATURE_DRAKKARICOLOSSUS                     = 29307,
    CREATURE_ECK                                  = 29932
};

#endif
