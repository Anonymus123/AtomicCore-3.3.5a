###############################################################################################
#                                                                                             #
#                          ______ _  __   _____ ____  _____  ______                           #
#                         |  ____| |/ /  / ____/ __ \|  __ \|  ____|                          #
#                         | |__  | ' /  | |   | |  | | |__) | |__                             #
#                         |  __| |  <   | |   | |  | |  _  /|  __|                            #
#                         | |    | . \  | |___| |__| | | \ \| |____                           #
#                         |_|    |_|\_\  \_____\____/|_|  \_\______|                          #
#                                                                                             #
#                              Copyright (c) Frozen Kingdom WoW                               #
#                                                                                             #
#                                                                                             #
#            Diese Emulation unterliegt vollständig dem Copyright / Kopierschutz              #
#            von Frozen Kingdom WoW. Sämtliche Vervielfältigung oder Verbreitung              #
#            dieser hier enthaltenen Medien wird juristisch bestraft. Diese                   #
#            Software darf nur vom Herausgeber Frozen Kingdom WoW verwendet bzw               #
#            Weiterverwendet werden.                                                          #
#                                                                                             #
#                                                                                             #
#            This emulation is subject to the law of copyright from "The Frozen               #
#            Kingdom World of Warcraft" servers. All copying of these here contained          #
#            content, will be legitimate punished. This software must only used by            #
#            the publisher.                                                                   #
#                                                                                             #
###############################################################################################

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  Custom/resetduel.cpp
  Custom/theme_npc.cpp
  Custom/transmogrification.cpp
  Custom/transmogrification.h
  Custom/level_rewards.cpp
  Custom/dalaran_squirrel.cpp
  Custom/npc_customize.cpp
  Custom/npc_vip.cpp
  Custom/argent_tournament.cpp
  Custom/event_teleporter.cpp
  Custom/cs_headhunter.cpp
  Custom/headhunter.cpp
  Custom/custom_hochzeit.cpp
  Custom/DasVerlies/boss_abbadon.cpp
  Custom/DasVerlies/boss_teufelsdrache.cpp
  Custom/DasVerlies/instance_verlies_neu.cpp
  Custom/DasVerlies/npc_wache_thomas.cpp
  Custom/DasVerlies/trash_verlies_neu.cpp
  Custom/DasVerlies/boss_hauptmann_lanzrath.cpp
  Custom/DasVerlies/verlies_neu.h
  Custom/DasVerlies/npc_wache_thomas.cpp
  Custom/item_vip.cpp
  Custom/npc_code_gift.cpp
  Custom/npc_code_system.cpp
)

message("  -> Prepared: Custom")
