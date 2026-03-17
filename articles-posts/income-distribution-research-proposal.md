---
title: "Research on Income Distribution's Explanatory Power on Product Demand"
description: "This proposal shows how we conduct research on income distribtion. It is written to limit scope and avoid runaway exploration."
image: /assets/social-card-pub.png
---
# Research on Income Distribution's Explanatory Power on Product Demand
This proposal shows how we conduct research on, e.g., income distribution. It is written to limit scope and avoid runaway explorations. It is an update on the same research documented in [Canback, S. and F. D'Agnese (2008): *Where in the World Is the Market](../papers/Canback-D'Agnese-Where-in-the-World-Is-the-Market.pdf).

### Hypotheses

**Hypothesis₁** Using income distribution instead of average income per capita increases explainability of demand for consumer goods.

**Hypothesis₂** Using income distribution together with average income per capita increases explainability of demand for consumer goods further.

**Hypothesis₃** Nonlinear models perform best.

### Data

Out of 164 product datasets collected, automotive demand was chosen as the first test case because it is cars are big ticket items that should respond to income distribution signals.

Income is pulled from TelluBase to match the countries in the automotive dataset.

### Method

Statistical methods where researched and three were settled on.

A. ln(Demand) = f[logit(Income bracket share 1), logit(Income bracket share 2),...]

B. ln(Demand) = f[ln(Income per capita), logit(Income bracket 1), logit(Income bracket 2)...]

C. Refit with income + residualized income bracket (chosen based on A and B)

Income brackets can, e.g., be seen as poor, lower, lower-middle, middle, upper-middle, upper classes.

Later, a nonlinear differential equation (already defined by Tellusant) may be applied if results are promising.

### Validation

We will employ two tests:

1. Regular goodness of fit (R²)

2. Cross-validation with the LOOCV method

3. Stepwise incremental improvement by adding each income bracket

### Results

Results will be reported back as graphs and summary tables. If hypotheses not rejected, continue with other products in a automated fashion. If hypotheses rejected, abandon.

---
₁₂₃
¹²³
