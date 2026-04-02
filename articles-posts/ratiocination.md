

# Ratiocination of Tellusant's Judgmental-Mechanical Model

Here is an example of how our models are created for those interested in ratiocination (epistemic strategy): the process of exact thinking.

Several authorities have found that mechanical (statistical) forecasts benefit from adding expert judgment as an overlay. This what we allow in Polusim. There are two systems for how this is done:

1. Should the judgmental forecast be made independently of the mechanical forecast, and then merged?
2. Should the experts benefit from having the mechanical forecast as a base, and then form thir judgment?

We have chosen the second method. 

We started with a graph in an academic journal: Punia (2025):
<p align="center">
<img  src="assets/images/punia.svg" width="700" alt="Punia schematic">
</p>
This graph describes System 1 above. We therefore modified it conceptually to represent System 2.  

The graph looks reasonable, but is not. It lacks scientific rigor. For example, a negative feedback loop should be added in a formally correct manner.
<p align="center">
<img  src="assets/images/tellusant-judgmental-mechanical-predictive-model.svg" width="300" alt="JM">
</p>

We therefore developed a scientific model based on control theory:

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
[See our collection of thought pieces on predictive model theory](predictive-modeling-collection.md)  

[Find more articles and posts](index.md)
