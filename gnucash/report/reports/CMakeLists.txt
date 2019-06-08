
add_subdirectory(standard/test)
add_subdirectory(support)

set (reports_common_SCHEME
  aging.scm
)

set (reports_SCHEME
  reports.scm
)

set (reports_standard_SCHEME
    standard/account-piecharts.scm
    standard/account-summary.scm
    standard/advanced-portfolio.scm
    standard/balance-sheet.scm
    standard/balance-forecast.scm
    standard/balsheet-pnl.scm
    standard/budget-balance-sheet.scm
    standard/budget-barchart.scm
    standard/budget-flow.scm
    standard/budget-income-statement.scm
    standard/budget.scm
    standard/cash-flow.scm
    standard/cashflow-barchart.scm
    standard/category-barchart.scm
    standard/dashboard.scm
    standard/equity-statement.scm
    standard/general-journal.scm
    standard/general-ledger.scm
    standard/income-gst-statement.scm
    standard/income-statement.scm
    standard/net-charts.scm
    standard/portfolio.scm
    standard/price-scatter.scm
    standard/reconcile-report.scm
    standard/register.scm
    standard/sx-summary.scm
    standard/transaction.scm
    standard/trial-balance.scm
    standard/view-column.scm
    standard/customer-summary.scm
    standard/taxinvoice.scm
    standard/receipt.scm
    standard/invoice.scm
    standard/job-report.scm
    standard/owner-report.scm
    standard/payables.scm
    standard/receivables.scm
    standard/balsheet-eg.scm
    )

set(reports_example_SCHEME
  example/average-balance.scm
  example/daily-reports.scm
  example/hello-world.scm
  example/sample-graphs.scm
  example/welcome-to-gnucash.scm
)


set(scm_rpts_GUILE_DEPENDS
  gncmod-html
  scm-core-utils
  scm-engine
  scm-gettext
  scm-scm
  scm-gnome-utils
  scm-report
  )

set(scm_rpt_example_GUILE_DEPENDS
  gncmod-html
  scm-app-utils
  scm-core-utils
  scm-gettext
  scm-gnc-module
  scm-scm
  scm-reports-example-links
  scm-gnome-utils
  scm-report
  )

set(scm_rpt_std_GUILE_DEPENDS
  ${scm_rpts_GUILE_DEPENDS}
  scm-app-utils
  scm-gnc-module
  scm-reports-common-links
  scm-reports-standard-links
  )

gnc_add_scheme_targets(scm-rpt-reports
  "${reports_SCHEME}"
  "gnucash/report"
  "${scm_rpts_GUILE_DEPENDS}"
  TRUE
)

gnc_add_scheme_targets(scm-reports-common
  "${reports_common_SCHEME}"
  "gnucash/report/reports"
  "scm-reports-common-links;scm-rpt-reports;${scm_rpt_std_GUILE_DEPENDS}"
  TRUE
)

gnc_add_scheme_targets(scm-reports-standard
  "${reports_standard_SCHEME}"
  "gnucash/report/reports/standard"
  "scm-rpt-reports;${scm_rpt_std_GUILE_DEPENDS}"
  TRUE
)


gnc_add_scheme_targets(scm-reports-example
  "${reports_example_SCHEME}"
  "gnucash/report/reports/example"
  "${scm_rpt_example_GUILE_DEPENDS}"
  TRUE
)

add_custom_target(scm-reports ALL DEPENDS scm-reports-standard scm-reports-example scm-reports-common scm-rpt-reports)

set_local_dist(reports_DIST_local CMakeLists.txt ${reports_SCHEME} ${reports_common_SCHEME} ${reports_standard_SCHEME} ${reports_example_SCHEME})
set(reports_DIST ${reports_DIST_local} ${reports_support_DIST} ${test_reports_standard_DIST} PARENT_SCOPE)