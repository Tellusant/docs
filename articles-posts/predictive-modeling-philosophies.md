---
title: "Philosophical Stances for Predictive Modeling"
description: "Work-in-progress"
image: /assets/social-card-pub.png
---

# Philosophical Stances for Predictive Modeling

<div style="max-width: 450px; margin: 0 auto;">
<div class="mermaid">
  
flowchart LR

%% ========= NODES =========
P["`1.2<br/>**Predictive Modeling**<br/>**Philosophies**`"]:::none

AW["`1.21<br/>**Approximate<br/>the World**`"]:::strong
AD["`1.22<br/>**Approximate<br/>the Data**`"]:::mixed
PW["`1.23<br/>**Map Possible<br/>Worlds**`"]:::neutral
HA["`1.24<br/>**Let Humans<br/>Arbitrate**`"]:::risk

STR["`1.211<br/>**Structural**<br/>*Only what is modeled<br/>based on theory<br/>can be trusted*`"]:::strong
RED["`1.212<br/>**Reduced-Form**<br/>*Stability is more<br/>valuable than truth*`"]:::strong
STA["`1.213<br/>**State-Space**<br/>*The signal is<br/>never observed<br/>directly*`"]:::strong
EMP["`1.221<br/>**Empirical**<br/>*The data are<br/>the model*`"]:::mixed
SCE["`1.231<br/>**Scenario-Based**<br/>*There is no<br/>single future*`"]:::neutral
JUD["`1.241<br/>**Judgemental**<br/>*The final model<br/>is human*`"]:::risk
BAY["`1.242<br/>**Bayesian Support**<br/>*All forecasts<br/>are probabilities*`"]:::risk

%% ========= RELATIONSHIPS =========
P --> AW
P --> AD
P --> PW
P --> HA
AW --> STR
AW --> RED
AW --> STA
AD --> EMP
PW --> SCE
HA --> JUD
HA --> BAY

%% ========= STYLES =========
classDef strong  fill:#E8F5E9,stroke:#1B5E20,stroke-width:2px,color:#111;
classDef neutral fill:#E3F2FD,stroke:#0D47A1,stroke-width:2px,color:#111;
classDef mixed   fill:#FFF8E1,stroke:#FF6F00,stroke-width:2px,color:#111;
classDef risk    fill:#FDECEA,stroke:#B71C1C,stroke-width:2px,color:#111;
classDef summary fill:#F5F5F5,stroke:#424242,stroke-width:2px,color:#111;
classDef anchor fill:transparent,stroke:transparent;

</div>
</div>

## Structural
The structural stance holds that forecasts are credible only insofar as they reflect the true causal mechanisms of the system being modeled. It requires explicit specification of relationships grounded in theory—economic, physical, or behavioral—and emphasizes interpretability and policy relevance. 

Because it models how the world works rather than how data appear, it is better suited for counterfactual analysis and regime change. Its limitation is that incorrect or incomplete specification can degrade predictive accuracy, especially in the short run.


## Reduced-Form
The reduced-form stance occupies the middle ground, seeking stable empirical relationships without fully specifying the underlying system. It accepts that causal drivers matter—such as price, income, or external conditions—but does not attempt full structural identification. 

The focus is on finding relationships that are empirically robust and practically useful for prediction. This approach often delivers a balance between accuracy and interpretability, though it depends critically on the stability of observed relationships over time.


## State-Space
The state-space stance views observed data as noisy manifestations of underlying latent processes that evolve over time. Forecasting becomes a problem of estimating and projecting these hidden states, typically using recursive filtering methods (e.g., Kalman). 

This framework is well suited for handling time variation, missing information, and real-time updating, making it central to nowcasting and dynamic modeling. Its effectiveness depends on the correct specification of the latent structure and noise processes. It is primarily used in engineering, especially electrical enginering.


## Empirical
The empirical stance treats forecasting as a problem of pattern extraction from data, with validity determined strictly by out-of-sample performance. It makes minimal assumptions about underlying mechanisms and instead relies on the idea that whatever structure exists will be reflected in historical observations. 

Model choice is therefore guided by predictive accuracy rather than interpretability, and techniques range from classical time-series methods to modern machine learning. Its strength lies in adaptability and performance; its weakness is vulnerability when the data-generating process shifts.

## Scenario-Based
The scenario-based stance rejects the idea of a single predicted future and instead constructs multiple conditional futures based on differing assumptions. It is particularly suited to environments characterized by structural uncertainty, policy changes, or rare events.  

Scenarios are not forecasts in a strict statistical sense but structured explorations of possibility spaces, often used for strategic planning. Their value lies in broadening decision-making; their limitation is the absence of probabilistic ranking unless combined with other approaches.  


## Judgemental
The judgmental stance recognizes that not all relevant information can be formalized in data or models and that expert judgment plays an irreducible role in forecasting. It incorporates tacit knowledge, contextual awareness, and qualitative insights, often through adjustments or overrides of model outputs.  

While it introduces risks of bias and inconsistency, it can add value in situations where data are sparse, regimes are shifting, or models systematically miss key factors. In practice, it often complements rather than replaces formal modeling.  


## Bayesian Support




---
[See our collection of thought pieces on predictive model theory](predictive-model-collection.md)  
[Find more articles and posts](index.md)  
