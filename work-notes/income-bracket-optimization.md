# Summary of Cross-Sectional Demand Modeling Discussion

## Objective

The discussion began with a methodological question:

> Can differencing be used in cross-sectional statistical analysis?

This evolved into a practical investigation of a cross-country demand model for TVs per capita using income-distribution variables.

---

# 1. Differencing in Cross-Sectional Analysis

## Standard Differencing

Differencing is normally a time-series technique:

$$
\Delta y_t = y_t - y_{t-1}
\$$

Its purpose is to:

- Remove trends
- Achieve stationarity
- Analyze changes over time

Because cross-sectional observations do not possess a natural ordering, ordinary differencing across units is generally not meaningful.

## When Differencing Can Make Sense

Differencing may be useful when:

1. Comparing against a benchmark
2. Comparing matched pairs
3. Using spatial structures
4. Working with panel data

### Benchmark Example

For a country observed in year t:

$$\
y_i - y_{US,t}
\$$

This measures deviation from a reference economy.

---

# 2. Reference-Series Transformation Idea

A proposed idea was:

1. Observe income per capita for countries.
2. Map observations to a reference series (e.g., U.S. income per capita over time).
3. Difference relative to the reference.

This is valid if interpreted as:

> Relative growth or relative position compared with a benchmark.

It does not become ordinary cross-sectional differencing.

---

# 3. TV Demand Problem

The empirical problem involved:

## Dependent Variable

TVs per capita

Typically modeled as:

$$\
\ln(TVpc)
\$$

## Candidate Explanatory Variables

Shares or counts of populations in:

- Lower-middle and above
- Middle and above
- Upper-middle and above

These were cumulative income categories.

Notation introduced:

- LM+ = lower-middle and above
- M+ = middle and above
- UM+ = upper-middle and above

Relationship:

$$
LM+ \ge M+ \ge UM+
\$$

---

# 4. Why the Optimum Appeared Flat

A "flat optimum" emerged when comparing the three variables.

This is expected because the variables are highly collinear.

Example:

$$\
LM+ = M+ + \text{Lower-Middle Only}
\$$

$$\
M+ = UM+ + \text{Middle Only}
\$$

Therefore all three variables carry nearly the same information.

The data may struggle to distinguish among them.

---

# 5. Recommended Decomposition

Convert cumulative classes into exclusive segments:

## Exclusive Segments

Lower-middle only:

$$\
LM_{only}=LM+ - M+
\$$

Middle only:

$$\
M_{only}=M+ - UM+
\$$

Upper-middle and above:

$$\
UM_{plus}=UM+
\$$

Advantages:

- Reduced collinearity
- Clear interpretation
- Better behavioral insights

---

# 6. Counts versus Shares

The data contained both:

- Counts
- Population shares

Because the dependent variable was already per capita:

$$\
TVpc
\$$

shares were generally preferred.

### Why Shares Are Better

Counts introduce country-size effects.

Shares measure purchasing power distribution independently of population size.

---

# 7. Transforming Shares

## Simple Share

Use the raw share directly.

## Log Share

Possible but problematic near zero.

$$\
\ln(s)
\$$

## Logit Share (Recommended)

$$\
\text{logit}(s)=\ln\left(\frac{s}{1-s}\right)
\$$

Advantages:

- Expands the middle region
- Handles bounded variables naturally
- Often linearizes diffusion relationships

---

# 8. Cross-Validation

The discussion introduced cross-validation as a method of model comparison.

## Purpose

Instead of asking:

> Which model fits the observed sample best?

Ask:

> Which model predicts unseen countries best?

---

## K-Fold Cross-Validation

For K = 10:

1. Split 162 countries into 10 folds.
2. Fit the model on 9 folds.
3. Predict the omitted fold.
4. Repeat.
5. Average prediction performance.

Recommended:

- K = 10
- Optionally repeat several times

---

# 9. Cross-Validated R-Squared

Ordinary R-squared:

$$\
R^2 = 1 - \frac{SSE}{SST}
\$$

Cross-validated R-squared:

$$\
R^2_{CV}
=
1-
\frac{\sum (y_i-\hat y_i^{CV})^2}
{\sum(y_i-\bar y)^2}
\$$

where predictions are generated from models that did not use the observation being predicted.

Interpretation:

- Higher is better
- Measures predictive performance
- Penalizes overfitting

---

# 10. Leave-One-Country-Out Cross-Validation (LOOCV)

Because there are only 162 countries, LOOCV is particularly attractive.

Procedure:

1. Remove one country.
2. Estimate on the remaining 161.
3. Predict the omitted country.
4. Repeat 162 times.

Advantages:

- Uses almost all available data
- No randomness in fold assignment
- Reveals influential countries

---

# 11. Nonlinear Specifications

Several nonlinear approaches were considered.

## Splines

$$\
\ln(TVpc)=f(x)+\varepsilon
\$$

Advantages:

- Flexible
- Few assumptions
- Good diagnostic tool

Recommended as the first nonlinear model.

---

## Logistic Models

$$\
TVpc
=
\frac{A}
{1+\exp(-k(\ln GDPpc-c))}
\$$

Interpretation:

- Threshold behavior
- Saturation
- Diffusion dynamics

---

## Threshold Models

Piecewise regressions allow different slopes before and after a threshold.

Useful when adoption accelerates after a certain income level.

---

# 12. Empirical Result

The strongest predictor was found to be:

$$\
\ln(TVpc)
=
\alpha
+
\beta \cdot \text{logit}(UM+)
+
\varepsilon
\$$

where UM+ denotes the share of population in the upper-middle-income-and-above segment.

This specification outperformed alternatives.

---

# 13. Interpretation of the UM+ Result

A key insight emerged:

TV ownership appears to depend more on:

> The proportion of the population able to comfortably afford the product

than on:

> Average national income.

This corresponds to an affordability-threshold model.

---

# 14. Why Income Distribution Can Beat GDP Per Capita

Two countries may have identical GDP per capita but different income distributions.

Example:

Country A:
- Large upper-middle class
- High TV penetration

Country B:
- Small upper-middle class
- Lower TV penetration

GDP per capita cannot distinguish them.

UM+ share can.

---

# 15. Diffusion Interpretation

Durable goods such as:

- TVs
- Refrigerators
- Washing machines
- Cars

often follow S-curve adoption patterns.

The upper-middle share acts as a proxy for:

> Households crossing the affordability threshold.

As this share grows, adoption accelerates.

Eventually saturation occurs.

---

# 16. Testing the Affordability Threshold Hypothesis

Recommended comparison:

## Model 1

$$\
\ln(TVpc)
=
f(\ln GDPpc)
\$$

## Model 2

$$\
\ln(TVpc)
=
\beta \cdot \text{logit}(UM+)
$$

## Model 3

$$\
\ln(TVpc)
=
f(\ln GDPpc)
+
\beta \cdot \text{logit}(UM+)
\$$

Compare using:

- LOOCV
- 10-fold CV
- CV R-squared
- CV RMSE

---

# 17. Residualization Strategy

To separate income effects from distribution effects:

First estimate:

$$\
\text{logit}(UM+)
=
g(\ln GDPpc)
+
u
\$$

Then estimate:

$$\
\ln(TVpc)
=
f(\ln GDPpc)
+
\gamma u
+
\varepsilon
\$$

Interpretation:

If γ remains significant:

> Income distribution contributes beyond average income.

This is strong evidence for a true affordability-threshold effect.

---

# 18. Main Conclusions

1. Differencing is generally not meaningful in pure cross-sectional analysis.
2. Cross-validation is the preferred tool for choosing among competing predictors.
3. LOOCV is highly appropriate for a sample of 162 countries.
4. Shares are preferable to counts when modeling per-capita demand.
5. Logit transformations are often superior to raw shares for bounded variables.
6. The best-performing specification identified was:

$$\
\ln(TVpc)
=
\alpha
+
\beta \cdot \text{logit}(UM+)
+
\varepsilon
\$$

7. This result supports an affordability-threshold interpretation of consumer durable demand.
8. Income distribution may explain adoption better than average income alone.
9. The next recommended step is to compare income-only, UM+-only, and combined models using LOOCV and cross-validated R-squared.
