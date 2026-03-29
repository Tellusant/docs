---
title: "Philosophies of Predictive Modeling"
description: "Work-in-progress"
image: /assets/social-card-pub.png
---

# Philosophies of Predictive Modeling

Work-in-progress. The 11 boxes will be explained.

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
