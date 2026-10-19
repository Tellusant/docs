---
title: "Long-Term Beverage Demand Forecasting with Panel Data"
description: "A research and commercial modeling strategy using 60-year historical data, 20-year panels, and short client datasets."
---

# Long-Term Beverage Demand Forecasting with Panel Data

## Objective

Develop reliable five-year forecasts of beer and other beverage demand using annual observations across countries. The central question is whether structural panel models, potentially augmented with autoregressive adjustments, outperform country-by-country ARIMA forecasts.

Two historical resources are available: a long dataset covering approximately 60 years and a contemporary panel of roughly 100 countries × 20 years. Commercial clients may have only three years of syndicated market data. The longer series can be used to develop and validate the methodology, while the shorter series can support contemporary estimation and client-level calibration.

## 1. Why ARIMA alone is unlikely to be sufficient

ARIMA models can forecast five years ahead, but with annual data their longer-horizon predictions are largely governed by assumptions about drift, persistence, and mean reversion. Estimating separate ARIMA models from only 20 observations per country is unstable; three observations cannot support meaningful country-specific ARIMA estimation.

A structural demand model offers an alternative: project consumption from economic and demographic drivers, and use autoregressive errors to adjust for recent departures from the long-run trajectory.

## 2. Structural demand model

Separate total consumption into population and consumption intensity:

$$
Q_{it}=P_{it}^{\mathrm{adult}}q_{it}
$$

where $Q_{it}$ is total beverage consumption, $P_{it}^{\mathrm{adult}}$ is adult population, and $q_{it}$ is liters consumed per adult in country $i$ and year $t$.

A parsimonious initial panel specification is:

$$
\ln q_{it}=\alpha_i+f(\ln Y_{it})+\beta_P\ln R_{it}+\gamma_i t+u_{it}
$$

where $Y_{it}$ is real income per adult (preferably PPP-adjusted), $R_{it}$ is relative beverage price where available, $\alpha_i$ represents persistent country differences, $\gamma_i$ represents secular trends, and $u_{it}$ captures residual deviations. Income and price projections must be available for the forecast horizon. When relative price is unavailable, omit it explicitly and evaluate the resulting model separately.

### Nonlinear income response

An initial option is:

$$
f(\ln Y)=\beta_1\ln Y+\beta_2(\ln Y)^2
$$

with income elasticity:

$$
\eta_Y=\beta_1+2\beta_2\ln Y
$$

This allows income elasticity to decrease as countries become wealthier. However, quadratic extrapolation can become implausible beyond the observed range. Compare it with a restricted spline or saturating demand curve. Estimate separate relationships for beer and other beverage categories.

### Autoregressive adjustment

A simple residual model is:

$$
u_{it}=\phi u_{i,t-1}+\varepsilon_{it},\qquad |\phi|<1
$$

which gives the illustrative forecast:

$$
\widehat{\ln q}_{i,T+h}=\hat\alpha_i+\hat f(\ln Y_{i,T+h})+\hat\beta_P\ln R_{i,T+h}+\hat\gamma_i(T+h)+\hat\phi^h\hat u_{iT}
$$

for $h=1,\ldots,5$. Start with a pooled autoregressive parameter rather than estimating 100 separate parameters from short histories. Ideally estimate the structural and residual processes jointly. Country-specific trends should be tested cautiously because they can absorb income effects; partially pooled regional or country trends are a useful alternative.

Inverse-transforming a predicted log level yields a conditional median, not generally the expected level. Use simulation or a suitable bias adjustment when forecasts must represent expected liters.

## 3. Use the 60-year dataset as a research laboratory

The longer history enables investigations that are difficult with a 20-year panel:

1. **Long-run income response:** Is the demand–income relationship nonlinear, and does it vary by beverage category?
2. **Secular shifts:** How much change reflects demographics, preferences, regulation, or substitution rather than income?
3. **Persistence:** How quickly do departures from structural demand dissipate?
4. **Structural breaks:** Have income responses or secular trends changed between historical and contemporary periods?
5. **Forecast accuracy:** Which models work best at horizons of one through five years?

The 60-year data should not automatically dominate estimation. Older observations may reflect different consumer behavior, product availability, regulation, and measurement conventions. Compare full-history, recent-history, and recency-weighted specifications.

## 4. A historical-window experiment

Use the long dataset to emulate forecasts built from progressively shorter historical windows:

| Estimation window | Interpretation | Role |
|---|---|---|
| 3 years | Typical client data availability | Anchor current level; borrow structural parameters from broader data |
| 10 years | Intermediate history | Test gains from additional observations |
| 20 years | Contemporary country panel | Estimate modern relationships |
| 40 years | Long-history comparison | Test stability and long-run information |

At each historical forecast origin, train the model using only observations and predictor information available at that date, then predict the next five years. Repeat across origins and countries.

**Important:** Three years are insufficient to estimate a rich model independently. In the three-year case, estimate common structural parameters from an external historical panel available at the forecast origin, and use the client's observations to calibrate the level and perhaps a limited local adjustment.

Plot five-year forecast error against the number of years of estimation history. This will show whether additional history yields meaningful gains and whether the gains level off.

## 5. Models to compare

| Model | Function | Main concern |
|---|---|---|
| Country-level ARIMA | Conventional time-series benchmark | Short country histories; weak structural guidance |
| Nonlinear fixed-effects panel | Common income curve and country intercepts | Cross-country heterogeneity and extrapolation |
| Nonlinear panel + AR(1) errors | Structural trajectory plus transitional adjustment | Requires careful dynamic estimation |
| Partially pooled country-trend model | Flexible secular changes without unrestricted trends | Greater complexity |
| Panel error-correction model | Gradual adjustment toward long-run demand | Long-run equilibrium must be credible |

An error-correction alternative is:

$$
\Delta\ln q_{it}=\kappa_i\left(\ln q^*_{i,t-1}-\ln q_{i,t-1}\right)+\theta_i\Delta\ln Y_{it}+\varepsilon_{it}
$$

where $q^*_{it}$ is structural equilibrium demand and $\kappa_i>0$ is the adjustment speed. This specification should be used only when the equilibrium relationship is economically and statistically defensible.

## 6. Validation design

Use rolling-origin five-year holdouts. For the 20-year sample, illustrative origins are years 12 through 15, each followed by five years of evaluation. The 60-year sample permits many more origins and stronger tests of model stability.

Measure:

- Forecast error separately for horizons 1, 2, 3, 4, and 5 years.
- Terminal-year volume error and five-year cumulative growth error.
- Country-level bias and differences across mature and emerging markets.
- Unweighted and volume-weighted performance, so large markets do not obscure smaller ones.
- Prediction-interval coverage, when probabilistic forecasts are produced.

Include naive benchmarks such as unchanged per-adult consumption and constant historical growth. Compare models using identical origins and information sets. Distinguish **conditional demand-model accuracy** (using realized future drivers) from **operational accuracy** (using forecasts of income, population, and prices). Only the latter measures the complete forecasting system.

To prevent look-ahead bias, neither the final model specification nor its estimated parameters should be informed by observations later than the historical forecast origin. Model selection can use nested historical validation or a genuinely held-out final period.

## 7. Research, calibration, and commercial application

| Layer | Primary data | Objective |
|---|---|---|
| Research | 60-year historical panel | Identify structural patterns, test alternatives, assess breaks and long-horizon accuracy |
| Contemporary calibration | 100 countries × 20 years | Estimate current demand relationships and dynamic adjustments |
| Commercial application | Client's 3–5 years | Anchor market level and recent changes using externally estimated structural relationships |

The distinction is crucial: **a commercial forecast based on three years of client observations need not rely on only three years of economic information.** Long-run relationships can be embedded in the model through pooled estimation, shrinkage, or informative priors. Their transferability to a new client and market must be tested.

## 8. Proposed first experiment

Test the following hypothesis:

> A nonlinear panel demand model developed and validated with long historical data can outperform country-specific ARIMA forecasts when operational forecasts are produced from a 20-year country panel.

Begin with beer, using per-adult volume and real PPP income per adult. Compare a nonlinear fixed-effects baseline, its AR(1)-error extension, and country-level ARIMA. Only then add country-specific or partially pooled secular trends, prices, and more elaborate dynamics if five-year out-of-sample performance improves.

The anticipated benefit of the hybrid model is a hypothesis, not a foregone conclusion. The key empirical result will be whether the structural model produces more accurate and more stable five-year forecasts across countries, time periods, and beverage categories.

## Conclusion

The 60-year panel is a strategic research asset, even if clients prefer recent data. It can reveal how much historical information five-year forecasting actually requires and which structural relationships survive changes in consumer behavior. The 20-year panel can then serve as the practical estimation environment, while three-year client datasets anchor market-specific applications.

The recommended starting point is **nonlinear panel demand estimation with parsimonious autoregressive adjustment**, benchmarked rigorously against ARIMA and naive forecasts.

## 9. Handling COVID-19 in beverage-demand forecasting

The COVID-19 pandemic introduced exceptional disturbances in 2020, 2021, and, in some markets, 2022. These observations can distort estimates of income elasticities, secular trends, and autoregressive persistence. The impact also differed across countries, beverage categories, and on-premise versus off-premise channels. The forecasting problem is to distinguish a temporary deviation from underlying demand from a persistent change in consumption behavior.

### 9.1. Alternative treatments

| Method | Interpretation | Main consideration |
|---|---|---|
| Year dummies | Separate average effects for 2020–2022 | Transparent baseline, but imposes common timing unless interactions are added |
| Intervention with decay | Temporary shock that gradually dissipates | Parsimonious, but a single monotonic decay may not describe all countries |
| Downweighting or robust estimation | Limit the influence of exceptional observations | Useful complement; does not itself distinguish structural change from temporary shock |
| Treat affected observations as missing | Estimate a counterfactual underlying demand path | Useful benchmark, but can overlook permanent shifts |
| Temporary shock plus level shift | Allow both recovery and lasting change | Flexible, but hard to identify with limited post-pandemic data |

### 9.2. Temporary intervention model

Extend the structural panel model with a pandemic intervention:

$$
\ln q_{it}=\alpha_i+f(\ln Y_{it})+\gamma_i t+\delta_i C_t+u_{it}.
$$

A simple decaying intervention is:

$$
C_t=\begin{cases}
0, & t<2020,\\
1, & t=2020,\\
\rho C_{t-1}, & t>2020,
\end{cases}
\qquad 0\leq\rho<1.
$$

With $\rho=0.5$, the intervention retains 100% of its initial magnitude in 2020, 50% in 2021, 25% in 2022, and 12.5% in 2023. This is illustrative, not an assumed empirical pattern. The peak may occur later than 2020, and the effects may reverse sign. More flexible pulse interventions or beverage-specific timing may therefore be warranted.

For a panel with only 20 annual observations per country, estimate a common or partially pooled decay parameter rather than a separate unconstrained decay process for every country.

### 9.3. Allowing for permanent changes

A combined temporary-and-permanent specification is:

$$
\ln q_{it}=\alpha_i+f(\ln Y_{it})+\gamma_i t
+\delta_i C_t+\psi_i S_t+u_{it},
$$

where $S_t=0$ before 2020 and $S_t=1$ from 2020 onward. Here $\delta_i$ captures the transitory effect and $\psi_i$ a lasting level shift. Because a slow recovery can resemble a permanent break, the two effects should be estimated conservatively, with partial pooling and sensitivity analysis. A post-pandemic change in slope could also be tested, but adds further identification demands.

### 9.4. Exclusion and robust estimation as benchmarks

A practical alternative is to treat 2020–2022 as missing **for estimation of the normal-demand trajectory**, while retaining actual observations for validation and reporting. A state-space smoother can estimate a counterfactual path through the affected years. This should not be interpreted as evidence that COVID had no permanent effects.

Robust regression or explicit lower weights for affected observations offers a middle ground:

$$
\min_{\theta}\sum_{i,t}w_{it}
\left[\ln q_{it}-\widehat{\ln q}_{it}(\theta)\right]^2.
$$

Because COVID was a systematic shock rather than merely random outliers, robust estimation is best used alongside an explicit intervention or exclusion strategy.

### 9.5. Proposed empirical comparison

Using the 60-year research panel, compare three approaches under the same underlying demand specification:

1. **A — Dummies:** The existing 2020–2022 dummy-variable approach.
2. **B — Exclusion:** Omit pandemic-affected observations when estimating the structural trajectory.
3. **C — Intervention:** Estimate a decaying temporary effect, optionally with a permanent level shift.

Assess how each approach reconstructs the underlying trend and predicts post-pandemic demand, particularly 2023–2025. Where the data permit, test the same methods on earlier major disruptions using genuine rolling-origin forecasts. Avoid choosing the smoothest fitted trend merely because it looks plausible: compare terminal-year forecast errors, five-year cumulative growth errors, bias, and market-volume-weighted performance. When using 2023–2025 to evaluate a method, do not use those observations to fit that method's forecast at the evaluation origin.

**Recommendation:** Retain the year-dummy specification as a benchmark. Test exclusion as the simplest alternative and a pooled intervention model as the leading candidate. Permit lasting level changes where supported by the post-pandemic data, rather than forcing all countries and beverage categories back to their pre-2020 trajectories.
