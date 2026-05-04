---
title: "How do I Know If My Model Works? Hypothesis Validation Approaches"  
description: "There is a tension that runs through modern epistemology: between a science of refutation and a desire for affirmation. We want hypotheses ''proven'', but this is impossible. Here we delineate the approaches that can be used to get closer to affirmation."  
image: /assets/social-card-pub.png  
---

# How do I Know If My Model Works? Hypothesis Validation Approaches

*by Dr. Staffan Canback, Tellusant*

There is a tension that runs through modern epistemology: between a science of refutation and a desire for affirmation. We want hypotheses "proven", but this is impossible. Here we delineate the approaches that can be used to get closer to proof.

>In our chairman's doctoral dissertation, he said: *For simplicity, the word ”confirmed” is used, although ”not rejected” is more accurate.* Such tension exists forever.

<figure>
    <figcaption style="font-weight: bold; text-align: center;">HYPOTHESIS VALIDATION APPROACHES</figcaption>
    <br/>
<div style="max-width: 450px; margin: 0 auto;">
<div class="mermaid">

flowchart LR

%%{init: {'themeVariables': { 'fontFamily': 'Arial'}}}%%

    V["`**Validation Approaches**`"]:::none

    F["`**Falsification<br/>(Not Rejected)**<br/>*Hypotheses are not<br/>confirmed. They survive<br/>attempts at refutation*`"]:::strong
    B["`**Bayesian Epistemology**<br/>*Evidence updates belief;<br/>hypotheses gain<br/>posterior probability*`"]:::strong
    C["`**Confirmation Theory**<br/>*Evidence increases<br/>degree of support*`"]:::strong
    I["`**Inference to the<br/>Best Explanation**<br/>*Prefer the hypothesis that<br/>best explains the evidence*`"]:::strong
    R["`**Pragmatism**<br/>*Hypotheses validated<br/>by practical success*`"]:::strong

    NV["`**Not Possible**`"]:::none
    CO["`**Proving Hypotheses True**`"]:::mixed

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
</figure>

## Falsification
Associated with Karl Popper, this approach holds that hypotheses can never be confirmed as true—they can only be exposed to tests they may fail. A theory earns standing not by accumulating supporting evidence, but by surviving serious attempts to refute it.  

The emphasis is therefore on designing risky tests—situations where the theory could genuinely break. What remains after such testing is not truth, but a provisional status: not yet rejected. This discipline protects inquiry from overconfidence, even if it leaves us with a somewhat austere notion of knowledge.  

>Less and less used as a philosophical backbone because of its severity. Nothing can be proven, or even said to be directionally correct. Hard for non-philosophers to deal with. "You say climate change is not proven, so why should we care?" "Correct, but we have not refuted it, so it could be important" A strange discussion.

## Bayesian Epistemology
Bayesian epistemology replaces the binary of reject/accept with a continuous updating of belief. Hypotheses begin with prior probabilities, which are revised in light of new evidence using Bayes’ theorem. Strong evidence can push a hypothesis to very high probability, making it rational to treat it as effectively “confirmed” for practical purposes—while never claiming certainty. 

This framework aligns closely with how scientists and analysts actually reason under uncertainty: weighing evidence, revising expectations, and comparing competing explanations quantitatively.  

>The word Bayesian may be ill chosen because it may lead thoughts astray ("too complicated"). However, the basic idea of adapting beliefs as new evidence arrives is powerful. In the end, one can get to proof in a layperson's sense.

## Confirmation Theory

Developed in the tradition of logical empiricism, notably by Rudolf Carnap, confirmation theory attempts to formalize how evidence supports a hypothesis. Instead of asking whether a theory is true or false, it asks: to what degree does the evidence confirm it? 

Various measures of confirmation have been proposed, though none has resolved all conceptual difficulties. Still, the central idea endures: evidence can accumulate in favor of a hypothesis in a structured, even if imperfectly defined, way—offering a middle ground between strict falsification and uncritical acceptance.  

>Again truly useful. Instead of black and white, it introduces shades of gray. General managers can understand this.

## Inference to the Best Explanation
Inference to the Best Explanation shifts the focus from testing single hypotheses to comparing multiple candidates. A hypothesis is accepted not because it has survived falsification, but because it explains the evidence better than its rivals—through scope, coherence, simplicity, or depth. 

This is the logic often used implicitly in science: when several models fit the data, we prefer the one that makes the most sense of it and is parsimonious. It is less formal than Bayesianism, but often more aligned with real scientific judgment.  

>We often work with companies on quick analyses and say "this is closer to the truth than what you had before. It does not mean it is true, but you are better off with this than with what you had before". Example: *You used to say that income elasticity is 1.2. We suggest making it dependent on the category's stage of development. After a statistical analysis based on this, it now ranges from 0.1 to 1.4. A much more realistic view, don't you think?*

## Pragmatism
In the tradition of William James and others, pragmatism ties the standing of a hypothesis to its practical consequences. Belief is warranted if it proves reliable in guiding action, solving problems, or integrating experience. Truth, in this view, is not a static correspondence but something that emerges through use. 

Hypotheses are “validated” insofar as they work—predictively, operationally, or socially. This approach is less concerned with abstract justification and more with whether a framework delivers results in the world.  

>We do not recommend this. Being pragmatic allows for too much self-interest and cheating in the real world.

<p align="center">
— — —
</p>
Finally, why hypothesis confirmation is impossible. 

## Proving Hypotheses True
The idea of “proving hypotheses true” runs into a structural limit: empirical claims always reach beyond the evidence that supports them. A hypothesis typically asserts something general—about all cases, or about the future—while any body of evidence is finite and local. 

No matter how many confirming instances we collect, there always remains the possibility of a counterexample tomorrow, in another setting, or under slightly different conditions. This is the classic problem of induction, articulated by David Hume and later made stringent by Karl Popper: confirmation can accumulate, but it never closes the logical gap to certainty.  

>We are always asked for this and can never deliver it. Nor can the reader of this piece.

---

[See our collection of thought pieces on predictive model theory](predictive-modeling-collection.md)  

[Find more articles and posts](index.md)   

*ChatGPT was used for brainstorming and drafting support.*  
