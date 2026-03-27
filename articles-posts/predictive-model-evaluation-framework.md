# How to Specify and Evaluate (but not Build) Predictive Models

*Work in progress. Text getting there. Graph is correct*  

Statistical model are often not contextualized in a structured manner and evaluating them becomes a laundry list of observations and questions. Here we suggest a structured approach based on the law of threes.

<p align="center">
<img  src="assets/images/tellusant-predictive-model-evaluation-framework.svg" width="500" alt="Tellusant predictive model evaluation framework.svg
">
</p>

## Comments

The most important part of the modelling effort is to have the correct higher-level cognitive choices laid out:  

**1.1 Objectives**  
The first aspect of objectives is whether the model is strategic horizons (3-, 5-, 10-years out) or for near-term operational or even tactical uses (0-18 months out). Or perhaps it is a geographic model (cross-sectional). These three uses lead to completetly different modeling choices.  

The second aspect of model objectives is to clarify if it is developed to [save cost, reduce time or increase accuracy](https://tellusant.github.io/docs/articles-posts/cost-time-accuracy.md). Too often, objectives focus on accuracy. However, no senior executive will approve an accuracy-only model if it adds another layer of nureaucracy.  

**1.2 Modeling Philosophy**  
There are usefully seven modeling philosophies to choose among ranging from "let theory guide choices" to "if it works, it's OK". 
P["1.2<br/>`**Prediction**`<br/>𝗣𝗵𝗶𝗹𝗼𝘀𝗼𝗽𝗵𝗶𝗲𝘀"]:::none
<div style="max-width: 550px; margin: 0 auto;">
<div class="mermaid">
  
flowchart LR

%% ========= NODES =========
P["`**Prediction**<br/>**Philosophies**`"]:::none

AW["1.21<br/>𝗔𝗽𝗽𝗿𝗼𝘅𝗶𝗺𝗮𝘁𝗲<br/>𝘁𝗵𝗲 𝗪𝗼𝗿𝗹𝗱"]:::strong
AD["1.22<br/>𝗔𝗽𝗽𝗿𝗼𝘅𝗶𝗺𝗮𝘁𝗲<br/>𝘁𝗵𝗲 𝗗𝗮𝘁𝗮"]:::mixed
PW["1.23<br/>𝗠𝗮𝗽 𝗣𝗼𝘀𝘀𝗶𝗯𝗹𝗲<br/>𝗪𝗼𝗿𝗹𝗱𝘀"]:::neutral
HA["1.24<br/>𝗟𝗲𝘁 𝗛𝘂𝗺𝗮𝗻𝘀<br/>𝗔𝗿𝗯𝗶𝘁𝗿𝗮𝘁𝗲"]:::risk

STR["1.211<br/>𝗦𝘁𝗿𝘂𝗰𝘁𝘂𝗿𝗮𝗹<br/>''Only what is modeled<br/>causally can be trusted''"]:::strong
RED["1.212<br/>𝗥𝗲𝗱𝘂𝗰𝗲𝗱-𝗙𝗼𝗿𝗺<br/>''Stability is more<br/>valuable than truth''"]:::strong
STA["1.213<br/>𝗦𝘁𝗮𝘁𝗲-𝗦𝗽𝗮𝗰𝗲<br/>''The signal is<br/>never observed<br/>directly''"]:::strong
EMP["1.221<br/>𝗘𝗺𝗽𝗶𝗿𝗶𝗰𝗮𝗹<br/>''The data are<br/>the model''"]:::mixed
SCE["1.231<br/>𝗦𝗰𝗲𝗻𝗮𝗿𝗶𝗼-𝗕𝗮𝘀𝗲𝗱<br/>''There is no<br/>single future''"]:::neutral
JUD["1.241<br/>𝗝𝘂𝗱𝗴𝗺𝗲𝗻𝘁𝗮𝗹<br/>''The final model<br/>is human''"]:::risk
BAY["1.242<br/>𝗕𝗮𝘆𝗲𝘀𝗶𝗮𝗻 𝗦𝘂𝗽𝗽𝗼𝗿𝘁<br/>''All forecasts<br/>are probabilities''"]:::risk

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
Any model has to make the [tradeoff between being predictive, explainable or understandable](horns-dilemma-2.md). All three cannot be achieved in one model. E.g., a pure timeseries model often works well for near-term forecasts but lacks explainability and transparency. A long-term non-linear regression model typically has high predictiveness and explainability, but may be hard to understand.  

---
These higher level choices are converted into specific courses of action:  

**2.1 Data**  
Much of a modeling effort is spent on trivial, time-consuming data tasks, especially data wrangling. Having a clear view on what is needed saves considerable time.  

**2.2 Drivers**  
Develop a list of ptential drivers based on a) theory, and b) expert opinions, but do not c) test any conceivable driver except if you use philosophy 1.221, in which case you do not do a) and b).  

**2.3 Model Development**  
This is based on  

**2.4 Validation**  
Validate using ex-post MAPE if the model is over time, LOOVC iif it cross-sectional. Be sure to include alternative models and test against Aikake Information Criterion. But most importantly, does the model meet the smell test? An example, a team developed a demand model based on the data, testing all permutations of drivers (possible or not). They found that government budget deficit was the only meaningful driver of demand. This does not meet the smell test.  

---
Model outcomes stem from these:  

**3.1 Results**  

**3.2 Lessons Learned**  

**3.3 Recommendations**  
