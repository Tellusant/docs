# Corporate Operating Risk Framework – Summary

## 1. Objective
Measure corporate operating risk using publicly available data by combining:
- Revenue growth volatility (YoY)
- Cost structure dynamics
- Shock vs persistence decomposition (AR model)

---

## 2. Core Definitions

### Quarterly log growth
$$
x_t = \log R_t - \log R_{t-1}
$$

### Year-over-year (YoY) growth
$$
y_t = \log R_t - \log R_{t-4}
$$

Relationship: $y_t = x_t + x_{t-1} + x_{t-2} + x_{t-3}$

---

## 3. Volatility Measure

Primary operating risk measure: $\sigma_{\text{YoY}} = \text{StdDev}(y_t)$

---

## 4. Möbius Transformation

$$f(x) = \frac{x}{x + 2}$$

General form: $f_k(x) = \frac{x}{x + k}, \quad k > 1$

---

## 5. AR(1) Model

$$
x_t = \phi x_{t-1} + \epsilon_t
$$

---

## 6. Closed-Form Link

$$
\sigma_x^2 = \frac{\sigma_\epsilon^2}{1 - \phi^2}
$$

$$
\operatorname{Var}(y_t) =
\frac{\sigma_\epsilon^2}{1-\phi^2}
\left(4 + 6\phi + 4\phi^2 + 2\phi^3 \right)
$$

$$
\sigma_{\text{YoY}} =
\sigma_\epsilon
\sqrt{
\frac{4 + 6\phi + 4\phi^2 + 2\phi^3}{1-\phi^2}
}
$$

---

## 7. Interpretation

- $\phi > 0$: persistence  
- $\phi \approx 0$: shocks dominate  
- $\phi < 0$: reversal  

---

## 8. Example Insight

For $\phi \approx 0: \sigma_{\text{YoY}} \approx 2\sigma_\epsilon$

---

## 9. Cost–Revenue Interaction

$$
E = \frac{\Delta \text{Cost}}{\Delta \text{Revenue}}
$$

$$
\rho = \text{Corr}(\Delta R, \Delta C)
$$

---

## 10. Final Structure

Operating Risk =
- YoY volatility  
- Shock volatility  
- Persistence  
- Cost flexibility  

---

## 11. Stata Implementation

```stata
gen lrev = log(revenue)
gen x = D.lrev

arima x, ar(1)

scalar phi = _b[ARMA:L1.ar]

predict eps, resid
summ eps
scalar sigma_eps = r(sd)
```

