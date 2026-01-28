---
title: "South Africa Economic & Policy Sentiment Analysis Leveraging AI"
description:  "This article shows how we use semantic analysis of qualitative reports using automated parsing, scoring and weighting, leveraging a trained AI model."
image: /assets/social-card-pub.png
---

# South Africa Economic & Policy Sentiment Analysis Leveraging AI
This article shows how we use semantic analysis of qualitative reports using automated parsing, scoring and weighting, leveraging a trained AI model.

In 2017, our chairman, Staffan Canback, wrote an opinion piece in the South African newspaper Business Times: [_Ending South Africa's Forever Recession_](https://www.linkedin.com/pulse/ending-south-africas-forever-recession-staffan-canback-g0fye/?trackingId=Xxg5IuUvTTiH%2BUic5XKbZQ%3D%3D). As part of the background analysis, he did a semantic analysis of South Africa's economic and policy contect. Even in 2017 it was possible to do this with word cloud tools. Primitive, but they worked.

In 2024, the article was updated. By then, modern AI tools were available to perform the semantic analysis. The analysis was updated in early 2026, incorporating the latest reports on the country. All aspects of the analyses are automated except the final quality control.

The graph below shows our latest assessment. As a semantic analysis, it evaluates the qualitative wording in the reports instead of looking at quantitative data. It then converts this into scores in eight categories. The scores are weighted and summarized into an overall index. The weights differ by country.

The bottom graph shows the summary for 16 countries to give more context to the South African assessment. We can replicate this for most countries in the world, with the full details.

The graphs are made with Mermaid, a visualization tool with almost no formatting capability. It is suitable for demos and proof-of concept efforts, like here.

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
classDef strong  fill:#E8F5E9,stroke:#1B5E20,stroke-width:2px,color:#111;
classDef neutral fill:#E3F2FD,stroke:#0D47A1,stroke-width:2px,color:#111;
classDef mixed   fill:#FFF8E1,stroke:#FF6F00,stroke-width:2px,color:#111;
classDef risk    fill:#FDECEA,stroke:#B71C1C,stroke-width:2px,color:#111;
classDef summary fill:#F5F5F5,stroke:#424242,stroke-width:2px,color:#111;
classDef anchor fill:transparent,stroke:transparent;

</div>

<p align="center">
<img  src="assets/images/legend.svg" width="400" alt="Legend">  
</p>

---
How does **South Africa** compare to other countries? Below is a graph where the same method was applied to 16 select countries.

- Affluent countries (with Switzerland as the highest scoring country)
- 𝙀𝙢𝙚𝙧𝙜𝙞𝙣𝙜 𝙘𝙤𝙪𝙣𝙩𝙧𝙞𝙚𝙨 (with Myanmar as the lowest scoring country)
- 𝙶𝙲𝙲 𝚖𝚎𝚖𝚋𝚎𝚛𝚜 (chosen to show how neighboring countries can differ)
<div class="mermaid">

xychart-beta horizontal
    title "𝗖𝗢𝗨𝗡𝗧𝗥𝗬 𝗖𝗢𝗠𝗣𝗔𝗥𝗜𝗦𝗢𝗡 𝗢𝗙 𝗦𝗨𝗠𝗠𝗔𝗥𝗬 𝗦𝗖𝗢𝗥𝗘𝗦"
    x-axis ["𝗦𝗼𝘂𝘁𝗵 𝗔𝗳𝗿𝗶𝗰𝗮", "Switzerland", "Netherlands", "United States", "United Kingdom", "𝙄𝙣𝙙𝙞𝙖", "𝘽𝙧𝙖𝙯𝙞𝙡", "𝘾𝙝𝙞𝙣𝙖", "𝙉𝙞𝙜𝙚𝙧𝙞𝙖", "𝙈𝙚𝙭𝙞𝙘𝙤", "𝙈𝙮𝙖𝙣𝙢𝙖𝙧", "𝚄𝚗𝚒𝚝𝚎𝚍 𝙰𝚛𝚊𝚋 𝙴𝚖𝚒𝚛𝚊𝚝𝚎𝚜", "𝚂𝚊𝚞𝚍𝚒 𝙰𝚛𝚊𝚋𝚒𝚊", "𝚀𝚊𝚝𝚊𝚛","𝙾𝚖𝚊𝚗", "𝙺𝚞𝚠𝚊𝚒𝚝", "𝙱𝚊𝚑𝚛𝚊𝚒𝚗"]
    y-axis "Weighted average score across 8 measures" 0 --> 10
    bar [8.0, 5.1, 6.6, 5.7, 5.5, 6.6, 6.3, 5.7, 5.6, 5.1, 2.3, 7.1, 6.9, 6.8, 6.2, 6.0, 4.8]
    
</div>

---
Source: Various text-based documents from public institutions such the IMF World Bank, and local publications; Tellusant analysis
