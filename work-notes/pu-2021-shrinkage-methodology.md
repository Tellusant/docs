---
title: "PU Ratios: Trendline-Based Compression for Modeling and Forecasting"
date: 2026-10-12
---

# PU Ratios: Trendline-Based Compression for Modeling and Forecasting

## 1. Problem and objective

The **PU ratio** is GDP expressed in purchasing-power-parity dollars divided by GDP expressed in market-exchange-rate US dollars:

$$
PU_i=\frac{GDP_{i,PPP}}{GDP_{i,USD}}.
$$

The country dataset is based on the **2021 World Bank International Comparison Program (ICP)** benchmark. An established regression-based trendline describes the systematic relationship between PU and income measured at market exchange rates. Actual PU ratios can lie far above or below this trendline.

Three alternatives were initially considered:

1. Preserve all observed ICP PU ratios.
2. Replace every observed PU with its predicted trendline value.
3. **Partially compress deviations toward the trendline**, retaining economically meaningful country variation while reducing extreme observations.

The stated objective is **economically plausible PU ratios for subsequent modeling and forecasting**, not a claim to correct errors in ICP statistics. Therefore the original observations should remain unchanged and adjusted PU should be stored as a separate series.

## 2. Why use only the 2021 benchmark?

The 2021 ICP benchmark is used alone. Differences in methodology across 2011, 2017, and 2021 make simple pooling across benchmark rounds potentially problematic. A multi-benchmark persistence model may be revisited later, but is **not part of the current calculation**.

## 3. How the original Stata trendline was constructed

The original Stata do-file contains exploratory GDP and household consumption expenditure (HCE) regressions. For the PU GDP trendline, the relevant procedure is:

1. Work with natural-log GDP per capita in PPP dollars (`lgdpcup_pop`) and market-exchange-rate dollars (`lgdpcuu_pop`). The prefix `l` means natural logarithm.
2. Investigate transformations, including `boxcox` on the logged data.
3. Square the logged PPP GDP per capita:

   ```stata
   gen sqlgdpcup_pop = lgdpcup_pop^2
   ```

4. Regress the squared logged PPP measure on logged market-dollar GDP per capita:

   ```stata
   reg sqlgdpcup_pop lgdpcuu_pop
   predict w
   ```

5. Back-transform the fitted values to a PU ratio:

   ```stata
   gen pu_smoothed = exp(w^.5) / gdpcuu_pop
   ```

Thus, in mathematical notation, if $x_i=\ln(GDP_{i,USD}/Pop_i)$ and $z_i=[\ln(GDP_{i,PPP}/Pop_i)]^2$, the fitted regression is

$$
\widehat z_i=\widehat\alpha+\widehat\beta x_i,
$$

and the corresponding PU trendline is

$$
\widehat{PU}_i=\frac{\exp(\sqrt{\widehat z_i})}{GDP_{i,USD}/Pop_i}.
$$

This back-transformation uses the positive square-root branch and requires nonnegative fitted squared-log values. It is **not** a simple log-PU-on-log-income regression.

### Constrained trendline and US anchor

The do-file then imposes:

```stata
constraint 1 _cons + 11.156427*lgdpcuu_pop = 124.46587
cnsreg sqlgdpcup_pop lgdpcuu_pop, constraints(1)
margins, at(lgdpcuu_pop=11.156427)
```

Since $11.156427^2\approx124.46587$, the constraint is designed to make the predicted logged PPP income equal the logged market-dollar income at the specified US income anchor. Consequently, **the constrained trendline gives PU approximately equal to 1 at that anchor**.

The do-file then contains:

```stata
gen pu_smoothed2 = exp(w2^.5) / gdpcuu_pop
```

The prediction command for `w2` is missing from the saved do-file. The likely omitted command, to run immediately after the constrained regression, is:

```stata
predict w2
```

This should be added and the predictions confirmed in Stata. The constrained fitted series, `pu_smoothed2`, is the preferred economic benchmark for the compression exercise, conditional on that verification.

### Sample

The supplied dataset contains **213 countries and territories**; **192** have the observed values needed for the regression/residual analysis. The remaining 21 can receive trendline predictions if their explanatory variables are available. Verify the estimation sample immediately after each regression with:

```stata
display e(N)
```

## 4. Defining the log residual

For an observed ratio $PU_i$ and constrained fitted ratio $\widehat{PU}_i$:

$$
\boxed{r_i=\ln\left(\frac{PU_i}{\widehat{PU}_i}\right)
=\ln(PU_i)-\ln(\widehat{PU}_i)}
$$

- $r_i=0$: observed and fitted ratios agree.
- $r_i>0$: observed PU is above trend.
- $r_i<0$: observed PU is below trend.

The log form provides **multiplicative symmetry**: twice the trendline corresponds to $+\ln2\approx0.693$, while half the trendline corresponds to $-\ln2\approx-0.693$.

For Afghanistan, the supplied data give approximately:

| Quantity | Value |
|---|---:|
| Actual PU | 6.012 |
| Unconstrained trend PU | 3.387 |
| Constrained trend PU | 3.824 |
| Log residual relative to constrained trend | $\ln(6.012/3.824)\approx0.453$ |

Stata implementation (using the dataset's actual variable names):

```stata
gen log_residual = ln(pu_actual / pu_smoothed2) if pu_actual>0 & pu_smoothed2>0
```

**Important:** This is the log residual of the *PU ratio against the fitted PU trendline*, not the residual from the original regression of squared logged PPP GDP per capita.

## 5. Option A: Linear shrinkage in PU units

A simple partial adjustment is

$$
PU_i^*=\widehat{PU}_i+\lambda(PU_i-\widehat{PU}_i), \qquad 0\le\lambda\le1.
$$

Here $\lambda=1$ retains actual PU, $\lambda=0$ replaces it with the trendline, and $\lambda=0.5$ retains half the arithmetic deviation. With an illustrative actual PU of 6 and trend PU of 3, the midpoint is 4.5.

This is easy to interpret, but arithmetic deviations are less natural for a strictly positive ratio.

## 6. Option B: Geometric (logarithmic) shrinkage

Apply the shrinkage factor to the log residual:

$$
r_i^*=\lambda r_i.
$$

Reconstruct PU:

$$
\boxed{PU_i^*=\widehat{PU}_i\exp(\lambda r_i)
=PU_i^\lambda\widehat{PU}_i^{1-\lambda}}
$$

This is a weighted geometric mean. It preserves positivity and treats proportional upward and downward deviations symmetrically.

For illustrative actual PU 6 and fitted PU 3:

| Retained log deviation $\lambda$ | Linear adjustment | Geometric adjustment |
|---:|---:|---:|
| 0 | 3.00 | 3.00 |
| 0.25 | 3.75 | 3.57 |
| 0.50 | 4.50 | 4.24 |
| 0.75 | 5.25 | 5.05 |
| 1 | 6.00 | 6.00 |

Its limitation is that a constant $\lambda$ compresses **all** deviations by the same fraction, even small and potentially informative ones.

## 7. Option C: Nonlinear compression of extreme residuals (preferred starting point)

The proposed nonlinear transform is

$$
\boxed{r_i^*=c\tanh\left(\frac{r_i}{c}\right),\qquad c>0}
$$

followed by

$$
\boxed{PU_i^*=\widehat{PU}_i\exp(r_i^*)}.
$$

The hyperbolic tangent is

$$
\tanh(x)=\frac{e^x-e^{-x}}{e^x+e^{-x}}.
$$

Key properties:

- Near zero, $r_i^*\approx r_i$: small country deviations are nearly unchanged.
- Large positive or negative deviations are increasingly compressed.
- The transform is odd in log residuals, treating equal and opposite proportional deviations symmetrically.
- $|r_i^*|<c$: it imposes a ceiling on the **absolute adjusted log deviation** (not on the PU level).
- Smaller $c$ means stronger compression.
- If actual PU equals trend PU, the adjustment leaves it unchanged. Hence a US anchor with both values equal to 1 remains at 1.

For illustrative actual PU 6 and fitted PU 3, $r=\ln2$:

| $c$ | Adjusted PU (approx.) |
|---:|---:|
| 0.25 | 3.84 |
| 0.50 | 4.48 |
| 0.75 | 4.85 |
| 1.00 | 5.11 |
| 2.00 | 5.76 |
| No compression | 6.00 |

For the **actual Afghanistan values** in the dataset, the earlier workbook's mild, medium, and strong scenarios yielded approximately **5.708, 5.441, and 5.188**, respectively. These are exploratory settings, not validated optimum parameters.

## 8. Calibrating compression from cross-country dispersion

Instead of setting $c$ solely by judgment, estimate robust dispersion of the observed log residuals. Let

$$
m=\operatorname{median}(r_i)
$$

and

$$
\boxed{s=1.4826\,\operatorname{median}(|r_i-m|)}.
$$

This is the median absolute deviation (MAD), scaled to be comparable to standard deviation for normally distributed data.

Then specify

$$
\boxed{c=ks}
$$

and compare $k=1.5$, $2$, and $3$, for example. In the preliminary 2021 analysis, the robust scale for residuals against the constrained trendline was approximately **$s=0.239$**.

**Caution:** MAD measures cross-country residual dispersion; it does not prove that large residuals are measurement errors. A country with a persistently unusual price structure may have a genuine large deviation.

## 9. Alternative: empirical Bayes shrinkage

A statistical interpretation separates genuine country effects from measurement noise:

$$
\ln(PU_i)=\ln(\widehat{PU}_i)+u_i+\epsilon_i,
$$

where $u_i$ is a true country-specific deviation and $\epsilon_i$ is error. Under independent zero-mean normal assumptions, with variances $\tau^2$ and $\sigma^2$:

$$
\boxed{\lambda=\frac{\tau^2}{\tau^2+\sigma^2}}.
$$

This gives an optimal linear shrinkage coefficient under those assumptions. **A single cross-section of residuals cannot by itself identify $\tau^2$ separately from $\sigma^2$.** Revisions, external accuracy indicators, or comparable panel observations would be needed. Because of comparability concerns across ICP rounds, empirical Bayes was not selected as the immediate operational method.

## 10. Questions for review and diagnostics

Before choosing a final adjusted PU series:

1. **Confirm the constrained predictions:** add `predict w2` after `cnsreg`, rerun the do-file, and check `pu_smoothed2` and the US anchor.
2. **Inspect outliers in both directions:** the preliminary analysis found that Afghanistan is not the most extreme positive proportional deviation; Brunei, Belarus, Russia, and Kazakhstan were more extreme against the constrained trendline.
3. **Check the residual center:** the constrained trendline has a positive median log residual, while the unconstrained version had a slightly negative median. Decide whether to preserve that systematic offset or separately recenter residuals. The proposed transform as written does **not** deliberately recenter them.
4. **Compare adjustment families:** original values, constant geometric shrinkage, and nonlinear compression at several $k$ values.
5. **Test downstream forecasts:** select the method by economic plausibility and out-of-sample performance, not merely by making a visually smooth scatterplot.
6. **Preserve raw ICP data:** store every adjustment as a distinct derived variable with the method and parameter documented.

## 11. Excel implementation

Assume row 2 contains:

- `B2`: actual PU;
- `C2`: constrained trendline PU;
- `$H$2`: compression parameter $c$.

The formulas are:

| Calculation | Excel formula |
|---|---|
| Log residual | `=LN(B2/C2)` |
| Nonlinear compressed residual, with residual in D2 | `=$H$2*TANH(D2/$H$2)` |
| Adjusted PU, with compressed residual in E2 | `=C2*EXP(E2)` |
| Geometric shrinkage, with $\lambda$ in H3 | `=C2*EXP($H$3*D2)` |
| Absolute deviation from median $m$ in H4 | `=ABS(D2-$H$4)` |
| MAD scale from a range of absolute deviations | `=1.4826*MEDIAN(F2:F193)` |
| Compression parameter, $k$ in H5 and $s$ in H6 | `=$H$5*$H$6` |

For a full spreadsheet, use the actual range of the **192 valid residuals**; the row range above is only illustrative. Excel's `TANH` is the hyperbolic tangent function.

The companion workbook supplied during this analysis, `PU_2021_full_formula_calculations.xlsx`, contains the 213-country dataset, both trendlines, residuals, parameter calculations, and alternative compression scenarios with formulas. The trendline predictions originate in Stata rather than being reestimated in Excel.

## 12. Provisional recommendation

**Use the constrained, US-anchored 2021 trendline as the economic benchmark, subject to verifying `w2`; apply nonlinear compression to the PU log residuals; calibrate $c$ using robust cross-country dispersion; and retain the original ICP ratios unchanged.**

This is a proposed forecasting regularization procedure, not an assertion that the resulting values are more accurate ICP measurements. Final parameter selection should follow country-level review and forecast validation.

---

*Prepared for internal discussion, October 12, 2026. Based on the supplied 2021 Stata dataset and do-file and the subsequent compression analysis.*
