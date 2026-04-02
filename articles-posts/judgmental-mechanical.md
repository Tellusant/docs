---
title: "Combining Judgmental and Mechanical Predictive Models: The PoluSim P Controller Logic"
description: "Adding expert judgment to models improves their accuracy. We discuss how to do this the best way."
image: /assets/social-card-pub.png
---
# Combining Judgmental and Mechanical Predictive Models: The PoluSim P Controller Logic

Adding expert judgment to models improves their accuracy. We discuss how to do this the best way. What you see here is how PoluSim, our strategic forecasting solution, works.

Several authorities have found that mechanical (statistical) forecasts benefit from adding expert judgment as an overlay. This what we allow in Polusim. There are two systems for how this is done: 
1. Should the judgmental forecast be made independently of the mechanical forecast, and then merged?
2. Should the experts benefit from having the mechanical forecast as a base, and then form thir judgment?

We have chosen the second method. Experts should have all tools at their disposal: senior executives, colleagues, AI, market reports, and the PoluSim forecast when they form their judgment.

The diagram below shows how this by applying time-discrete control control theory to the logical solution. What you see is a formal way to describe the system we use. For those familiar with control theory, you immediately see a P controller (proportional), the simplest form of negative feedback loop system.

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
Sum((Σ)):::risk
K["`**Gain K**`"]
F["`**Final Forecast (t)**`"]:::strong

%% ===== Realized demand =====
R["`**Realized Demand (t)**`"]:::mixed

%% ===== Error and delay =====
E["`**Error e(t)**<br/>= Forecast(t) − Demand(t)`"]:::neutral
Delay["`**z⁻¹**`"]:::neutral

%% ===== Forward path =====
D1 --> M
X -->|⠀given⠀| M
M --> S
S --> J
J -->|"`⠀**+**⠀`"| Sum
Sum --> F

%% ===== Error computation =====
F --> E
R --> E

%% ===== Feedback =====
E --> Delay
Delay --> K
K -->|"`⠀**−**⠀<br/>⠀Neg. feedback loop⠀`"| Sum

%% ========= STYLES =========
classDef strong  fill:#E8F5E9,stroke:#1B5E20,stroke-width:2px,color:#111;
classDef neutral fill:#E3F2FD,stroke:#0D47A1,stroke-width:2px,color:#111;
classDef mixed   fill:#FFF8E1,stroke:#FF6F00,stroke-width:2px,color:#111;
classDef risk    fill:#FDECEA,stroke:#B71C1C,stroke-width:2px,color:#111;
classDef summary fill:#F5F5F5,stroke:#424242,stroke-width:2px,color:#111;

</div>
</div>

Definitions from control theory:  
**Plant** = A real-world process. The term is central to control theoty. A plant can be human hearing, a car brake, an AI prompt; anything that modifies an input.  
**Plant model** = An approximation of the plant. Here a statistical analysis.  
**z<sup>−1</sup>** = the time-shift operator, here 1 year, z<sup>−1</sup>(t) = t-1  
**Gain** = The sensitivity to past error (how strongly bias is corrected). Here a factor K, but can be an equation. K is often 1.

---
This diagram can be converted to a set of equations:

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
For those interested in the ratiocination (epistemic strategy) of the model](ratiocination.md)

---
[See our collection of thought pieces on predictive model theory](predictive-modeling-collection.md)  

[Find more articles and posts](index.md)
