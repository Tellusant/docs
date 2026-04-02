---
title: "Combining Judgmental and Mechanical Predictive Models: The PoluSim P Controller Logic"
description: "Adding expert judgment to models improves their accuracy. We discuss how to do this the best way."
image: /assets/social-card-pub.png
---
# Combining Judgmental and Mechanical Predictive Models: The PoluSim P Controller Logic

Adding expert judgment to models improves their accuracy. We discuss how to do this the best way. What you here is how PoluSim, our strategic forecasting solution, works.

Several authorities have found that mechanical (statistical) forecasts benefit from adding expert judgment as an overlay. This what we allow in Polusim. There are two ways this can be done: 
- Should the judgmental forecast be made independently of the mechanical forecast, and then merged?
- Should the experts benefit from having the mechanical forecast as a base, and then form thir judgment?

We have chosen the second method. Experts should have all tools at their disposable: senior executives, colleagues, AI, market reports, and the PoluSim forecast.

The diagram below shows how this by applying control theory to the logical solution. What you see is a formal way to describe the system we use.

The graph looks reasonable, but isn't. A negative feedback loop should be added in a formally correct manner.
<p align="center">
<img  src="assets/images/tellusant-judgmental-mechanical-predictive-model.svg" width="300" alt="JM">
</p>

Happily, the correct diagram is now in place. It strictly follows the logic and conventions of time-discrete control theory.

---
<div style="max-width: 450px; margin: 0 auto;">
<div class="mermaid">
  
flowchart TD

%%{init: {'themeVariables': { 'fontFamily': 'Arial'}}}%%
%% ===== Inputs =====
D1["`**Demand (t−1)**`"]:::mixed
X["`**Independent Variables**<br/>(Forecasted Externally / Exogenous)`"]:::mixed

%% ===== Baseline model =====
M["`**Plant Model**<br/>(Statistical)`"]:::strong
S["`**Statistical Forecast (t)**`"]:::strong

%% ===== Judgment and correction =====
J["`**Judgmental Overlay**`"]:::strong
Sum((Σ))
K["`**Gain K**`"]
F["`**Final Forecast (t)**`"]:::strong

%% ===== Realized demand =====
R["`**Realized Demand (t)**`"]:::mixed

%% ===== Error and delay =====
E["`**Error e(t)**<br/>= Forecast(t) − Demand(t)`"]:::neutral
Delay["`**z⁻¹**`"]:::neutral

%% ===== Forward path =====
D1 --> M
X -->|given| M
M --> S
S --> J
J -->|&nbsp;+&nbsp;| Sum
Sum --> F

%% ===== Error computation =====
F --> E
R --> E

%% ===== Feedback =====
E --> Delay
Delay --> K
K -->|−<br/>Neg. feedback loop| Sum

%% ========= STYLES =========
classDef strong  fill:#E8F5E9,stroke:#1B5E20,stroke-width:2px,color:#111;
classDef neutral fill:#E3F2FD,stroke:#0D47A1,stroke-width:2px,color:#111;
classDef mixed   fill:#FFF8E1,stroke:#FF6F00,stroke-width:2px,color:#111;
classDef risk    fill:#FDECEA,stroke:#B71C1C,stroke-width:2px,color:#111;
classDef summary fill:#F5F5F5,stroke:#424242,stroke-width:2px,color:#111;

</div>
</div>

---

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

%% ===== Management layer =====
MD["Management Decisions"]

%% ===== Real-world process =====
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

%% ===== Management use =====
F --> MD

%% ===== Exogenous realization =====
P --> R

%% ===== Error computation =====
F --> E
R --> E

%% ===== Feedback =====
E --> Delay
Delay --> K
K -->|−| Sum

</div>
</div>

---
$$\begin{align}
x_t &= \text{externally forecast independent variables} \\[4pt]

\hat d^{\,S}_t &= f(d_{t-1}, x_t) 
&& \text{(statistical / plant model)} \\[6pt]

\hat d_t &= \hat d^{\,S}_t + j_t - K e_{t-1} 
&& \text{(final forecast with judgment and correction)} \\[6pt]

e_t &= \hat d_t - d_t 
&& \text{(forecast error / bias)} \\[6pt]

m_t &= g(\hat d_t) 
&& \text{(management decisions)} \\[6pt]

d_t &= h(d_{t-1}, x_t, \varepsilon_t) 
&& \text{(true demand / plant)}
\end{align}$$

---
[See our collection of thought pieces on predictive model theory](predictive-modeling-collection.md)  

[Find more articles and posts](index.md)
