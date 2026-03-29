---
title: "How to Specify and Evaluate Predictive Models"
description: "Statistical models are seldom well contextualized and evaluating them becomes a laundry list of observations and questions. Here we suggest a structured approach."
image: /assets/social-card-pub.png
---

# How to Specify and Evaluate Predictive Models

*by Dr. Staffan Canback, Tellusant*

>This paper builds on the author's decades of top management consulting experience, increasingly supported by predictive and other statistical models. It also leverages the author's academic experience over the past 30 years.
>
>The central theme is that predictive models in corporate settings too often are developed myopically based on root knowledge, rather than from within a larger context.
>
>The paper steps back from the details of model construction and instead discusses what surrounds this, including philosophical stances that should be decided before an effort starts.
>
>It is intended as a prescriptive framework with flexibility, with the aim of satisfying top managements' priorities and corporate users' needs.

Statistical models are seldom well contextualized and evaluating them becomes a laundry list of observations and questions. Here we suggest a structured approach inspired by the law of threes. We use Wittgenstein's numbering system.

This paper is not about building models; it is about how models should be framed and judged.

Predictive models should be evaluated across three layers:
1. Higher-order cognitive framing before modeling
2. Model construction and validation
3. Model outcomes and practical usage  

Failure at any one layer can outweigh success at the others. However, most modeling efforts focus on the second layer.

Corporate predictive models (outside engineering and finance) arguably come in four main categories that can be mixed:  
- Short-term time-dependent  
- Long-term time-dependent  
- Geographic cross-sectional  
- Product cross-sectional  

Here we mainly discuss time-dependent models (we say time-dependent, not time series because time series is associated with moving averages, ARIMA and similar, which is only one aspect of solving time problems).

With this as background, a holistic schenatic of a predictive modeling initiatives is shown below.

<p align="center">
<img  src="assets/images/tellusant-predictive-model-evaluation-framework.svg" width="550" alt="Tellusant predictive model evaluation framework.svg
">
</p>

## 1. Higher-Order Cognitive Framing

Higher-order choices determine what constitutes a “good” model before any estimation takes place. Most modeling failures originate here rather than in the estimation step.  

A brief review of relevant theory and prior empirical work is often useful, especially for cross-sectional and near-term models. For long-term prediction, such guidance is more limited.  

### 1.1 Objectives  
Objectives define what success means. They are best developed through interviews with senior management.

The first aspect is the use case: strategic horizons (3-, 5-, 10-years out), near-term operational or tactical uses (0–18 months out), or cross-sectional analysis. These lead to fundamentally different modeling approaches.  

The second aspect of model objectives is to clarify if it is developed to [save cost, reduce time or increase accuracy](https://tellusant.github.io/docs/articles-posts/cost-time-accuracy.md). Accuracy is often overemphasized relative to cost and time. However, no senior executive will approve an accuracy-only model if it adds another layer of bureaucracy.  

### 1.2 Philosophies of Predictive Modeling  
Modeling also reflects underlying philosophical choices.  

There are, usefully, seven modeling philosophies to choose among and combine, ranging from "let theory guide choices" to "if it works, it's OK".  

These are not model classes, but default stances about how uncertainty is represented and resolved.  

[The seven philosophies are explicated in this separate document](predictive-modeling-philosophies.md). Here is a summary.  

<p align="center">
<b>PHILOSOPHICAL STANCES OF PREDICTIVE MODELING</b>
</p>
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

A literature review will help in finding the right philosophical stance. It should be combined with an interpretation of what top management is looking for.¹


### 1.3 Limitations  
All models face [tradeoffs between being predictive, explanatory, and understandable](horns-dilemma-2.md). These goals typically conflict at the margin. E.g., a pure time-dependent model often works well for near-term forecasts but is poor at explaining yet easy to understand. A long-term non-linear regression model may be predictive and explanatory but harder to understand.  

---

## 2. Model Construction

Model specifics are downstream consequences of higher-order choices. These are the subject of countless textbooks, so we only touch on a few points:  

### 2.1 Data
Much of a modeling effort is spent on time-consuming data tasks, especially data wrangling. Having a clear view of what is needed saves considerable time.  

### 2.2 Drivers  
Develop a list of potential drivers based on a) theory, and b) expert opinions, but do not c) test every conceivable driver except if you use philosophy 1.221, in which case you do not do a) and b).  

### 2.3 Model Development  
Once the higher-level choices are made, it is straightforward to develop the actual model. It is still a great deal of work.  

### 2.4 Validation  
Validation should be understood in three layers:  
- statistical fit  
- comparison with alternatives  
- practical plausibility  

[Validate using ex-post MAPE](../quick-reads/Tellusant-Quick-Read-Ex-post-and-Ex-ante-Validation-of-Statistical-Models.pdf) if the model is over time, LOOCV if it is cross-sectional. Be sure to include alternative models (especially the naïve model) and compare with Akaike Information Criterion (AIC). But most importantly, does the chosen model meet the smell test?

---

## 3. Model outcomes  
Outcomes are seen in the evaluation phase, but are not part of the framing phase.

### 3.1 Results  
Evaluation is not reducible to accuracy.

The **first** dimension of results is whether the model aligns with the objectives. If the model is meant to be accurate, is it? If it is meant to save cost and time, does it? [3.11]

The **second** dimension is the user interface. Can the model be used by the intended audience? Did it turn out to be a model by modellers for modellers? Delivering models in Excel and PowerPoint often leads to version creep and mistakes. Cloud-based delivery based on modern tools is typically more robust. [3.12]

The **third** dimension is reliability. There are two subdimensions:

- Is the model consistent for all users? E.g., will a user in one country get results generated in the same manner as a user in another country? The method has to be the same; the data, coefficients (elasticities), and findings differ. [3.131]
- Is the model accurate? This goes back to 2.4 above. This is important, but if the model violates points *one* and *two*, accuracy does not matter. [3.132]

These three dimensions are jointly necessary.

We therefore have an AND logic: **1∧2∧3**.

### 3.2 Lessons Learned   
There will inevitably be lessons learned in a process that often has taken 6 months up to two years (not all the time is spent on modeling; it also includes application development and user training).

Lessons can often be grouped in three buckets:
- *Improving data management*. Companies are still in the infancy of robust data management. They may collect the data but do not wrangle it. Subsidiaries use different sources and definitions. There are always important lessons in data management. [3.21]
- *Increasing parsimony*. There is intense pressure from executives without statistical training to have many independent variables. Therefore models tend to be less parsimonious and more bloated than necessary. [3.22]
- *New areas to pursue*. For example, a model may be intended for strategic purposes, but it may be learned that there is also a need for an operational model. Strategic and operational models have little in common. [3.23]

### 3.3 Recommendations 
This is based on numerous practical recommendation rounds at various clients.

There will inevitably be a few recommendations; ideally three, ranked by importance. The three can then have sub-points.

Recommendations should include timing. What is important now? In next year's cycle of improvements? In the unknown future? What looks important here and now often fades in importance in a few weeks or months. Therefore, patience is required to avoid unnecessary work.

Most models perform well if they were developed by thoughtful people without too much rush. Therefore, one cannot expect recommendations to be overly expansive. If they are, perhaps the evaluators should be scrutinized. Or perhaps the builders and evaluators come from different philosophical schools (see 1.2) without knowing it.

One common problem is that evaluation is often seconded to an academic reviewer. Those reviewers, knowingly or not, tend to offer extensive criticism of what the builders have created, especially if they come from a commercial background. The main question is: are such points truly adding to the model objectives?

This said, the main recommendations should be implemented in a timely manner for the good of results for years to come.

---
¹ Senior executives are, for good reasons, usually not able to articulate this clearly (few would know what state-space or Bayesian means), but it can be deduced from the interviews mentioned earlier.

---
[Find more articles and posts](index.md)  
Deep edit version
