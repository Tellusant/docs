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
