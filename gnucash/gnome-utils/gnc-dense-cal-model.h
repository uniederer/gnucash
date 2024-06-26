/********************************************************************\
 * gnc-dense-cal-model.h                                            *
 * Copyright (C) 2006 Joshua Sled <jsled@asynchronous.org>          *
 *                                                                  *
 * This program is free software; you can redistribute it and/or    *
 * modify it under the terms of the GNU General Public License as   *
 * published by the Free Software Foundation, under version 2 and   *
 *  / or version 3 of the License.                                  *
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
\********************************************************************/

#ifndef _GNC_DENSE_CAL_MODEL_H
#define _GNC_DENSE_CAL_MODEL_H

#include <config.h>
#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

#define GNC_TYPE_DENSE_CAL_MODEL (gnc_dense_cal_model_get_type ())
G_DECLARE_INTERFACE(GncDenseCalModel, gnc_dense_cal_model, GNC, DENSE_CAL_MODEL, GObject)

struct _GncDenseCalModelInterface
{
    GTypeInterface parent;

    /* virtual table */
    GList* (*get_contained)(GncDenseCalModel *model);
    gchar* (*get_name)(GncDenseCalModel *model, guint tag);
    gchar* (*get_info)(GncDenseCalModel *model, guint tag);
    gint (*get_instance_count)(GncDenseCalModel *model, guint tag);
    void (*get_instance)(GncDenseCalModel *model, guint tag, gint instance_index, GDate *date);
};

/** @return Caller-owned GList (but not elements).  The Model-user will free. **/
GList* gnc_dense_cal_model_get_contained (GncDenseCalModel *model);
gchar* gnc_dense_cal_model_get_name (GncDenseCalModel *model, guint tag);
gchar* gnc_dense_cal_model_get_info (GncDenseCalModel *model, guint tag);
gint gnc_dense_cal_model_get_instance_count (GncDenseCalModel *model, guint tag);
void gnc_dense_cal_model_get_instance (GncDenseCalModel *model,
                                       guint tag,
                                       gint instance_index,
                                       GDate *date);

G_END_DECLS

#endif // _GNC_DENSE_CAL_MODEL_H
