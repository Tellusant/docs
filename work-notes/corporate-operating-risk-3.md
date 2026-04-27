# Corporate Operating Risk Model — Extended Notes

## 1. Objective

The objective is to develop a firm-level measure of **corporate operating risk** that is analogous in spirit to financial beta, but based on operating fundamentals rather than stock-price movements.

The intended measure should be:

- general across businesses,
- based on publicly available data,
- grounded in robust theory,
- comparable across firms,
- decomposable into interpretable components.

The working idea is that a firm's operating risk reflects the instability, persistence, cyclicality, and cost-response structure of its core business engine.

A useful conceptual framing is:

$$
\text{Operating Risk} = \text{Systematic Operating Exposure} + \text{Idiosyncratic Operating Volatility} + \text{Structural Amplification}
$$

This mirrors the logic of financial risk models, but replaces market-price sensitivity with operating-data sensitivity.

---

## 2. Relation to Financial Beta

Financial beta is usually defined as:

$$
\beta_i = \frac{\operatorname{Cov}(r_i, r_m)}{\operatorname{Var}(r_m)}
$$

where:

- $r_i$ is the return of firm $i$,
- $r_m$ is the market return.

The analogy for operating risk is to define an operating beta as the sensitivity of firm-level operating growth to a macroeconomic or global activity factor:

$$
\beta_{\text{op},i} = \frac{\operatorname{Cov}(g_i, g_{\text{macro}})}{\operatorname{Var}(g_{\text{macro}})}
$$

or equivalently from the regression:

$$
g_{i,t} = \alpha_i + \beta_{\text{op},i} g_{\text{macro},t} + \epsilon_{i,t}
$$

where:

- $g_{i,t}$ is operating growth for firm $i$,
- $g_{\text{macro},t}$ is macroeconomic growth,
- $\beta_{\text{op},i}$ is the firm's operating beta,
- $\epsilon_{i,t}$ is idiosyncratic operating variation.

This gives a direct conceptual analog to market beta.

However, operating risk is richer than financial beta because it can also incorporate:

- revenue volatility,
- cost volatility,
- cost/revenue elasticity,
- margin volatility,
- shock persistence,
- downside asymmetry,
- regime instability.

Thus, the best design is likely:

1. one headline operating beta or operating risk score, and
2. a decomposition underneath.

---

## 3. Available Public Data

The current working data structure is a long Stata table with variables:

| Variable | Meaning |
|---|---|
| `no` | company number |
| `q` | quarter |
| `series` | operating series, e.g. `rev` or `opcost` |
| `val` | level value |
| `lval` | log value |

Each company has two series:

- revenue,
- operating cost.

With 40 companies and 2 series per company, there are 80 panel series.

---

## 4. Time-Series Setup in Stata

Because the data are long by company and series, each company-series pair should be treated as a separate panel.

```stata
* Confirm that each company-series-quarter is unique
isid no series q, sort

* If q is already a Stata quarterly date
format q %tq

* Create one panel ID for each company x series pair
egen panelid = group(no series), label

* Declare panel time series
tsset panelid q, quarterly
```

The key point is that `panelid` represents each unique operating time series:

$$
\text{panelid} = (\text{company}, \text{series})
$$

Thus, with 40 companies and two series, the expected number of panels is:

$$
40 \times 2 = 80
$$

---

## 5. Handling Gaps

Stata's `tsfilter hp` requires the time series to be free of gaps within each panel.

Different starting quarters across companies are not necessarily a problem. The problem is missing quarters **inside** a company's observed span.

Useful diagnostics:

```stata
tsreport, panel
```

If there are missing time periods, one can use:

```stata
tsfill
```

But if `lval` itself is missing in the middle of a panel, the missing value must be handled. In the actual case, there were two missing middle values. Once these were fixed, the HP filter worked without looping.

---

## 6. HP Filtering / Detrending

The goal is to remove trend from log operating values before calculating growth volatility.

For log value:

$$
l_{i,t} = \log(V_{i,t})
$$

HP filtering decomposes this into trend and cycle:

$$
l_{i,t} = \tau_{i,t} + c_{i,t}
$$

where:

- $\tau_{i,t}$ is the smooth trend,
- $c_{i,t}$ is the detrended component.

In Stata:

```stata
* HP filter each panel series
tsfilter hp cycle_lval = lval, trend(trend_lval) smooth(1600)

* Rename conceptually if desired
gen lval_detrended = cycle_lval
label var lval_detrended "HP-detrended log value"
```

For quarterly data, the conventional HP smoothing parameter is:

$$
\lambda = 1600
$$

---

## 7. Visual Inspection of HP Fit

It is important to visually inspect the original log series and the HP trend.

For one panel:

```stata
twoway (line trend_lval q) (line lval q) if panelid == 8
```

A loop over all panels with a one-second pause:

```stata
levelsof panelid, local(panels)

foreach p of local panels {

    graph drop _all

    twoway ///
        (line trend_lval q) ///
        (line lval q) ///
        if panelid == `p', ///
        title("Panel `p'") ///
        legend(order(1 "Trend" 2 "Actual"))

    sleep 1000
}
```

To show company and series rather than panel ID:

```stata
levelsof panelid, local(panels)

foreach p of local panels {

    levelsof no if panelid == `p', local(comp)
    levelsof series if panelid == `p', local(s)

    graph drop _all

    twoway ///
        (line trend_lval q) ///
        (line lval q) ///
        if panelid == `p', ///
        title("Company `comp' - `s'") ///
        legend(order(1 "Trend" 2 "Actual"))

    sleep 1000
}
```

To stop the loop manually, the Lenovo keyboard shortcut that worked was:

```text
Ctrl + Scroll Lock
```

---

## 8. Growth Measurement

The base growth concept is year-over-year log growth:

$$
g_{i,t}^{\log,YoY} = l_{i,t} - l_{i,t-4}
$$

Using detrended log values:

$$
g_{i,t}^{\log,YoY} = c_{i,t} - c_{i,t-4}
$$

In Stata:

```stata
gen g_log_yoy = D4.cycle_lval
```

Quarter-on-quarter log growth is:

$$
g_{i,t}^{\log,QoQ} = l_{i,t} - l_{i,t-1}
$$

In Stata:

```stata
gen g_log_qoq = D.cycle_lval
```

Year-over-year growth is useful for risk measurement because it reduces seasonality. Quarter-on-quarter growth is cleaner for AR analysis because YoY growth has overlapping observations.

---

## 9. Standard Deviation of Growth

The original operating risk measure is the standard deviation of growth over approximately 40 quarters.

For a given firm-series:

$$
\sigma_i = \operatorname{StdDev}(g_{i,t})
$$

In Stata:

```stata
bysort panelid: egen sd_g_log_yoy = sd(g_log_yoy)
```

This gives the volatility of detrended YoY log growth.

For the core statistical measure, standard deviation should generally be calculated in log space, because log growth is additive and statistically well behaved.

---

## 10. Möbius Transformation

The Möbius transformation used is:

$$
f(x) = \frac{ax+b}{cx+d}
$$

with:

$$
a=1, \quad b=0, \quad c=1, \quad d=2
$$

so:

$$
f(x) = \frac{x}{x+2}
$$

When $x$ is percentage growth, the transformation has attractive properties:

$$
f(0) = 0
$$

$$
f(-1) = -1
$$

and:

$$
x \in [-1, \infty) \quad \Rightarrow \quad f(x) \in [-1,1)
$$

This respects the economic lower bound of revenue growth:

$$
x = -1 \quad \Leftrightarrow \quad -100\% \text{ growth}
$$

The derivative is:

$$
f'(x) = \frac{2}{(x+2)^2}
$$

At zero:

$$
f'(0) = \frac{1}{2}
$$

Thus, near zero, the transform is approximately linear but scaled down. It compresses large positive values and gives greater separation near the negative boundary.

---

## 11. Log Space vs Percentage Space for Möbius

A key clarification is that log growth and percentage growth are related but not identical.

Log growth:

$$
g_t^{\log} = \log(R_t) - \log(R_{t-4})
$$

Percentage growth:

$$
g_t^{\%} = \frac{R_t}{R_{t-4}} - 1
$$

Relationship:

$$
g_t^{\%} = \exp(g_t^{\log}) - 1
$$

If the goal of the Möbius transform is specifically to respect the economic lower bound of $-100\%$, then it is conceptually better to apply Möbius in percentage-growth space:

$$
m_t = \frac{g_t^{\%}}{g_t^{\%}+2}
$$

In Stata:

```stata
* Start from detrended YoY log growth
gen g_log_yoy = D4.cycle_lval

* Convert to percentage growth
gen g_pct_yoy = exp(g_log_yoy) - 1

* Apply Mobius transform
gen g_mob_yoy = g_pct_yoy / (g_pct_yoy + 2)

* Compute standard deviation of transformed growth
bysort panelid: egen sd_g_mob_yoy = sd(g_mob_yoy)
```

The resulting split is:

- log space for estimation and filtering,
- percentage space for economically meaningful Möbius scaling.

---

## 12. Generalized Möbius Family

A more general version is:

$$
f_k(x) = \frac{x}{x+k}, \quad k > 1
$$

The current model uses:

$$
k = 2
$$

Interpretation:

- smaller $k$: stronger curvature,
- larger $k$: more nearly linear,
- $k=2$: balanced choice that maps $-100\%$ growth to $-1$.

---

## 13. AR(1) Persistence and Shock Volatility

To separate persistence from shocks, use an AR(1) model:

$$
g_t = \alpha + \phi g_{t-1} + \epsilon_t
$$

where:

- $\phi$ measures persistence,
- $\epsilon_t$ is the shock component,
- $\sigma(\epsilon_t)$ measures shock volatility.

### Recommended series for AR analysis

Use quarter-on-quarter log growth rather than YoY growth, because YoY growth has overlapping observations that can mechanically distort autocorrelation.

In Stata:

```stata
gen g_log_qoq = D.cycle_lval
arima g_log_qoq, ar(1)
```

Store persistence:

```stata
scalar phi = _b[ARMA:L1.ar]
```

Generate residuals and store shock volatility:

```stata
predict eps, resid
summ eps
scalar sigma_eps = r(sd)
```

Full single-series workflow:

```stata
arima g_log_qoq, ar(1)
scalar phi = _b[ARMA:L1.ar]
predict eps, resid
summ eps
scalar sigma_eps = r(sd)
```

---

## 14. Interpretation of AR(1) Coefficients

The AR(1) coefficient $\phi$ should be interpreted as follows:

| Value of $\phi$ | Interpretation |
|---|---|
| Large positive | persistent growth dynamics |
| Near zero | mostly transitory shocks |
| Large negative | mean-reverting / oscillatory dynamics |

In one Amazon test case, YoY growth produced:

$$
\phi \approx -0.82
$$

This initially suggested strong anti-persistence, but with quarter-on-quarter log growth, the coefficient was approximately:

$$
\phi \approx 0.06
$$

with a modest z-statistic. This suggests that the strongly negative YoY coefficient was mostly caused by overlapping YoY observations rather than true operating anti-persistence.

The practical interpretation is:

- persistence is low,
- shocks are mostly transitory,
- shock volatility is likely more important than persistence for operating risk.

---

## 15. Revenue and Cost Volatility

The model includes both revenue and operating cost volatility.

For revenue:

$$
\sigma_R = \operatorname{StdDev}(g_R)
$$

For operating cost:

$$
\sigma_C = \operatorname{StdDev}(g_C)
$$

In long format:

```stata
bysort no series: egen sd_g = sd(g_mob_yoy)
```

To compare revenue and cost standard deviations across firms, reshape wide:

```stata
reshape wide sd_g, i(no) j(series) string
corr sd_grev sd_gopcost
```

If the variable names become `sd_grev` and `sd_gopcost`, then:

```stata
corr sd_grev sd_gopcost
pwcorr sd_grev sd_gopcost, sig
```

This answers:

> Do firms with more volatile revenue also tend to have more volatile operating costs?

---

## 16. Cost-Revenue Interaction

The more economically interesting relationship is not only whether revenue and cost volatilities are correlated across firms, but whether costs move with revenue within each firm.

A cost elasticity measure is:

$$
E_i = \frac{\Delta C_i}{\Delta R_i}
$$

A correlation-based flexibility measure is:

$$
\rho_i = \operatorname{Corr}(g_{R,i,t}, g_{C,i,t})
$$

Interpretation:

- high correlation: costs move with revenue, indicating flexibility,
- low correlation: costs are rigid, indicating greater operating leverage risk.

In Stata, reshape to wide by company-quarter:

```stata
reshape wide g_mob_yoy, i(no q) j(series) string
```

Then compute firm-level within-company correlations:

```stata
statsby corr=r(rho), by(no): corr g_mob_yoyrev g_mob_yoyopcost
```

This creates one cost-revenue correlation per company.

---

## 17. Downside Risk

Standard deviation treats upside and downside deviations symmetrically. Operating risk may be more concerned with downside moves.

A downside semi-standard deviation is:

$$
\sigma_- = \sqrt{\frac{1}{N_-}\sum_{g_t < \mu}(g_t - \mu)^2}
$$

where:

- $\mu$ is mean growth,
- $N_-$ is the number of observations below the mean.

This captures bad volatility more directly than total volatility.

---

## 18. Volatility of Volatility / Regime Instability

A firm may have the same average volatility as another firm but much less stable volatility over time.

Define rolling volatility:

$$
\sigma_{i,t}^{(k)} = \operatorname{StdDev}(g_{i,t-k+1}, \ldots, g_{i,t})
$$

Then define volatility of volatility:

$$
\operatorname{VoV}_i = \operatorname{StdDev}(\sigma_{i,t}^{(k)})
$$

This captures regime instability:

- stable volatility: more predictable business,
- unstable volatility: possible structural breaks or business model shifts.

---

## 19. Macro / GDP Sensitivity

A clean operating beta can start with US GDP as the macro factor.

Let:

$$
g_{\text{GDP},t} = \log(GDP_t) - \log(GDP_{t-4})
$$

Then estimate:

$$
g_{i,t} = \alpha_i + \beta_{\text{op},i} g_{\text{GDP},t} + \epsilon_{i,t}
$$

In Stata:

```stata
* GDP growth
gen lgdp = log(gdp)
gen g_gdp = D4.lgdp

* Firm-level operating beta
statsby beta=_b[g_gdp], by(no): reg g_firm g_gdp
```

For large global companies, US GDP is an imperfect but practical starting point. Later refinements could use:

- global GDP,
- global industrial production,
- world trade volume,
- firm-specific geographic revenue weights,
- principal component common factors.

The key conceptual point is that the macro factor should represent broad economic activity, not necessarily only US domestic activity.

---

## 20. Systematic vs Idiosyncratic Operating Risk

The GDP regression decomposes operating growth into systematic and idiosyncratic parts:

$$
g_{i,t} = \alpha_i + \beta_{\text{op},i} g_{\text{macro},t} + \epsilon_{i,t}
$$

Systematic operating exposure:

$$
\beta_{\text{op},i}
$$

Systematic operating volatility contribution:

$$
\beta_{\text{op},i} \cdot \sigma(g_{\text{macro}})
$$

Idiosyncratic operating volatility:

$$
\sigma(\epsilon_{i,t})
$$

This is one of the strongest theoretical links to financial beta.

---

## 21. Composite Operating Risk Structure

A full operating risk model can be organized in layers.

### A. Core Uncertainty

- detrended revenue growth volatility,
- idiosyncratic residual volatility.

### B. Systematic Exposure

- GDP or macro activity beta,
- industry or global activity sensitivity.

### C. Operating Leverage / Cost Structure

- cost growth volatility,
- cost-revenue correlation,
- cost elasticity,
- margin volatility.

### D. Downside / Convexity

- downside semi-standard deviation,
- Möbius-transformed volatility,
- gap between raw and transformed volatility.

### E. Stability

- volatility of volatility,
- regime instability,
- structural break indicators.

A possible high-level expression is:

$$
\text{Operating Risk Score}_i = w_1 Z(\sigma_{R,i}) + w_2 Z(\sigma_{\epsilon,i}) + w_3 Z(\beta_{\text{op},i}) + w_4 Z(\text{Cost Rigidity}_i) + w_5 Z(\text{Downside Risk}_i)
$$

where $Z(\cdot)$ denotes cross-sectional standardization.

---

## 22. Where This Kind of Assessment Exists Elsewhere

Pieces of the approach exist in several places.

### Academic finance

Related concepts include:

- operating leverage,
- earnings volatility,
- cash flow volatility,
- firm-level volatility decomposition,
- cyclicality and macro sensitivity.

### Credit analysis

Rating agencies consider:

- revenue stability,
- margin stability,
- cyclicality,
- diversification,
- business risk.

However, these are often qualitative or only coarsely quantified.

### Equity research

Practitioners sometimes use:

- quality factors,
- earnings stability,
- margin volatility,
- revenue consistency.

These tend to be simpler and less structurally decomposed.

### Corporate finance / FP&A

Companies internally model:

- revenue uncertainty,
- cost flexibility,
- scenario stress,
- downside outcomes.

But these are rarely standardized across firms.

---

## 23. What Is Distinctive About This Model

The distinctive element is not any single metric, but the integration of:

1. time-series rigor,
2. operating structure,
3. nonlinear distribution shaping,
4. cross-sectional comparability,
5. systematic/idiosyncratic decomposition.

In other words, the model is not merely a volatility measure. It is closer to a **fundamental operating risk model**.

The closest analogy is:

$$
\text{Financial Beta} \quad \leftrightarrow \quad \text{Operating Beta}
$$

but the operating framework can be richer because it observes the internal mechanics of the firm.

---

## 24. Practical Current Pipeline

A compact working pipeline is:

```stata
* 1. Declare panel structure
isid no series q, sort
format q %tq
egen panelid = group(no series), label
tsset panelid q, quarterly

* 2. HP filter log values
tsfilter hp cycle_lval = lval, trend(trend_lval) smooth(1600)

* 3. YoY detrended log growth
gen g_log_yoy = D4.cycle_lval

* 4. Convert to percentage growth for Mobius
gen g_pct_yoy = exp(g_log_yoy) - 1

* 5. Apply Mobius transform
gen g_mob_yoy = g_pct_yoy / (g_pct_yoy + 2)

* 6. Standard deviation per company-series panel
bysort panelid: egen sd_g_mob_yoy = sd(g_mob_yoy)

* 7. Quarter-on-quarter log growth for AR work
gen g_log_qoq = D.cycle_lval
```

For visual inspection:

```stata
levelsof panelid, local(panels)

foreach p of local panels {

    levelsof no if panelid == `p', local(comp)
    levelsof series if panelid == `p', local(s)

    graph drop _all

    twoway ///
        (line trend_lval q) ///
        (line lval q) ///
        if panelid == `p', ///
        title("Company `comp' - `s'") ///
        legend(order(1 "Trend" 2 "Actual"))

    sleep 1000
}
```

---

## 25. Current Modeling Position

The current state of the model is internally consistent:

- use log space for filtering, AR decomposition, and statistical estimation,
- use percentage-growth space for the Möbius transform,
- use YoY growth for seasonality-resistant operating volatility,
- use QoQ growth for AR persistence and shock decomposition,
- include both revenue and operating cost behavior,
- eventually add macro/GDP sensitivity to form a true operating beta.

The model is moving toward a robust and general measure of operating risk, with a structure analogous to beta but grounded in firm fundamentals.
