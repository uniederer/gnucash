/********************************************************************\
 * gnc-euro.c -- utilities for EURO currency                        *
 *                                                                  *
 * Copyright (C) 2000 Herbert Thoma                                 *
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
 * along with this program; if not, write to the Free Software      *
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.        *
 *                                                                  *
\********************************************************************/

#include <string>
#include <map>
#include <optional>

#include "gnc-euro.h"
#include "gnc-session.h"

/* The rates are per EURO and are converted to GncNumeric  */
static const std::map<std::string,double> gnc_euro_rates =
{
    { "ATS",  13.7603 },  /* austrian schilling */
    { "BEF",  40.3399 },  /* belgian franc */
    { "CYP",  .585274 },  /* cyprus pound */
    { "DEM",  1.95583 },  /* german mark */
    { "EEK",  15.6466 },  /* Estonian Kroon */
    { "ESP",  166.386 },  /* spanish peseta */
    { "EUR",  1.00000 },  /* euro */
    { "FIM",  5.94573 },  /* finnmark */
    { "FRF",  6.55957 },  /* french franc */
    { "GRD",  340.750 },  /* greek drachma */
    { "HRK",  7.53450 },  /* Croatian kuna */
    { "IEP",  .787564 },  /* irish pound */
    { "ITL",  1936.27 },  /* italian lira */
    { "LUF",  40.3399 },  /* luxembourg franc */
    { "LVL",  .702804 },  /* latvian lats */
    { "MTL",  .429300 },  /* maltese lira */
    { "NLG",  2.20371 },  /* netherland gulden */
    { "PTE",  200.482 },  /* portuguese escudo */
    { "SIT",  239.640 },  /* slovenian tolar */
    { "SKK",  30.1260 }   /* slovak koruna */
};

static std::optional<double>
get_euro_rate (const gnc_commodity * currency)
{
    if (!currency || !gnc_commodity_is_iso(currency))
        return {};

    auto it = gnc_euro_rates.find (gnc_commodity_get_mnemonic(currency));
    if (it == gnc_euro_rates.end())
        return {};

    return it->second;
}

/* ------------------------------------------------------ */

gboolean
gnc_is_euro_currency(const gnc_commodity * currency)
{
    return get_euro_rate (currency).has_value();
}

/* ------------------------------------------------------ */

gnc_numeric
gnc_convert_to_euro(const gnc_commodity * currency, gnc_numeric value)
{
    auto euro_rate = get_euro_rate (currency);
    if (!euro_rate)
        return gnc_numeric_zero();

    auto rate = double_to_gnc_numeric (*euro_rate, 100000, GNC_HOW_RND_ROUND_HALF_UP);

    /* round to 2 decimal places */
    /* EC Regulation 1103/97 states we should use "Round half away from zero"
     * See https://eur-lex.europa.eu/legal-content/EN/TXT/?uri=CELEX%3A31997R1103&qid=1662917247821
     */
    return gnc_numeric_div (value, rate, 100, GNC_HOW_RND_ROUND_HALF_UP);
}

/* ------------------------------------------------------ */

gnc_numeric
gnc_convert_from_euro(const gnc_commodity * currency, gnc_numeric value)
{
    auto euro_rate = get_euro_rate (currency);
    if (!euro_rate)
        return gnc_numeric_zero();

    auto rate = double_to_gnc_numeric (*euro_rate, 100000, GNC_HOW_RND_ROUND_HALF_UP);

    /* EC Regulation 1103/97 states we should use "Round half away from zero"
     * See http://europa.eu/legislation_summaries/economic_and_monetary_affairs/institutional_and_economic_framework/l25025_en.htm */
    return gnc_numeric_mul (value, rate, gnc_commodity_get_fraction (currency),
                            GNC_HOW_RND_ROUND_HALF_UP);
}

/* ------------------------------------------------------ */

gnc_numeric
gnc_euro_currency_get_rate (const gnc_commodity *currency)
{
    auto euro_rate = get_euro_rate (currency);
    if (!euro_rate)
        return gnc_numeric_zero();

    return double_to_gnc_numeric (*euro_rate, GNC_DENOM_AUTO, GNC_HOW_RND_ROUND_HALF_UP);
}

/* ------------------------------------------------------ */

gnc_commodity *
gnc_get_euro (void)
{
    QofBook* book = qof_session_get_book (gnc_get_current_session ());
    gnc_commodity_table *table = gnc_commodity_table_get_table (book);

    return gnc_commodity_table_lookup (table, GNC_COMMODITY_NS_CURRENCY, "EUR");
}
