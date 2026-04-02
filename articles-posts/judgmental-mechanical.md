---
title: "Combining Judgmental and Mechanical Predictive Models"
description: "Adding expert judgment to models improves their accuracy. We discuss how to do this the best way."
image: /assets/social-card-pub.png
---
# Combining Judgmental and Mechanical Predictive Models

Adding expert judgment to models improves their accuracy. We discuss how to do this the best way.

WIP

The graph looks reasonable, but isn't. A negative feedback loop should be added in a formally correct manner.
<p align="center">
<img  src="assets/images/tellusant-judgmental-mechanical-predictive-model.svg" width="300" alt="JM">
</p>

Happily, the correct diagram is now in place. It stricy=tly follows the logic and conventions of time-discrete control theory.

It just doesn't display yet.

<div style="max-width: 450px; margin: 0 auto;">
<div class="mermaid">
  
flowchart TD

%% ===== Inputs =====
D1["Demand (t−1)"]
X["Independent Variables (Forecasted Externally / Exogenous)"]

%% ===== Baseline model =====
M["Plant Model (Statistical)"]
S["Statistical Forecast (t)"]

%% ===== Judgment and correction =====
J["Judgment Overlay"]
Sum((Σ))
K["Gain K"]
F["Final Forecast (t)"]

%% ===== Plant =====
P["Plant (Market / Reality)"]
R["Realized Demand (t)"]

%% ===== Error and delay =====
E["Error e(t) = Forecast(t) − Demand(t)"]
Delay["z⁻¹"]

%% ===== Forward path =====
D1 --> M
X -->|given| M
M --> S
S --> J
J -->|+| Sum
Sum --> F
F --> P
P --> R

%% ===== Feedback path =====
F --> E
R --> E
E --> Delay
Delay --> K
K -->|−| Sum

</div>
</div>

---
[See our collection of thought pieces on predictive model theory](predictive-modeling-collection.md)  

[Find more articles and posts](index.md)
