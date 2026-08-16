---
title: "Research on Income Distribution's Explanatory Power on Product Demand"
description: "This proposal shows how we conduct research on income distribtion. It is written to limit scope and avoid runaway exploration."
image: /assets/social-card-pub.png
---
# Research on Income Distribution's Explanatory Power on Product Demand

<a href="{{ site.company_url }}" style="color: black; text-decoration: none;"><i>By Tellusant, Inc.</i>

This proposal shows how we conduct research on, e.g., income distribution. It is written to limit scope and avoid runaway explorations. It is an update on the same research documented in [Canback, S. and F. D'Agnese (2008): *Where in the World Is the Market*](../papers/Canback-D'Agnese-Where-in-the-World-Is-the-Market.pdf).

### Hypotheses

**Hypothesis₁** Using income distribution *instead of* average income increases explainability of demand for consumer goods.

**Hypothesis₂** Using income distribution *together* with average income increases explainability of demand for consumer goods further.

**Hypothesis₃** Nonlinear models perform best.

## Data

Out of 164 product datasets collected, automotive demand for 147 countries was chosen as the first test case. because cars are big ticket items that should respond to income distribution signals.

Income is pulled from TelluBase to match the countries in the automotive dataset.

## Method

Statistical methods where researched and three were settled on.

A. ln(Demand) = f[logit(Income bracket share 1), logit(Income bracket share 2),...]

B. ln(Demand) = f[ln(Income), logit(Income bracket 1), logit(Income bracket 2)...]

C. Refit with income + residualized income bracket (chosen based on A and B)

Income brackets can, e.g., be socioeconomic levels poor, lower, lower-middle, middle, upper-middle, upper.

Later, a nonlinear differential equation (already defined by Tellusant) may be applied if results are promising.

## Validation

We will employ three tests:

1. Goodness of fit (R²)

2. Cross-validation with the LOOCV method

3. Stepwise incremental improvement by adding each income bracket

## Outcome

Results will be reported back as graphs and summary tables. 

If hypotheses are not rejected, continue with other products in an automated fashion. If hypotheses are rejected, abandon.

---
#### Initial findings on 2026-03-18

- In line with 2008 results  
- Best income bracket (IB) is Pop[80-100]  
- Best model includes both income and IB Pop[80-100]  
  - R²: car demand (new reg.) = f(income) => 0.67  
  - **R²: car demand (new reg.) = f(income, IB[Pop 80-100]) => 0.86**  
  - R²: car demand (new reg.) = f(income, IB[DI 80-100]) => 0.84
No other tests done yet.

At this point, hypotheses 2 and 3 (ln and logit used) are not rejected. Hypothesis 1 is neutral because while it has R²=0.83, this conceals an average income effect and exaggerates the independent variables influence.

---
[2026-03-17]  

[Find more articles and posts](index.md)

*AI was not used.*  

