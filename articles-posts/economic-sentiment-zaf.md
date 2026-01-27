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

