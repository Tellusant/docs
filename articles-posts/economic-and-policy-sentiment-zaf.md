---
layout: default
title: South Africa Economic & Policy Sentiment Analysis Based on IMF et Plus
description:  Semantic parsing of various reports such as IMF Article IV and more with automated scoring and weighting using a trained AI model.
---

# South Africa Economic & Policy Sentiment Analysis Based on IMF et Plus
Semantic parsing of various reports such as IMF Article IV and more with automated scoring and weighting using a trained AI model.

---

<div class="mermaid">
---
title: 𝗦𝗢𝗨𝗧𝗛 𝗔𝗙𝗥𝗜𝗖𝗔 𝗘𝗖𝗢𝗡𝗢𝗠𝗜𝗖 & 𝗣𝗢𝗟𝗜𝗖𝗬 𝗦𝗘𝗡𝗧𝗜𝗠𝗘𝗡𝗧
---
flowchart TD

%% ========= NODES =========
GE["𝗚𝗟𝗢𝗕𝗔𝗟 𝗘𝗡𝗩𝗜𝗥𝗢𝗡𝗠𝗘𝗡𝗧\nScore: 3/10\n''Risks remain tilted to the downside''"]:::risk
FP["𝗙𝗜𝗦𝗖𝗔𝗟 𝗣𝗢𝗟𝗜𝗖𝗬\nScore: 3/10\n''Debt remains high and rising''"]:::risk
GJ["𝗚𝗥𝗢𝗪𝗧𝗛 & 𝗝𝗢𝗕𝗦\nScore: 4/10\n''Growth remains constrained by bottlenecks''"]:::risk
MP["𝗠𝗢𝗡𝗘𝗧𝗔𝗥𝗬 𝗣𝗢𝗟𝗜𝗖𝗬\nScore: 8/10\n''Adoption of a lower inflation target is a major policy achievement''"]:::strong
MS["𝗠𝗔𝗖𝗥𝗢 𝗦𝗧𝗔𝗕𝗜𝗟𝗜𝗧𝗬\nScore: 6/10\n''Frameworks support resilience''"]:::neutral
FS["𝗙𝗜𝗡𝗔𝗡𝗖𝗜𝗔𝗟 𝗦𝗘𝗖𝗧𝗢𝗥\nScore: 8/10\n''The banking system has remained sound''"]:::strong
SR["𝗦𝗧𝗥𝗨𝗖𝗧𝗨𝗥𝗔𝗟 𝗥𝗘𝗙𝗢𝗥𝗠𝗦\nScore: 5/10\n''Implementation needs to accelerate''"]:::mixed
LC["𝗟𝗢𝗡𝗚-𝗧𝗘𝗥𝗠 𝗖𝗢𝗡𝗙𝗜𝗗𝗘𝗡𝗖𝗘\nScore: 5/10\n''Outlook depends on reform delivery''"]:::mixed

%% ========= RELATIONSHIPS =========
GE -->|Downside risks| GJ
FP -->|Constrains growth| GJ
MP -->|Anchors inflation| MS
MS -->|Enables| GJ
MP -->|Strengthens| FS
FS <-->|Depends on progress| SR
SR -->|Pace insufficient| LC
LC <-->|Feedback loop| GJ

%% ========= INVISIBLE LAYOUT CONTROL =========
ANCHOR[" "]:::anchor

%% ========= SUMMARY (FORCED BELOW, NO VISIBLE ARROWS) =========
SUM["𝗦𝗨𝗠𝗠𝗔𝗥𝗬\nWeighted average score: 5.05/10\n''Strong monetary and financial anchors\nsupport stability, but fiscal constraints and \nslow reform implementation \nkeep growth subdued.''"]:::summary
LC -.-> SUM:::anchor

%% ========= STYLES =========
classDef strong  fill:#E8F5E9,stroke:#1B5E20,stroke-width:1px,color:#111;
classDef neutral fill:#E3F2FD,stroke:#0D47A1,stroke-width:1px,color:#111;
classDef mixed   fill:#FFF8E1,stroke:#FF6F00,stroke-width:1px,color:#111;
classDef risk    fill:#FDECEA,stroke:#B71C1C,stroke-width:1px,color:#111;
classDef summary fill:#F5F5F5,stroke:#424242,stroke-width:1px,color:#111;
classDef anchor fill:transparent,stroke:transparent;

</div>

<p align="center">
<img  src="assets/images/legend.svg" width="400" alt="Legend">  
</p>

---
How does South Arica compare to other countries? Below is a graph where the same method was applied to 16 select countries.

- Affluent countries (with Switzerland as the highest scoring country)
- Emerging countries (with Myanmar as the lowest scoring country)
- GCC members
<div class="mermaid">

xychart-beta horizontal
    title "𝗖𝗢𝗨𝗡𝗧𝗥𝗬 𝗖𝗢𝗠𝗣𝗔𝗥𝗜𝗦𝗢𝗡 𝗢𝗙 𝗦𝗨𝗠𝗠𝗔𝗥𝗬 𝗦𝗖𝗢𝗥𝗘𝗦"
    x-axis ["𝗦𝗼𝘂𝘁𝗵 𝗔𝗳𝗿𝗶𝗰𝗮", "Switzerland", "Netherlands", "United States", "          United Kingdom", "𝘐𝘯𝘥𝘪𝘢", "𝘉𝘳𝘢𝘻𝘪𝘭", "𝘊𝘩𝘪𝘯𝘢", "𝘕𝘪𝘨𝘦𝘳𝘪𝘢", "𝘔𝘦𝘹𝘪𝘤𝘰", "𝘔𝘺𝘢𝘯𝘮𝘢𝘳", "UAE", "Saudi Arabia", "Qatar","Oman", "Kuwait", "Bahrain"]
    y-axis "Weighted average score across 8 measures" 0 --> 10
    bar [8.0, 5.1, 6.6, 5.7, 5.5, 6.6, 6.3, 5.7, 5.6, 5.1, 2.3, 7.1, 6.9, 6.8, 6.2, 6.0, 4.8]
    
</div>

---
Source: Various text-based documents from public institutions such the IMF World Bank, and local publications; Tellusant analysis
