# NEK 2 NEK2

<div style="max-width: 600px; margin: 0 auto;">
<div class="mermaid">
  
flowchart LR

%%{init: {'themeVariables': { 'fontFamily': 'Arial'}}}%%
%% ===== Inputs =====
D1["`**Demand (t−1)**`"]:::orange
X["`**Independent Variables**<br/>(Forecasted Externally / Exogenous)`"]:::orange

%% ===== Baseline model =====
M["`**Plant Model**<br/>(Statistical)`"]:::green
S["`**Statistical<br/>Forecast (t)**`"]:::green

%% ===== Judgment and correction =====
J["`**Judgmental<br/>Overlay**`"]:::green
Sum((⠀Σ⠀)):::base
K["`**Gain K**`"]:::red
F["`**Final<br/>Forecast (t)**`"]:::green

%% ===== Realized demand =====
R["`**Realized<br/>Demand (t)**`"]:::orange

%% ===== Error and delay =====
E["`**Error e(t)**<br/>= Forecast(t) − Demand(t)`"]:::red
Delay["`**z⁻¹**`"]:::red

%% ===== Management =====
MGT["`**Management<br/>Decisions**`"]:::blue

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

linkStyle 10 stroke:blue
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
