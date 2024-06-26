/********************************************************************\
 * split-register-model-save.h -- split register model object       *
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

#ifndef SPLIT_REGISTER_MODEL_SAVE_H
#define SPLIT_REGISTER_MODEL_SAVE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Transaction.h"
#include "table-model.h"

/** @addtogroup SplitRegister
 * @{
 */
/** @file split-register-model-save.h
 * @brief Save handlers for the SplitRegister Model and Template SplitRegister
 * model.
 */
void gnc_split_register_model_add_save_handlers (TableModel *model);
void gnc_template_register_model_add_save_handlers (TableModel *model);

typedef struct sr_save_data SRSaveData;

SRSaveData * gnc_split_register_save_data_new (Transaction *trans,
        Split *split,
        gboolean expanded);

void gnc_split_register_save_data_destroy (SRSaveData *sd);

#ifdef __cplusplus
}
#endif

/** @} */
#endif
