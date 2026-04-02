# Shock Elasticities

## Overview
In economic modeling, **short-term elasticity** differs significantly from steady-state figures. A "shock"—whether a sudden price spike or a recessionary income drop—forces a transition from habitual behavior to active adaptation. This document summarizes how to conceptualize these shifts and the risks associated with adjusting elasticity coefficients during uncertainty.

---

## 1. The Mechanics of a Short-Term Shock
During the immediate onset of a shock, demand is typically **less elastic** than in the long run. This is driven by three primary factors:

* **Behavioral Inertia:** Habits and existing contracts prevent immediate changes in consumption.
* **Infrastructure Constraints:** Physical limitations (e.g., owning a specific car or living a certain distance from work) lock consumers into spending patterns.
* **The Adjustment Lag:** It takes time for consumers to identify substitutes or change lifestyle patterns.

## 2. Income Elasticity (YED) Benchmarks
The impact of a recession is measured by how sensitive a category is to changes in consumer income.

| Good Type | Steady-State YED | Response to Income Shock |
| :--- | :--- | :--- |
| **Necessities** | 0.0 to 0.5 | Spending is protected; cuts are minimal. |
| **Normal Goods** | 0.5 to 1.5 | Spending fluctuates in tandem with the economy. |
| **Luxuries/Durables** | > 1.5 | Spending is highly volatile; often the first to be cut. |
| **Inferior Goods** | < 0.0 | Demand increases as consumers "trade down." |

---

## 3. Analysis of the "Unitary Elasticity" (1.0) Assumption
You proposed shifting a category from a steady-state **0.2** to a shock-state **1.0**. 

### The Rationale
* **Neutrality:** When specific data is unavailable, 1.0 serves as a "societal average" or a mathematical middle ground.
* **The Principle of Insufficient Reason:** If there is no evidence to suggest a specific direction, assuming the category mirrors the overall economy is a defensible placeholder.

### The Risks
> **Warning:** Moving from 0.2 to 1.0 is a 5x increase in sensitivity. 

* **Over-Correction:** If a category is fundamentally a necessity (0.2), it is unlikely to behave like a normal good (1.0) even in a shock. This may lead to an **overly pessimistic revenue forecast**.
* **Identity Shift:** Setting YED to 1.0 assumes the product's "budget share" remains constant, ignoring the fact that consumers usually prioritize low-elasticity goods when budgets tighten.

> The category has low elasticity, but is not a necessity, so the objection does not hold fully.

---

## 4. Strategic Recommendations
To improve model robustness, consider the following:

* **Sensitivity Analysis:** Rather than a single point (1.0), run scenarios at 0.4, 0.7, and 1.0.
* **Sector Benchmarking:** Use the average elasticity of the specific sector (e.g., CPG, Tech, or Utilities) rather than the total societal average.
* **Time-Phased Modeling:** Apply a higher elasticity for the peak of the shock, but decay it back toward the steady-state 0.2 as "new normals" are established.

---
**Key Takeaway:** While 1.0 is a convenient "best guess," it fundamentally changes the nature of the product from a necessity to a discretionary item. Ensure your strategy can withstand the volatility this assumption introduces.
"""
