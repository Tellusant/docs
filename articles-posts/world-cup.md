---
title: "World Cup Performance by Country 2002–2026"
description: "How have countries performed at the World Cup this century? A composite score by country is created by applying the Zipf distribution."
image: /assets/social-card-think.png
---
# World Cup Performance by Country 2002–2026
*Dr. Staffan Canback, Tellusant*  

How have countries performed at the World Cup this century? A composite score by country is created by applying the Zipf distribution.  

The Zipf distribution is a wonderful tool. It is for example used to understand the size-distribution of cities, and of companies. Datasets where the smallest value is zero are often Zipf-distributed.  

The formula is simple. The largest item has the weight 1; the second largest 1/2, third 1/3, and so on till the nth item with weight 1/n.  

We applied this in **two ways** to football performance for the seven world cups this century.  

- Each team that reached the round of 16 in a given year was given a Zipf weight. The gold medalist 1, silver 1/2, etc. This created 7 sets of 16 teams with weights.  

- The most recent year (2026) was given weight 1, down the most distant year (2002) with weight 1/7. (this is called recency adjustment) 

The two dimensions were finally combined to create a total score by country. Higher placement in recent years get the highest score.

The Zipf distribution favors high placement and recency strongly. Some may argue too strongly. Alternative distributions are, e.g., half-life and rectangular distributions. We have found Zipf often have the best characteristics, but there is no objective truth in choice.

The graph shows the ranking before the 2026 quarterfinals are played. All other data is final. This means that there will be some movement and we will update the graph after quarterfinals, semifinals, and final.

<p align="center">
<img  src="https://canback.net/docs/articles-posts/assets/images/s.canback-tellusant-world-cup-performance.svg" width="450" alt="S.Canback-Tellusant - World Cup performance">
</p>

This post is about Zipf primarily to illutrate its usefulness. We applied it to a popular topic to stimulate readership.
