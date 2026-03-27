tbd

<div class="mermaid">

flowchart TB

    %% NODES
    A[Forecasting Philosophies]

    B["Empirical (Data-Driven)\nLet the data speak; structure is secondary."]
    C["Structural (Causal / Mechanistic)\nModel the system as it actually works."]
    D["Reduced-Form (Pragmatic Causal)\nCapture stable relationships without overcommitting to theory."]
    E["Bayesian (Belief-Updating)\nForecasting is updating beliefs under uncertainty."]
    F["Scenario-Based (Counterfactual)\nThe future is not a single path but a set of plausible worlds."]
    G["State-Space (Signal Extraction)\nObserved data are noisy reflections of latent processes."]
    H["Judgmental (Heuristic)\nModels assist, but humans decide."]

    %% RELATIONSHIPS
    A --> B
    A --> C
    A --> D
    A --> E
    A --> F
    A --> G
    A --> H

</div>

<div class="mermaid">
    
flowchart TB

    %% NODES
    A[Forecasting Philosophies]

    B["Approximate the Data"]
    C["Approximate the World"]
    D["Explore Possible Worlds"]
    E["Human Arbitration"]

    F["Empirical (Data-Driven)\nLet the data speak; structure is secondary."]

    G["Structural (Causal / Mechanistic)\nModel the system as it actually works."]
    H["Reduced-Form (Pragmatic Causal)\nCapture stable relationships without overcommitting to theory."]
    I["State-Space (Signal Extraction)\nObserved data are noisy reflections of latent processes."]

    J["Scenario-Based (Counterfactual)\nThe future is not a single path but a set of plausible worlds."]

    K["Judgmental (Heuristic)\nModels assist, but humans decide."]

    L["Bayesian (Belief-Updating)\nForecasting is updating beliefs under uncertainty."]

    %% RELATIONSHIPS
    A --> B
    A --> C
    A --> D
    A --> E

    B --> F

    C --> G
    C --> H
    C --> I

    D --> J

    E --> K

    %% Bayesian spans across (placed centrally)
    A --> L

    </div>
