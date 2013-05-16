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

#ifndef DEF_RUBY_SANCTUM_H
#define DEF_RUBY_SANCTUM_H

enum Sonstiges
{
    COUNTER_OFF			            = 255,
    MAX_ENCOUNTERS		            = 6,
};

enum Data
{
    TYPE_EVENT			            = 0,
    TYPE_RAGEFIRE		            = 1,
    TYPE_BALTHARUS	             	= 2,
    TYPE_XERESTRASZA	            = 3,
    TYPE_ZARITHRIAN		            = 4,
    TYPE_HALION			            = 5,
    TYPE_COUNTER		            = 6,
    TYPE_HALION_EVENT               = 7,
    TYPE_EVENT_TIMER	            = 50,
    TYPE_EVENT_NPC		            = 51,    
    DATA_EVENT_TIMER            	= 101,
    DATA_EVENT			            = 102,
    DATA_ORB_DIRECTION           	= 110,
    DATA_ORB_S		            	= 111,
    DATA_ORB_N			            = 112,
};

enum Objects
{
    GO_HALION_PORTAL_1				= 202794,
    GO_HALION_PORTAL_2				= 202795,
    GO_HALION_PORTAL_3				= 202796,
    GO_FIRE_FIELD					= 203005,
    GO_FLAME_WALLS					= 203006,
    GO_FLAME_RING					= 203007,
};

enum NPCs
{
    NPC_HALION_REAL		            = 39863,
    NPC_HALION_TWILIGHT         	= 40142,
    NPC_HALION_CONTROL	            = 40146,
    NPC_BALTHARUS	            	= 39751,
    NPC_CLONE		                = 39899,
    NPC_ZARITHIAN	             	= 39746,
    NPC_RAGEFIRE	            	= 39747,
    NPC_XERESTRASZA		            = 40429,
    NPC_BALTHARUS_TARGET			= 26712,
    NPC_ZARITHIAN_SPAWN_STALKER		= 39794,
    NPC_SHADOW_PULSAR_N             = 40083,
    NPC_SHADOW_PULSAR_S             = 40100,
    NPC_SHADOW_PULSAR_E             = 40468,
    NPC_SHADOW_PULSAR_W             = 40469,
    NPC_ORB_CARRIER					= 40081,
    NPC_ORB_ROTATION_FOCUS			= 40091,
};

enum uiWorldStates
{
    UPDATE_STATE_UI_COUNT_R			= 5050,
    UPDATE_STATE_UI_COUNT_T			= 5050,
    UPDATE_STATE_UI_SHOW			= 5051,
};

#endif