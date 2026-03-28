---
title: "How to Specify and Evaluate Predictive Models"
description: "Statistical models are seldom well contextualized and evaluating them becomes a laundry list of observations and questions. Here we suggest a structured approach."
image: /assets/social-card-pub.png
---

# How to Specify and Evaluate Predictive Models

*by Dr. Staffan Canback, Tellusant*

Statistical models are seldom well contextualized and evaluating them becomes a laundry list of observations and questions. Here we suggest a structured approach inspired by the law of threes. We use Wittgenstein's numbering system.

This is not about building models; it is about what happens before and after building.

Predictive models mostly come in four flavors:
- Short-term time dependent
- Long-term time dependent
- Geographic cross-sectional
- Product cross-sectional

Here we mainly discuss time-dependent models (we say time dependent, not timeseries because timeseries is associated with moving averages, ARIMA and similar, which is only one aspect of solving time problems.)

<p align="center">
<img  src="assets/images/tellusant-predictive-model-evaluation-framework.svg" width="500" alt="Tellusant predictive model evaluation framework.svg
">
</p>

## 1. Higher Order Cognitive Choices

The most important part of the modelling effort is to have the correct higher-order cognitive choices laid out:  

### 1.0 Literature Review

Before starting, do a thorough a thorough search of the relevant authorities. For cross-sectional and near-term predictions there is plenty of literature, for long-term predictions there is not much. When evaluating, make sure the authorities are listed. *A model without explicit authorities cited is no model.*  
- Economic theory (3-5 papers). Very important.  
- Econometric methods (3-5 papers). Somewhat important.

We have observed that data scientistists often have little konwledge of economic theory and jump into econometrics too quickly. This sometimes make them ill equipped to develop useful models.

**1.1 Objectives**  
The first aspect of objectives is whether the model is strategic horizons (3-, 5-, 10-years out) or for near-term operational or even tactical uses (0-18 months out). Or perhaps it is a geographic model (cross-sectional). These three uses lead to completetly different modeling choices.  

The second aspect of model objectives is to clarify if it is developed to [save cost, reduce time or increase accuracy](https://tellusant.github.io/docs/articles-posts/cost-time-accuracy.md). Too often, objectives focus on accuracy. However, no senior executive will approve an accuracy-only model if it adds another layer of bureaucracy.  

**1.2 Philosophies of Predictive Modeling**  
There are usefully seven modeling philosophies to choose among and combine, ranging from "let theory guide choices" to "if it works, it's OK". 

<p align="center">
<b>PHILOSOPHIES OF PREDICTIVE MODELING</b>
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

**1.3 Limitations**  
Any model has to make the [tradeoff between being predictive, explanatory or understandable](horns-dilemma-2.md). All three cannot be achieved in one model. E.g., a pure timeseries model often works well for near-term forecasts but is poor at explaining yet easy to understand. A long-term non-linear regression model typically has high predictiveness and is explanatory, but may be hard to understand.  

---
## 2. Model Specifics

These higher level choices are converted into specific courses of action. These are the subject of countless textbooks so we only touch on a few points:  

### 2.1 Data
Much of a modeling effort is spent on trivial, time-consuming data tasks, especially data wrangling. Having a clear view on what is needed saves considerable time.  

### 2.2 Drivers  
Develop a list of ptential drivers based on a) theory, and b) expert opinions, but do not c) test every conceivable driver except if you use philosophy 1.221, in which case you do not do a) and b).  

### 2.3 Model Development  
Once the higher level choices are made, it is straightforward to develop the actual model. Much work though.

### 2.4 Validation  
[Validate using ex-post MAPE](../quick-reads/Tellusant-Quick-Read-Ex-post-and-Ex-ante-Validation-of-Statistical-Models.pdf) if the model is over time, LOOVC if it is cross-sectional. Be sure to include alternative models (especielly the naïve model) and compare with Aikake Information Criterion (AIC). But most importantly, does the model chosen meet the smell test?  

---
## 3. Model outcomes  
Outcomes are seen in the evalution phase but are obviously not part of the specification phase. 
### 3.1 Results  
Results are far more than model accuracy.

The **first** dimension of results is if the model aligns with the objectives. If the model is meant to be accurate, is it? If it is meant to save cost and time, does it? [3.11] 

The **second** dimension is the user interface? Can the model be used by the intended audience? Did it turn out to be a model by modellers for modellers? Delivering models in Excel and PowerPoint is prohibited. It only leads to version creep, and mistakes. Cloud-based deliveries based on modern tools is the only way to go. [3.12]

The **third** dimension is model consistency. There are two subdimensions:  

- Is the model consistent for all users? E.g., will a user in one country get results generated in the same manner as a a user in another country. The method has to be the same, the data, coefficients (elasticities), and findings differ. [3.131]
- Is the model accurate. This goes back to 2.4 above. This is important, but if the model violates points *one* and *two*, accuracy does not matter. [3.132]

We therefore have an AND logic: **1∧2∧3**.

### 3.2 Lessons Learned  

### 3.3 Recommendations  
There will inevitably be a few recommendations, ideally three and ranked by importance. The three can then have sub-points.

Recommendations should include timing. What is important now? In next years cycle of improvements? In the unknown future? What looks important here and now often fades in importance in a few weeks or months. Therefore, patience is required to not stir up unnecessary work.

Most models perform well if they where developed by thoughtful people without too much rush. Therefore, one cannot expect recommendations too be overly expansive. If they are, maybe the evaluators should be scrutinized.

One common problem is that the evaluation is often seconded to an academic reviewer. Those reviewers, knowingly or not, tend to offer extensive criticism of what the builders have created, especially if they come with a commercial background. The main question is: are such points truly adding to the model objectives and philosophy?

This said, the main recommendations should be implemented in a timely manner for the good of results for years to come.

---
[2026-03-28]  
[Find more articles and posts](index.md)
