---
title: "Nowcast: Sentiment Analysis of Economic Activity—Based on the Beige Book of June 3, 2026"
description: "The Fed's Beige Book, Summary of Commentary on Current Economic Conditions, covers current economic activity for the 12 Federal Reserve Districts. Tellusant converts it into a quantitative nowcast."
image: /assets/social-card-beig.png
---
# Nowcast: Sentiment Analysis of Economic Activity—Based on the Beige Book of June 3, 2026
The Fed's Beige Book, *[Summary of Commentary on Current Economic Conditions](https://www.federalreserve.gov/monetarypolicy/publications/beige-book-default.htm)*, covers current economic activity for the 12 Federal Reserve Districts. It is published sesqui-monthly (every 1½
months). Tellusant converts it into a quantitative nowcast.  

The Beige Book is useful for, among others, CEOs and management teams who want to quickly assess where the economy is at present.  

We compute a composite score for each of the twelve districts based on a **semantic analysis** of the report, then sum the scores weighted by the GDP of each district.  

We have published these nowcasts since June 2015 on LinkedIn. The new series published here starts in October 2025. The LinkedIn series can still be found there.

>Ther analysis is now entirely performed by our Fedora AI agent (v1.1.1). It consists of five parts:
>
>- ChatGPT = runtime environment
>- YAML = analytical serialization
>- Excel = model + parameters
>- Mermaid v11 = workflow graphing
>
>In the next cycle, ChatGPT will be replaced by a python script and a scheduler such as *cron* in GitHub Action.

---
*Updating on June 10*

Economic activity increased slightly in the June Beige Book, with conditions improving across a broader set of districts. National performance was higher than in the April Beige Book. 

<p align="center">
<img  src="assets/images/tellusant-fed-beige-book-summary-2026-06.svg" width="700" alt="Nowcast: Federal Reserve Beige Book Economic Activity">
</p>

Ten districts reported expansion, one was little changed, and one noted decline, indicating a more widely distributed but still low pace of growth. 

Underlying conditions point to continued support from demand and labor markets, though persistent price pressures remain a constraint on overall economic momentum.

<p align="center">
<img  src="assets/images/tellusant-fed-beige-book-contributing-factors-2026-04.svg" width="450" alt="Nowcast: Federal Reserve Beige Book contributing factors">
</p>

The GDP-weighted growth index edged down to 0.68, while both unweighted and weighted diffusion measures rose, suggesting that activity is becoming more evenly spread across regions. 

<p align="center">
<img  src="assets/images/tellusant-fed-beige-book-indexes-2026-04.svg" width="500" alt="Nowcast: Federal Reserve Beige Book key indexes">
</p>

Erratic government policies continue to damp growth. The Iran war is reflected in the Beige Book but has a small effect except on inflation.  
<br/>

---
#### [Archive](archive.md)

#### [Retrospective Comparison of Fed Beige Book Nowcast and Actual GDP Growth](retrospective.md)  

*ChatGPT was used for the entire analysis.*
