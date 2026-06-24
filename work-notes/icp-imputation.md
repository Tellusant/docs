# World Bank ICP Imputation Methodology: A Summary

This document outlines the framework used by the World Bank’s International Comparison Program (ICP) to estimate Purchasing Power Parities (PPPs) and Price Level Indices (PLIs) for economies that do not participate in regional price survey collection cycles.

---

## 1. Estimation Framework

The ICP framework relies on **Seemingly Unrelated Regression (SUR)**. This method is preferred over ordinary least squares (OLS) because it estimates a system of equations simultaneously, accounting for the reality that unobserved errors across different national price indices are highly correlated.

### Primary Regression System
The system estimates three interdependent macroeconomic price levels jointly:
1. **Gross Domestic Product PLI** ($\text{PLI}_{\text{GDP}}$)
2. **Individual Consumption Expenditure by Households PLI** ($\text{PLI}_{\text{HHC}}$)
3. **Actual Individual Consumption PLI** ($\text{PLI}_{\text{AIC}}$)

### Equation Specification
For any country $i$, variables are normalized and modeled relative to the base country (the United States):

$$\ln(\text{PLI}_{i}) - \ln(\text{PLI}_{\text{USA}}) = \beta (X_{i} - X_{\text{USA}}) + \epsilon_{i}$$

Because $\text{PLI}_{\text{USA}} = 100$, the left-hand side reduces to the log of the country's price level.

---

## 2. Model Covariates ($X$)

The predictor vector ($X$) balances structural, demographic, and openness indicators known to drive systemic variations in price levels (the Balassa-Samuelson effect).

### Macroeconomic & Structural Indicators
* **GDP Per Capita**: Measured in USD via market exchange rates.
* **Trade Openness (Imports)**: Total imports expressed as a share of domestic GDP.
* **Trade Openness (Exports)**: Total exports expressed as a share of domestic GDP.

### Demographic Shifts
* **Age-Dependency Ratio**: The ratio of dependents (populations under 15 and over 64) to the working-age population (ages 15–64).

### Regional & Geographical Dummy Controls
* Binary indicators for **Sub-Saharan African** economies.
* Binary indicators for **Eurostat-OECD PPP Programme** economies.
* Structural flags for geography: **Island** economies and **Landlocked** economies.
* Interaction terms between regional dummies and market-exchange-rate-based GDP.

---

## 3. Stata Implementation Syntax

The standard routine to estimate parameters on participating countries and project them onto non-covered countries:

```stata
* 1. Macro containing all explanatory covariates
local covariates ln_gdp_pc imports_gdp exports_gdp age_dependency dummy_africa dummy_island dummy_landlocked

* 2. Run system-wide SUR on participating nations
sureg (ln_pli_gdp `covariates') ///
      (ln_pli_hhc `covariates') ///
      (ln_pli_aic `covariates') if participating == 1

* 3. Impute log values for non-covered nations 
predict imputed_gdp if participating == 0, equation(ln_pli_gdp)
predict imputed_hhc if participating == 0, equation(ln_pli_hhc)
predict imputed_aic if participating == 0, equation(ln_pli_aic)

* 4. Exponentiate back to standard PLI scale
gen pli_gdp_final = exp(imputed_gdp)
```
This is the basis for our impuation of missing countries, but can also be used to estimate all countries. Note that te log transformation is not good enough. We have better, proprietary, way to do this.

---

## 4. Key Methodological Diagnostics

* **Breusch-Pagan Test**: Executed automatically by `sureg` to confirm that residual correlation across the three components is non-zero, validating SUR over independent OLS models.
* **Cross-Equation Parameter Constraints**: If needed, coefficients for specific variables (such as the age-dependency ratio) can be constrained to be equal across the consumption dimensions (`hhc` and `aic`) to preserve economic consistency.
