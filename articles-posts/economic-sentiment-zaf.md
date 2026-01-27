---
layout: default
title: South Africa Economic Sentiment Analysis Based on Article IV et Plus
description: Semantic parsing of IMF text with scoring and weighting
---

# South Africa Economic Sentiment Analysis Based on Article IV et Plus
 Semantic parsing of IMF text with automated scoring and weighting.

---
<div class="mermaid">
flowchart TD
    GE["GLOBAL ENVIRONMENT\nScore: 3/10"]
    FP["FISCAL POLICY\nScore: 3/10"]
    GJ["GROWTH & JOBS\nScore: 4/10"]
    MP["MONETARY POLICY\nScore: 8/10\n''Risks remain tilted to the downside''"]:::risk
    MS["MACRO STABILITY\nScore: 6/10"]
    FS["FINANCIAL SECTOR\nScore: 8/10"]
    SR["STRUCTURAK REFORMS\nScore: 5/10"]
    LC["LONG-TERM CONFIDENCE\nScore: 5/10"]

    GE -->|Downside risks| GJ
    FP -->|Constrains growth| GJ
    MP -->|Anchors inflation| MS
    MS -->|Enables| GJ
    MP -->|Strengthens| FS
    FS <-->|Depends on progress| SR
    SR -->|Pace insufficient| LC
    LC -->|Feedback loop| GJ

    classDef risk fill:#fdecea,stroke:#b71c1c,stroke-width:2px
</div>

---
<div class="mermaid">
flowchart TD

%% ========= NODES =========
GE["GLOBAL ENVIRONMENT\nScore: X/10\n''External conditions shape the outlook''"]:::risk
FP["FISCAL POLICY\nScore: X/10\n''Fiscal dynamics influence confidence''"]:::risk
GJ["GROWTH & JOBS\nScore: X/10\n''Growth reflects structural constraints''"]:::risk
MP["MONETARY POLICY\nScore: X/10\n''Policy credibility anchors stability''"]:::strong
MS["MACRO STABILITY\nScore: X/10\n''Buffers support resilience''"]:::neutral
FS["FINANCIAL SECTOR\nScore: X/10\n''The financial system remains sound''"]:::strong
SR["STRUCTURAL REFORMS\nScore: X/10\n''Reform momentum is critical''"]:::mixed
LC["LONG-TERM CONFIDENCE\nScore: X/10\n''Confidence depends on delivery''"]:::mixed

%% ========= RELATIONSHIPS =========
GE -->|Downside risks| GJ
FP -->|Constrains growth| GJ
MP -->|Anchors inflation| MS
MS -->|Enables| GJ
MP -->|Strengthens| FS
FS <-->|Depends on progress| SR
SR -->|Pace matters| LC
LC -->|Feedback loop| GJ

%% ========= INVISIBLE ANCHOR =========
ANCHOR[" "]:::anchor
GJ --> ANCHOR

%% ========= SUMMARY (FORCED BELOW) =========
SUM["SUMMARY\nWeighted average score: X.XX/10\nOne-sentence IMF-style synthesis goes here."]:::summary
ANCHOR --> SUM

%% ========= STYLES =========
classDef strong  fill:#E8F5E9,stroke:#1B5E20,stroke-width:2px,color:#111;
classDef neutral fill:#E3F2FD,stroke:#0D47A1,stroke-width:2px,color:#111;
classDef mixed   fill:#FFF8E1,stroke:#FF6F00,stroke-width:2px,color:#111;
classDef risk    fill:#FDECEA,stroke:#B71C1C,stroke-width:2px,color:#111;
classDef summary fill:#F5F5F5,stroke:#424242,stroke-width:2px,color:#111;
classDef anchor fill:transparent,stroke:transparent;

</div>
