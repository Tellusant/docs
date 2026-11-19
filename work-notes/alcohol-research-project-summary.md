---
title: "Alcohol Consumption Research — Project Summary"
description: "."
date: 2026-11-15
image: /assets/social-card-publ.png
robots: noindex, nofollow
sitemap: false
---

# Alcohol Consumption Research: Project Summary

**Scope:** International beer, wine, spirits, and total alcohol consumption; explanatory variables, regulatory-policy measurement, statistical modeling, and presentation graphics. Supporting U.S. historical and regional work was also developed.

**Status:** Working research synthesis, reflecting the datasets, diagnostics, model-comparison outputs, and visualizations produced during the project. This is a record of work undertaken, **not** a claim that every model or policy-index candidate has been validated or selected as final.

## 1. Purpose and research questions

The project investigated how alcoholic-beverage consumption varies across countries, regions, income levels, climates, urbanization, cultural indicators, and regulatory environments—and how those relationships change over time. The practical objective was to combine economically interpretable evidence with reliable forecasting and graphics suitable for management audiences.

The core questions were:

1. How do beer, wine, and spirits differ in their cross-country consumption distributions?
2. How do income, climate, urbanization, culture, and regulatory conditions relate to beverage choice and consumption?
3. How have country and regional consumption distributions shifted from 2000 to 2024?
4. Can a robust, interpretable alcohol-policy index be constructed from WHO policy variables?
5. Which econometric specifications forecast consumption better out of sample, including during COVID-19 and recovery?
6. How should these findings be communicated without overstating statistical precision or causality?

## 2. Data foundation

### International panel

The successive master workbooks (`alcohol-global-dataset.xlsx`, versions 2–7) consolidated country-year information. The most recent plotting workbook was **`alcohol-global-dataset-v7.xlsx`**, primarily its `Main` worksheet. Its relevant fields include:

| Domain | Variables used |
|---|---|
| Beverage outcomes | `Beer`, `Wine`, `Spirits`, `Total`; corresponding `_t` variables |
| Size / denominators | `Pop`, `LDApop`, `WHOpop` |
| Income | `DIcoP`, `DIcoP_Pop` |
| Geography | `Country`, `Code`, `Year`, `TelluReg`, `NewReg` |
| Environment | `Temp`, `Humid`, `City_share` |
| Culture | `hierarchical`, `planning`, `stability`; `Varimax_1`–`Varimax_3` |
| Policy | `Regulatory_ix` |

The most recent 2024 cross-sectional density analyses used **142 valid countries**, subject to variable-specific filtering. The 2000/2024 ridge work retained the same country universe where available; regional and beverage-specific effective samples can be smaller.

### Additional research datasets

- **WHO alcohol policy:** `WHO - Alcohol policies.xlsx` and multiple derived policy-index, PCA, bootstrap, reconstruction, and diagnostic workbooks.
- **Consumption imputation:** source and imputed alcohol-consumption workbooks, including scenario variants (`alcohol-consumption-imputed*.xlsx`).
- **Regulatory and restriction proxies:** successive `alcohol-restrictions*.xlsx` files.
- **U.S. history:** alcohol consumption by beverage and region/state, historical tables, population denominator workbooks, and SVG charts covering extended historical periods.

**Data handling principle:** Keep clear distinctions between observed values, reconstructed/imputed values, alternative index specifications, and presentation transformations. A figure's country count and weighting rule should be documented rather than assumed from the master workbook.

## 3. Main analytical workstreams

### A. Cross-country exploratory analysis

We developed one-dimensional KDEs, two-dimensional KDEs, country-level diagnostics, and comparisons by beverage. The analyses considered income, temperature, humidity, urbanization, culture, and regulatory conditions. Some versions excluded zero-consumption observations to prevent zero masses from distorting continuous density estimates.

A central methodological choice for the later presentation graphics was:  

$$
\w_{ib}=q_{ib}\sqrt{P_i},\]
$$  

where $(q_{ib}\$ is beverage $b$'s per-capita consumption in country $i\$, and $P_i\$ is population. This gives greater influence to countries with larger populations and greater beverage consumption, while avoiding the full dominance that direct population weighting can create.

**Interpretation:** These are *beverage-consumption-weighted distributions of country characteristics*, not population probability distributions and not estimates of causal effects.

### B. Income and residualized explanatory variables

For the 2024 bivariate KDE panels, income was represented by:

$$
x_i=\ln(DIcoP\_Pop_i).
$$

To distinguish a variable's association with income from its remaining cross-country variation, selected explanatory variables were residualized using unweighted country-level OLS:

$$
z_i=\alpha+\beta x_i+\varepsilon_i,\qquad z_i^{\mathrm{resid}}=z_i-(\hat\alpha+\hat\beta x_i).
$$

Results recorded in the analyses:

| Dependent variable | Estimated income relationship | OLS $\(R^2\)$ | Countries |
|---|---|---:|---:|
| Temperature | \(52.873-3.761\ln(DIcoP\_Pop)\) | 0.236 | 142 |
| City share | \(-1.0694+0.1574\ln(DIcoP\_Pop)\) | 0.465 | 142 |
| Regulatory Index | \(-3.423+5.320\ln(DIcoP\_Pop)\) | 0.061 | 142 |

Residuals above zero represent values **higher than predicted by income**, not necessarily higher or lower in a normative sense. In particular, the direction of the Regulatory Index must be checked against its construction before describing positive residuals as more or less restrictive.

Four-panel KDE comparisons were created for **beer, spirits, wine, and total alcohol**, including raw and income-residualized temperature, city share, and regulation. Panels were colored separately and scaled independently; color intensity should not be used to compare absolute density magnitudes between beverages.

### C. Regulatory-policy index construction

A substantial workstream explored how to summarize WHO alcohol-policy indicators. It included:

- Iterative PCA specifications and diagnostic reports (`WHO_alcohol_policy_PCA_test2` through `test9A`, among others).
- Bootstrap and stability analyses, including a directional audit.
- Polychoric PCA and rank-normal sensitivity checks, appropriate to consider when policy inputs are ordinal or categorical.
- Reconstruction/imputation exercises for countries with incomplete policy information, including ten-country comparisons.
- Integration of a `Regulatory_ix` field into the international analysis dataset.

**Important qualification:** The file inventory documents extensive testing, but does not by itself establish which candidate PCA/index specification is the approved final policy measure. Index polarity, coverage, stability, missing-data treatment, and sensitivity to methodological choices should accompany any substantive policy interpretation.

### D. Econometric modeling and forecasting

The project also developed country-panel and out-of-sample comparison files for beverage demand. The documented model families include:

- Pooled panel models: income-only and augmented specifications with climate, urbanization, cultural indicators, and residualized urbanization.
- Dynamic models and error-correction models (ECMs).
- Simpler benchmarks, including persistence, income-change, and naive drift / last-year-growth approaches.
- Out-of-sample assessments, including COVID-19 and recovery periods.

Saved outputs include `alcohol-panel-2000-2024-model-results.csv`, `alcohol-oos-model-metrics.csv`, `alcohol-dynamic-oos-metrics.csv`, `alcohol-ecm-oos-metrics.csv`, and related predictions and comparison figures.

**Methodological lesson:** High in-sample fit does not guarantee good forecasts. Forecast performance must be assessed on held-out years and countries, against simple baselines, with attention to pandemic disruption, time dependence, and weighting. The presence of multiple evaluation tables should not be collapsed into a single winner without reconciling their different samples, forecast targets, units, and error definitions.

### E. Historical U.S. work

The project inventory also contains U.S. beer, wine, spirits, and total-alcohol charts; regional consumption series; historical tables; and age-based population denominators. This provides a separate, longer historical lens and useful plausibility checks, but the U.S. series should not be mixed with the global panel without explicitly aligning units and population definitions.

## 4. Visualization program

The visualization work evolved from standard distribution plots toward **weighted KDEs and regional ridgeline comparisons**.

### One-dimensional KDEs

These summarize the distribution of one characteristic at a time, weighted by beverage consumption and population. Versions examined beverage consumption, income, climate, culture, and regulation. One later chart compared beer, spirits, and wine along the Regulatory Index.

### Two-dimensional KDEs

These show joint concentration along two axes, without country scatter dots. Later charts placed **log income on the horizontal axis** and temperature, urbanization, regulation, or their income-residualized counterparts on the vertical axis. Beverage-specific colors were:

| Beverage | Color |
|---|---|
| Beer | Blue |
| Spirits | Green |
| Wine | Red |
| Total | Purple |

A separate exploratory graph put beer consumption on the horizontal axis and regulation on the vertical axis, with income-based weighting. This was *not* adopted for the management presentation because it introduced an additional interpretive burden.

### Income ridges, 2000 versus 2024

Regional ridgelines compared distributions of **log income per capita**, weighted by beer consumption per capita times square-root population. They answered: *At which income levels is beer consumption concentrated, and how did this shift between 2000 and 2024?*

### Beer-consumption ridges, 2000 versus 2024 — final presentation choice

The final selected ridges instead put **beer consumption per capita (`Beer`) on the x-axis**. Each regional ridge overlays:

- **2000:** orange (`#e1a04a`)
- **2024:** blue (`#2467aa`)

The weighting remains \(Beer_i\sqrt{Pop_i}\). The two years within a region use a common peak-height scaling, while the horizontal axis is shared across regions and slides. The resulting shapes and shifts can be compared **within each region**, but peak heights do **not** measure regional market volume or permit direct absolute-density comparisons across regions.

The original eight-region sequence was:

1. Northern America
2. Core Europe
3. Peripheral Europe & Central Asia
4. Latin America & Caribbean
5. East Asia
6. Southeast Asia & Pacific
7. South Asia
8. Africa

For the slide-ready version, the charts were split:

**Slide / graph 1 — four regions:** Northern America; Core Europe; Peripheral Europe & Central Asia; Latin America & Caribbean.

**Slide / graph 2 — three regions:** **E and SE Asia & Pacific** (a newly pooled East Asia + Southeast Asia & Pacific sample); South Asia; Africa.

The Asian curve was **re-estimated from the pooled country observations**, not calculated by averaging two regional curves. The combined Asian group contains 18 countries; South Asia contains only three, so its smooth density should be treated cautiously. The original eight-region classification remains available for other analyses.

## 5. Final presentation deliverables

These filenames are the actual project output artifacts; paths are relative to the working artifact directory.

| Figure | Editable / vector deliverable | Preview |
|---|---|---|
| **Final beer ridges — top four regions** | `beer_indicator_ridge_top_four_2000_2024.svg` | `.png` of same stem |
| **Final beer ridges — bottom three regions** | `beer_indicator_ridge_bottom_three_2000_2024.svg` | `.png` of same stem |
| Original eight-region beer ridges | `beer_indicator_ridge_newregion_2000_2024.svg` | `.png` |
| Earlier income-based regional ridges | `beer_ridge_newregion_2000_2024.svg` | `.png` |
| Income vs. temperature residual, four panels | `kde_income_vs_temperature_residual_2x2_sqrtpop.svg` | `.png` |
| Income vs. urbanization residual, four panels | `kde_income_vs_cityshare_residual_2x2_sqrtpop.svg` | `.png` |
| Income vs. regulation residual, four panels | `kde_income_vs_regulatory_residual_2x2_sqrtpop.svg` | `.png` |
| Income vs. raw regulation, four panels | `kde_income_vs_regulatory_2x2_sqrtpop.svg` | `.png` |

SVG is preferred for slide use because it remains sharp when resized. PNG versions support rapid preview and compatibility checks.

## 6. What the results do—and do not—say

**Supported descriptive messages**

- Beer, wine, and spirits are associated with different country-characteristic distributions.
- The geographical distribution of beer consumption can be compared between 2000 and 2024 beyond a simple regional mean.
- Income is related to climate, urbanization, and regulation to differing degrees; the 2024 linear regressions above explain roughly 24%, 47%, and 6% of their respective cross-country variation.
- Residualized plots help reveal cross-country variation *conditional on a linear income relationship*.
- Regional distributional changes are not the same thing as changes in total beverage volume.

**Limits**

- KDE is descriptive; it does not identify causation.
- Consumption weighting intentionally emphasizes markets where the beverage is consumed, rather than representing a typical country or person.
- Very small regional samples, notably South Asia, can produce unstable KDE shapes.
- Different KDE bandwidths, handling of zeros, and missing-data rules can materially change apparent peaks.
- Regulatory-index construction and sign interpretation need an explicit final audit before policy claims.
- Forecast results require comparison on the same holdout, metric, sample, and units.
- COVID-19 creates structural disruptions that should be treated explicitly in both model estimation and forecast evaluation.

## 7. Reproducibility and key scripts

The chart-generation scripts include:

- `make_beer_indicator_ridge.py` — original beer-indicator ridges.
- `make_beer_indicator_ridge_split.py` — four-region top/bottom splits.
- `make_beer_indicator_ridge_bottom_three.py` — pooled E and SE Asia & Pacific, South Asia, Africa.
- `make_beer_ridge.py`, `make_ridges_newregion.py` — earlier income-based ridges.
- `make_city_residual.py`, `make_temperature_residual.py`, `make_regulatory_residual.py` — income-residualized four-panel KDEs.
- `make_regulatory_1d.py`, `make_reg_beer_income_weighted.py` — additional regulatory explorations.

The **final bottom-three script** reads the 2000 and 2024 records from `alcohol-global-dataset-v7.xlsx`, keeps nonnegative `Beer` and valid positive `Pop` and `DIcoP_Pop`, assigns the two Asian `NewReg` groups to one pooled region, uses positive `Beer × sqrt(Pop)` weights, estimates a Gaussian KDE for each year, and exports both SVG and PNG. Its KDE bandwidth is bounded below at 0.30 times the standard reference scale (`max(Scott factor, 0.30)`).

To reproduce the final slides, retain the workbook, the two split scripts, the selected SVGs, and the documented weighting and normalization conventions together.

## 8. Recommended next steps

1. **Freeze a reproducible release:** version the master dataset, index definition, plot scripts, and final presentation SVGs together.
2. **Audit the regulatory index:** lock down PCA/index choice, polarity, missing-data rules, and sensitivity results.
3. **Consolidate forecasting comparisons:** select consistent out-of-sample periods and comparable error metrics; report performance versus simple benchmarks.
4. **Prepare a short figure note for each slide:** define x-axis, colors, weighting, normalization, and small-sample cautions.
5. **Keep a clear distinction between exploratory graphics and approved presentation exhibits.** The final two-slide beer ridges are the current presentation selection.

## 9. Executive summary for reuse

> We assembled a cross-country alcohol-consumption research platform covering beer, wine, spirits, and total alcohol, enriched with income, population, climate, urbanization, cultural, and regulatory variables. We examined descriptive relationships through weighted kernel-density methods, developed and tested alternative policy-index constructions, and compared econometric forecasting approaches with out-of-sample benchmarks. For management communication, we selected paired 2000/2024 regional ridge plots showing how the **distribution of beer consumption per capita** has changed across world regions. The final exhibits preserve comparable horizontal scales and distinguish distributional shifts from total market growth.

---

*Prepared 15 November 2026. This synthesis reflects inspected project files and the documented analysis decisions; it is not a replacement for full model specifications, policy-index validation, or source-data provenance.*
