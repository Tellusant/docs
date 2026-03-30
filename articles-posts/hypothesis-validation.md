---
title: "How do I Know Whether My Model Works? Hypothesis Validation Approaches"
description: "Work-in-progress"
image: /assets/social-card-pub.png
---

# How do I Know Whether My Model Works? Hypothesis Validation Approaches

*Work-in-progress*

<div style="max-width: 450px; margin: 0 auto;">
<div class="mermaid">

flowchart LR

    V["`**Validation Approaches**`"]:::none

    F["`**Falsification (Not Rejected)**<br/>*Hypotheses are not confirmed;<br/>they survive attempts at refutation*`"]:::strong
    B["`**Bayesian epistemology**<br/>*Evidence updates belief;<br/>hypotheses gain posterior probability*`"]:::strong
    C["`**Confirmation theory**<br/>*Evidence increases degree of support*`"]:::strong
    I["`**Inference to the Best Explanation**<br/>*Prefer the hypothesis that best explains the evidence*`"]:::strong
    R["`**Pragmatism**<br/>*Hypotheses validated by practical success*`"]:::strong

    NV["`**Not Valid**`"]:::none
    CO["`**Confirmation**`"]:::mixed

    V --> F
    V --> B
    V --> C
    V --> I
    V --> R
    NV--> CO

    %% ========= STYLES ========= Labels are from another graph
classDef strong  fill:#E8F5E9,stroke:#1B5E20,stroke-width:2px,color:#111;
classDef neutral fill:#E3F2FD,stroke:#0D47A1,stroke-width:2px,color:#111;
classDef mixed   fill:#FFF8E1,stroke:#FF6F00,stroke-width:2px,color:#111;
classDef risk    fill:#FDECEA,stroke:#B71C1C,stroke-width:2px,color:#111;
classDef summary fill:#F5F5F5,stroke:#424242,stroke-width:2px,color:#111;
classDef anchor fill:transparent,stroke:transparent;

</div>
</div>
