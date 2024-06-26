/********************************************************************\
 * split-register-control.h -- split register control object        *
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

#ifndef SPLIT_REGISTER_CONTROL_H
#define SPLIT_REGISTER_CONTROL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "table-control.h"
/** @addtogroup SplitRegister
 *  @{
 */
/** @file split-register-control.h
 * @brief TableControl specialized for the SplitRegister.*/

/** Create a new TableControl specialized for the SplitRegister. */
TableControl * gnc_split_register_control_new (void);

#ifdef __cplusplus
}
#endif

/** @} */
#endif
