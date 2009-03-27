/******************************************************************************/
// Free implementation of Bullfrog's Dungeon Keeper strategy game.
/******************************************************************************/
/** @file lvl_filesdk1.h
 *     Header file for lvl_filesdk1.c.
 * @par Purpose:
 *     Level files reading routines fore standard DK1 levels.
 * @par Comment:
 *     Just a header file - #defines, typedefs, function prototypes etc.
 * @author   Tomasz Lis
 * @date     10 Mar 2009 - 20 Mar 2009
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/

#ifndef DK_LVL_FILESDK1_H
#define DK_LVL_FILESDK1_H

#include "bflib_basics.h"
#include "globals.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
long convert_old_column_file(unsigned long lv_num);
long load_column_file(unsigned long lv_num);
short load_slab_file(void);
long load_map_data_file(unsigned long lv_num);
short load_thing_file(unsigned long lv_num);
long load_action_point_file(unsigned long lv_num);
short load_texture_map_file(unsigned long tmapidx, unsigned char n);

short load_level_file(unsigned long lvnum);
short load_map_file(long lvidx);
/******************************************************************************/
#ifdef __cplusplus
}
#endif
#endif
