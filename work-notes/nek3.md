# NEK 3 NEK3

<div style="max-width: 450px; margin: 0 auto;">
<div class="mermaid">

flowchart TD

%%{init: {'themeVariables': { 'fontFamily': 'Arial'}}}%%

    V["`**Validation Approaches**`"]:::none

    F["`**Falsification<br/>(Not Rejected)**<br/>*Hypotheses are<br/>not confirmed.<br/>They survive<br/>attempts at refutation*`"]:::strong
    B["`**Bayesian Epistemology**<br/>*Evidence updates belief;<br/>hypotheses gain<br/>posterior probability*`"]:::strong
    C["`**Confirmation Theory**<br/>*Evidence increases<br/>degree of support*`"]:::strong
    I["`**Inference to the<br/>Best Explanation**<br/>*Prefer the hypothesis<br/>that best explains<br/>the evidence*`"]:::strong
    R["`**Pragmatism**<br/>*Hypotheses validated<br/>by practical success*`"]:::strong

    NV["`**Not Possible**`"]:::none
    CO["`**Proving<br/>Hypotheses<br/>True**`"]:::mixed

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
