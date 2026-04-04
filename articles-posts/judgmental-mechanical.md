---
title: "Combining Judgmental and Mechanical Predictive Models: The PoluSim P Controller Logic"
description: "Adding expert judgment to models improves their accuracy. We discuss how to do this the best way."
image: /assets/social-card-pub.png
---
# Combining Judgmental and Mechanical Predictive Models: The PoluSim P Controller Logic

Adding expert judgment to models improves their accuracy. We discuss how to do this the best way. What you see here is how PoluSim, our strategic forecasting solution, works.

Several authorities have found that mechanical (statistical) forecasts benefit from adding expert judgment as an overlay. This is what we allow in Polusim. 

There are two systems for how this can be done: 
1. The judgmental forecast is made independently of the mechanical forecast, and they are then merged.
2. The experts benefit from having the mechanical forecast as a base, and then form their judgments, that are superimposed on the mechanical model.

We have chosen the second method. Experts should have all tools at their disposal: senior executives, colleagues, AI, market reports, and the PoluSim forecast when they form their judgments.

The diagram below shows how this is done by applying time-discrete control control theory to the logical solution. What you see is a formal way to describe the system we use.  

For those familiar with control theory, you immediately see a P controller (proportional controller), the simplest and most fundamental type of a negative feedback loop system.
<br/>

<div style="max-width: 600px; margin: 0 auto;">
<div class="mermaid">
  
flowchart TD

%%{init: {'themeVariables': { 'fontFamily': 'Arial'}}}%%
%% ===== Inputs =====
D1["`**Demand (t−1)**`"]:::orange
X["`**Independent Variables**<br/>(Forecasted Externally / Exogenous)`"]:::orange

%% ===== Baseline model =====
M["`**Plant Model**<br/>(Statistical)`"]:::green
S["`**Statistical Forecast (t)**`"]:::green

%% ===== Judgment and correction =====
J["`**Judgmental Overlay**`"]:::green
Sum((⠀Σ⠀)):::base
K["`**Gain K**`"]:::red
F["`**Final Forecast (t)**`"]:::green

%% ===== Realized demand =====
R["`**Realized Demand (t)**`"]:::orange

%% ===== Error and delay =====
E["`**Error e(t)**<br/>= Forecast(t) − Demand(t)`"]:::red
Delay["`**z⁻¹**`"]:::red

%% ===== Management =====
MGT["`**Management Decisions**`"]:::blue

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
K -->|"`⠀**−**⠀<br/>⠀neg. feedback loop⠀`"| Sum

F -.-> MGT
K --> MGT

linkStyle 12 stroke:transparent,stroke-width:0;

%% ========= STYLES =========
classDef green   fill:#E8F5E9,stroke:#1B5E20,stroke-width:2px,color:#111;
classDef blue    fill:#E3F2FD,stroke:#0D47A1,stroke-width:2px,color:#111;
classDef orange  fill:#FFF8E1,stroke:#FF6F00,stroke-width:2px,color:#111;
classDef red     fill:#FDECEA,stroke:#B71C1C,stroke-width:2px,color:#111;
classDef grey    fill:#F5F5F5,stroke:#424242,stroke-width:2px,color:#111;
classDef base    fill:#ECECFF,stroke:#9370DB,stroke-width:2px,color:#111;
classDef clear   fill:transparent,stroke:transparent;

</div>
</div>

Definitions from control theory:  
**Plant** = A real-world process. The term is central to control theory. A plant can be human hearing, a car brake, a large-language model; anything that modifies an input (e.g., a prompt for LLM).  
**Plant model** = An approximation of the plant. Here a statistical analysis.  
**z<sup>−1</sup>** = the time-shift operator, here 1 year, z<sup>−1</sup>(t) = t-1  
**Gain** = The sensitivity to past error (how strongly bias is corrected). Here a factor K, but can be an equation. K is often 1.

---
This diagram can be converted to a set of equations:

$d_t = \text{demand as dependent variable}$

$x_t = \text{externally forecast independent variables}$

$\hat d^S_t = f(d_{t-1}, x_t)$

$\hat d^{\,S}_t = f(d_{t-1}, x_t)  
\qquad \text{(statistical / plant model)}$

$\hat d_t = \hat d^{\,S}_t + j_t - K e_{t-1}  
\qquad \text{(final forecast with judgment and correction)}$

$e_t = \hat d_t - d_t 
\qquad \text{(forecast error / bias)}$

$d_t = h(d_{t-1}, x_t, \varepsilon_t) 
\qquad \text{(true demand / plant)}$

$d_t = h(d_{t-1}, x_t, \varepsilon_t) 
\qquad \text{(true demand / plant)}$

Outside the model:

$m_t = g(\hat d_t) \qquad  \text{(management decisions)}$

Or, expressed with **state-space** logic:

The system can be expressed in a discrete-time state-space form by defining the state as the lagged forecast error, which is the only quantity that carries forward through the feedback loop. Let $s_t \equiv e_{t-1}$ denote the previous period’s error. 

The final forecast at time $t$ combines the statistical plant model, a judgment overlay, and a proportional correction based on this state. The state then updates as the newly realized forecast error once demand becomes known. 

This yields a minimal state-space representation in which the dynamics are driven entirely by the propagation of forecast error, while demand itself remains an exogenous realization of the underlying process.

$$\begin{align}
s_t &\equiv e_{t-1} \\[4pt]
\hat d_t &= f(d_{t-1},x_t) + j_t - K s_t \\[4pt]
s_{t+1} &= \hat d_t - d_t \\[4pt]
m_t &= g(\hat d_t)
\end{align}$$

---
[Ratiocination (epistemic strategy) of the model](ratiocination.md)

---
[See our collection of thought pieces on predictive model theory](predictive-modeling-collection.md)  

[Find more articles and posts](index.md)
