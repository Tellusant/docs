---
title: "How to Specify and Evaluate Predictive Models"
description: "Statistical models are seldom well contextualized and evaluating them becomes a laundry list of observations and questions. Here we suggest a structured approach."
image: /assets/social-card-pub.png
---

# How to Specify and Evaluate Predictive Models - LIGHT EDIT VERSION

*by Dr. Staffan Canback, Tellusant*

Statistical models are seldom well contextualized and evaluating them becomes a laundry list of observations and questions. Here we suggest a structured approach inspired by the law of threes. We use Wittgenstein's numbering system.

This is not about building models; it is about what happens before and after building.

More precisely, predictive models should be judged at three levels: the framing before modeling, the technical construction, and the way models are used. Failure at any one level can invalidate success at the others.

Predictive models mostly come in four flavors:
- Short-term time-dependent
- Long-term time-dependent
- Geographic cross-sectional
- Product cross-sectional

Here we mainly discuss time-dependent models (we say time-dependent, not time series because time series is associated with moving averages, ARIMA and similar, which is only one aspect of solving time problems.)

<p align="center">
<img  src="assets/images/tellusant-predictive-model-evaluation-framework.svg" width="500" alt="Tellusant predictive model evaluation framework.svg
">
</p>

## 1. Higher-Order Cognitive Choices

The most important part of the modeling effort is to have the correct higher-order cognitive choices laid out:

Before starting, it is useful to review relevant theory and prior empirical work. This is especially important for cross-sectional and near-term predictions; for long-term predictions, there is less guidance.

### 1.1 Objectives  
The first aspect of objectives is whether the model is for strategic horizons (3-, 5-, 10-years out) or for near-term operational or tactical uses (0-18 months out). Or perhaps it is a geographic model (cross-sectional). These three uses lead to completely different modeling choices.

The second aspect of model objectives is to clarify if it is developed to [save cost, reduce time or increase accuracy](https://tellusant.github.io/docs/articles-posts/cost-time-accuracy.md). Too often, objectives focus on accuracy. However, no senior executive will approve an accuracy-only model if it adds another layer of bureaucracy.

### 1.2 Philosophies of Predictive Modeling  
There are, usefully, seven modeling philosophies to choose among and combine, ranging from "let theory guide choices" to "if it works, it's OK".

These are not model classes, but default stances about how uncertainty is approached.  

[The seven philosophies are explicated in this separate document](predictive-modeling-philosophies.md). Here is a summary.

<p align="center">
<b>PHILOSOPHIES OF PREDICTIVE MODELING</b>
</p>
<div style="max-width: 450px; margin: 0 auto;">
<div class="mermaid">
[UNCHANGED MERMAID BLOCK]
</div>
</div>

### 1.3 Limitations  
Any model has to make a [tradeoff between being predictive, explanatory or understandable](horns-dilemma-2.md). These objectives often conflict, and strength in one dimension typically comes at the expense of the others.  

---

## 2. Model Specifics
These higher-level choices are converted into specific courses of action. These are the subject of countless textbooks, so we only touch on a few points:

### 2.1 Data
Much of a modeling effort is spent on time-consuming data tasks, especially data wrangling. Having a clear view of what is needed saves considerable time.

### 2.2 Drivers  
Develop a list of potential drivers based on a) theory, and b) expert opinions, but do not c) test every conceivable driver except if you use philosophy 1.221, in which case you do not do a) and b).

### 2.3 Model Development  
Once the higher-level choices are made, it is straightforward to develop the actual model. It is still a great deal of work.

### 2.4 Validation  
Validation operates at several levels: statistical fit, comparison with alternatives, and practical plausibility.  

[Validate using ex-post MAPE](../quick-reads/Tellusant-Quick-Read-Ex-post-and-Ex-ante-Validation-of-Statistical-Models.pdf) if the model is over time, LOOCV if it is cross-sectional. Be sure to include alternative models (especially the naïve model) and compare with Akaike Information Criterion (AIC). But most importantly, does the chosen model meet the smell test?  

---

## 3. Model outcomes  
Outcomes are seen in the evaluation phase, but are not part of the specification phase.

### 3.1 Results  
Results are far more than model accuracy.

The **first** dimension of results is whether the model aligns with the objectives. If the model is meant to be accurate, is it? If it is meant to save cost and time, does it? [3.11]

The **second** dimension is the user interface. Can the model be used by the intended audience? Did it turn out to be a model by modellers for modellers? Delivering models in Excel and PowerPoint often leads to version creep and mistakes. Cloud-based delivery based on modern tools is typically more robust. [3.12]

The **third** dimension is model reliability. There are two subdimensions:

- Is the model consistent for all users? E.g., will a user in one country get results generated in the same manner as a user in another country? The method has to be the same; the data, coefficients (elasticities), and findings differ. [3.131]
- Is the model accurate? This goes back to 2.4 above. This is important, but if the model violates points *one* and *two*, accuracy does not matter. [3.132]

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
[Find more articles and posts](index.md)  
Light edit version
