---
title: "Nowcast: Sentiment Analysis of Economic Activity Based on the Beige Book of April 15, 2026"
description: "The Fed's Beige Book, Summary of Commentary on Current Economic Conditions, covers current economic activity for the 12 Federal Reserve Districts. Tellusant converts it into a quantitative nowcast."
image: /assets/social-card-beig.png
---
# Nowcast: Sentiment Analysis of Economic Activity Based on the Beige Book of April 15, 2026
The Fed's Beige Book, *[Summary of Commentary on Current Economic Conditions](https://www.federalreserve.gov/monetarypolicy/publications/beige-book-default.htm)*, covers current economic activity for the 12 Federal Reserve Districts. It is published sesqui-monthly (every 1 1/2 month). Tellusant converts it into a quantitative nowcast.  

The Beige Book is useful for, among others, CEOs and management teams who want to quickly assess where the economy is at present.  

We compute a composite score for each of the twelve districts based on a **semantic analysis** of the report, then sum the scores weighted by the GDP of each district.  

We have published these nowcasts since June 2015 on LinkedIn. The new series published here starts in October 2025. The LinkedIn series can still be found there.

---

>Our analysis is now entirely performed by our Fedora AI agent (v1.1.1). It consists of three parts:
>
>- ChatGPT = runtime environment
>- YAML = serialization algorithm
>- Excel = model + parameters
>
>In the next cycle, ChatGPT will be replaced by a python script and a scheduler such as GitHub Action.

<p align="center">
<img  src="assets/images/tellusant-fed-beige-book-summary-2026-04.svg" width="700" alt="Nowcast: Federal Reserve Beige Book Economic Activity">
</p>

The April 2026 report shows only slight growth. Performance is diverging significantly with some districts doing well, others doing poorly.  

Three districts doing relatively well:  
- Atlanta  
- Cleveland  
- Richmond  

Poor performers are:  
- Boston  
- New York   

The rest are flat or show slight growth.  

The key resulting national indexes are reported below:  

<p align="center">
<img  src="assets/images/tellusant-fed-beige-book-indexes-2026-04.svg" width="500" alt="Nowcast: Federal Reserve Beige Book key indexes">
</p>

Erratic government policies continue to damp growth. The Iran war is not reflected in the Beige Book yet.  
<br/>

> A new feture is a breakdown of contributing factors to the scores. These are also created through semantic analysis of the beige book.

<p align="center">
<img  src="assets/images/tellusant-fed-beige-book-contributing-factors-2026-04.svg" width="500" alt="Nowcast: Federal Reserve Beige Book contributing factors">
</p>

---
#### [Archive](archive.md)

#### [Retrospective Comparison of Fed Beige Book Nowcast and Actual GDP Growth](retrospective.md)  
