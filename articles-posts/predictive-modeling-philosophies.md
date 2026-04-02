---
title: "Philosophical Stances for Predictive Modeling"
description: "Forecasting differs by what it tries to approximate: the world, the data, a set of possible futures, or informed human judgment. Each orientation reflects a distinct view of what makes a forecast valid. They are complementary rather than competing, and most systems combine them. Their differences matter most when conditions change or uncertainty is high."
image: /assets/social-card-pub.png
---

# Philosophical Stances for Predictive Modeling

*by Dr. Staffan Canback, Tellusant*

Forecasting differs by what it tries to approximate: the world around us, the data as it comes, a set of possible futures, or informed human judgment. Each orientation reflects a distinct view of what makes a forecast valid. 

They are complementary rather than competing, and most systems combine them. Their differences matter most when conditions change or uncertainty is high.

<div style="max-width: 600px; margin: 0 auto;">
<div class="mermaid">
  
flowchart LR

%%{init: {'themeVariables': { 'fontFamily': 'Arial'}}}%%
%% ========= NODES =========
P["`1.2<br/>**Predictive Modeling**<br/>**Philosophies**`"]:::none

AW["`1.21<br/>**Approximate<br/>the World**`"]:::strong
AD["`1.22<br/>**Approximate<br/>the Data**`"]:::mixed
PW["`1.23<br/>**Map Possible<br/>Worlds**`"]:::neutral
HA["`1.24<br/>**Let Humans<br/>Arbitrate**`"]:::risk

STR["`1.211<br/>**Structural**<br/>*Only what is modeled<br/>based on theory<br/>can be trusted*`"]:::strong
RED["`1.212<br/>**Reduced-Form**<br/>*Stability is more<br/>valuable than truth*`"]:::strong
EMP["`1.221<br/>**Empirical**<br/>*The data are<br/>the model*`"]:::mixed
STA["`1.213<br/>**State-Space**<br/>*The signal is<br/>never observed<br/>directly*`"]:::mixed
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
AD --> EMP
AD --> STA
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

## Approximate the World
Here the aim is to model the mechanisms that produce the data—causal relationships, constraints, and latent processes. Forecasts derive their credibility from the correctness of this structure, not merely from fit. This orientation supports explanation and counterfactual reasoning, but depends on specifying the system well enough to remain valid outside the observed range.

### Structural
The structural stance holds that forecasts are credible only insofar as they reflect the true causal mechanisms of the system being modeled. It requires explicit specification of relationships grounded in theory—economic, physical, or behavioral—and emphasizes interpretability and policy relevance. 

Because it models how the world works rather than how data appear, it is better suited for counterfactual analysis and regime change. Its limitation is that incorrect or incomplete specification can degrade predictive accuracy, especially in the short run.

>This is a severe form of modeling and it takes a long time to get right, the kind of time governments and academics often have. In corporate settings it can be a time sink.

### Reduced-Form
The reduced-form stance occupies the middle ground, seeking stable empirical relationships without fully specifying the underlying system. It accepts that causal drivers matter—such as price, income, or external conditions—but does not attempt full structural identification. 

The focus is on finding relationships that are empirically robust and practically useful for prediction. This approach often delivers a balance between accuracy and interpretability, though it depends critically on the stability of observed relationships over time.

>This is the most common way to make medium and long-term predictions in the corporate world. It allows for flexibility yet is reasonably rigorous. We recommend using this.

## Approximate the Data
This orientation treats the historical record as the most reliable guide to the future and judges models by predictive performance on unseen data. Structure is incidental—what matters is extracting stable patterns. It excels when the data-generating process is persistent and richly observed, and it fails when regimes shift or when past patterns cease to hold.  

### Empirical
The empirical stance treats forecasting as a problem of pattern extraction from data, with validity determined strictly by out-of-sample performance. It makes minimal assumptions about underlying mechanisms and instead relies on the idea that whatever structure exists will be reflected in historical observations.  

Model choice is therefore guided by predictive accuracy rather than interpretability, and techniques range from classical time-series methods to modern machine learning. Its strength lies in adaptability and performance—its weakness is vulnerability when the data-generating process shifts.  

>This is mainly used in short-term forecasting. It predicts well but has limited explanatory power. Do not confuse this method with what is needed for medium and long-term forecasting.

### State-Space
The state-space stance views observed data as noisy manifestations of underlying latent processes that evolve over time. Forecasting becomes a problem of estimating and projecting these hidden states, typically using recursive filtering methods (e.g., Kalman). 

This framework is well suited for handling time variation, missing information, and real-time updating, making it central to nowcasting and dynamic modeling. Its effectiveness depends on the correct specification of the latent structure and noise processes. It is primarily used in engineering, especially electrical enginering.  

>Of limited use in general management. It is fun for scientists but real-world uses seldom benefit from this, outside engineering.
>
>Note that even though this is a philosophical stance, there is a direct link to practical predictive models. Here is the demand model we use routinely expressed in state-space notation:

$$\\mathbf{X}'(x) = \mathbf{A}(x)\mathbf{X}(x) \qquad \y(x) = \mathbf{C}\mathbf{X}(x)\$$

$$\\mathbf{A}(x) = \begin{bmatrix} \dfrac{\eta}{x} - \zeta \end{bmatrix}, \qquad\mathbf{C} = \begin{bmatrix} 1 \end{bmatrix}.\$$

>Six of the seven philosophical stances (not pragmatism though) have directly corresponding math that is used in statistical models.  

## Map Possible Worlds  
This orientation treats the future as a set of conditional outcomes under differing assumptions rather than a single prediction. It is designed for environments with structural uncertainty, policy shifts, or low-frequency shocks. Its value lies in clarifying contingencies and strategic options. Its limitation is that it does not, by itself, assign probabilities or select a single outcome.  

### Scenario-Based  
The scenario-based stance rejects the idea of a single predicted future and instead constructs multiple conditional futures based on differing assumptions. It is particularly suited to environments characterized by structural uncertainty, policy changes, or rare events.  

Scenarios are not forecasts in a strict statistical sense but structured explorations of possibility spaces, often used for strategic planning. Their value lies in broadening decision-making while their limitation is the absence of probabilistic ranking unless combined with other approaches.  

>This is a truly useful philosophy. It was pioneered by Shell in the corporate world in the 1970s and is today a mainstay of planning. Ideally combined with reduced-form (above).

## Let Humans Arbitrate
This orientation recognizes that models are incomplete and that expert judgment contributes information not captured in data or structure. Forecasts are therefore adjusted, combined, or overridden based on context and experience. It can correct systematic blind spots, but introduces the risk of bias and inconsistency if not disciplined.  

### Judgemental
The judgmental stance recognizes that not all relevant information can be formalized in data or models and that expert judgment plays an irreducible role in forecasting. It incorporates tacit knowledge, contextual awareness, and qualitative insights, often through adjustments or overrides of model outputs.  

While it introduces risks of bias and inconsistency, it can add value in situations where data are sparse, regimes are shifting, or models systematically miss key factors. In practice, it often complements rather than replaces formal modeling.  

>It has repeatedly been shown that judgment from experts enhances mechanical (statistical) models. A good predictive model should include a judgment component, but judgment bias should be tracked and adjusted for. Experts tend to be too optimistic, especially if they are employees.

### Bayesian Support  
The Bayesian stance frames forecasting as the continuous updating of probabilistic beliefs in light of new evidence. Rather than producing single-point estimates, it treats all forecasts as distributions, explicitly incorporating uncertainty and prior information. 

This allows for coherent integration of data, expert knowledge, and model structure. Its strength is conceptual consistency and clarity about uncertainty; its cost is increased computational and modeling complexity.

>Bayesian methods are intellectually intriguing but hard to understand for general managers who do not have the time to learn how this works. There are specialized uses, but it is nothing we recommend for widespread adoption. Too complicated.

---
*ChatGPT was used for brainstorming and drafting support.*  

[See our collection of thought pieces on predictive model theory](predictive-modeling-collection.md)  

[Find more articles and posts](index.md)  
