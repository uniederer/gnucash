/********************************************************************\
 * table-control.h -- table control object                          *
 *                                                                  *
 * This program is free software; you can redistribute it and/or    *
 * modify it under the terms of the GNU General Public License as   *
 * published by the Free Software Foundation; either version 2 of   *
 * the License, or (at your option) any later version.              *
 *                                                                  *
 * This program is distributed in the hope that it will be useful,  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of   *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    *
 * GNU General Public License for more details.                     *
 *                                                                  *
 * You should have received a copy of the GNU General Public License*
 * along with this program; if not, contact:                        *
 *                                                                  *
 * Free Software Foundation           Voice:  +1-617-542-5942       *
 * 51 Franklin Street, Fifth Floor    Fax:    +1-617-542-2652       *
 * Boston, MA  02110-1301,  USA       gnu@gnu.org                   *
 *                                                                  *
\********************************************************************/

#ifndef TABLE_CONTROL_H
#define TABLE_CONTROL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "register-common.h"

/** @addtogroup Table Table
 * @{
 * @file table-control.h
 */
typedef enum
{
    GNC_TABLE_TRAVERSE_POINTER,
    GNC_TABLE_TRAVERSE_LEFT,
    GNC_TABLE_TRAVERSE_RIGHT,
    GNC_TABLE_TRAVERSE_UP,
    GNC_TABLE_TRAVERSE_DOWN
} gncTableTraversalDir;

typedef void (*TableMoveFunc) (VirtualLocation *new_virt_loc,
                               gpointer user_data);

typedef gboolean (*TableTraverseFunc) (VirtualLocation *new_virt_loc,
                                       gncTableTraversalDir dir,
                                       gpointer user_data);

typedef struct table_control
{
    /* called when the cursor is moved */
    TableMoveFunc move_cursor;

    gboolean allow_move;

    /* called to determine traversal when user requests a move */
    TableTraverseFunc traverse;

    gpointer user_data;
} TableControl;


TableControl * gnc_table_control_new (void);
void gnc_table_control_destroy (TableControl *control);

void gnc_table_control_allow_move (TableControl *control,
                                   gboolean allow_move);

#ifdef __cplusplus
}
#endif

/** @} */
#endif
