# How to Design and Evaluate (but not Build) Predictive Models

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

The second aspect of model objectives is to clarify it is developed to [save cost, reduce time or increase accuracy](https://tellusant.github.io/docs/articles-posts/cost-time-accuracy.md). Too often, objectives focus on accuracy. However, no senior executive will approve an accuracy-only model if it adds another layer of nureaucracy.  

**1.2 Modeling Philosophy**  
There are usefully seven modeling philosophies to choose among ranging from "let theory guide choices" to "if it works, it's OK". 



<div class="mermaid">

flowchart TD

%% ========= NODES =========
GE["𝗚𝗟𝗢𝗕𝗔𝗟 𝗘𝗡𝗩𝗜𝗥𝗢𝗡𝗠𝗘𝗡𝗧<br/>Score: 3/10<br/>''Risks remain tilted to the downside''"]:::risk
GJ["𝗚𝗥𝗢𝗪𝗧𝗛 & 𝗝𝗢𝗕𝗦<br/>Score: 4/10<br/>''Growth remains constrained by bottlenecks''"]:::risk


%% ========= RELATIONSHIPS =========
GE -->|Downside risks| GJ


%% ========= INVISIBLE LAYOUT CONTROL =========
ANCHOR[" "]:::anchor

%% ========= SUMMARY (FORCED BELOW, NO VISIBLE ARROWS) =========
SUM["𝗦𝗨𝗠𝗠𝗔𝗥𝗬<br/>Weighted average score:<br/>5.05/10<br/>''Strong monetary and financial anchors
support stability, but fiscal constraints and slow reform implementation keep growth subdued''"]:::summary
LC -.-> SUM:::anchor

%% ========= STYLES =========
classDef strong  fill:#E8F5E9,stroke:#1B5E20,stroke-width:2px,color:#111;
classDef neutral fill:#E3F2FD,stroke:#0D47A1,stroke-width:2px,color:#111;
classDef mixed   fill:#FFF8E1,stroke:#FF6F00,stroke-width:2px,color:#111;
classDef risk    fill:#FDECEA,stroke:#B71C1C,stroke-width:2px,color:#111;
classDef summary fill:#F5F5F5,stroke:#424242,stroke-width:2px,color:#111;
classDef anchor fill:transparent,stroke:transparent;

</div>

**1.3 Limitations**  
Any model has to make the [tradeoff between being predictive, explainable or understandable](horns-dilemma-2.md). All three cannot be achieved in one model. E.g., a pure timeseries model often works well for near-term forecasts but lacks explainability and transparency. A long-term non-linear regression model typically has high predictiveness and explainability, but may be hard to understand.  

These higher level choices are converted into specific courses of action:

**2.1 Data** 

**2.2 Drivers**

**2.3 Model Design**

**2.4 Validation**  

Model outcomes stem from these:

**3.1 Results**

**3.2 Lessons Learned**

**3.3 Recommendations**
