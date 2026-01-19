---
title: "Nowcast: Probability of a U.S. Recession Nine Months Out"
description: "Building on Ben Bernanke's recession probability model, we invented a better model using exactly the same the data. Bernanke and the Fed uses a P controller, we use a P.I.D controller. The improvement is large."
image: /assets/social-card-recession.png
---
# Nowcast: Probability of a U.S. Recession Nine Months Out  
Building on Ben Bernanke's widely used recession probability model, we invented a better model using exactly the same  data. Bernanke and the Fed uses a P controller, we use a P.I.D controller. The improvement is large.  

We have published this nowcast since 2006 until 2025 with Bernanke's specification, and now with Tellusant's improved method. The method is described below the graph.

---
### November 28, 2025: Probability 18%

<iframe src="https://tellubase.com/recession-predictor/" height="1000"></iframe>


<p align="center">
<img  src="assets/images/tellusant-recession-nowcast.svg" width="800" alt="Nowcast: U.S. recession probability 6 months out">
</p>

---
### Method
Prof. Ben Bernanke, later chairman of the Federal Reserve, in 1990 developed a method to find the probability of future recessions. He kept the model simple using only the term spread between long-term bills and short-term bonds and applied to a probit model with actual recessions, as determined by the National Bureau of Economic Research (NBER), as the dependent binary variable.

The beauty of the model is its simplicity. Bernanke did not try to find funky variables that would work for a while. Instead, he had a sound theoretical reason for why the term spread is suitable.

Tellusant has developed a new version of the model. We wanted to use exactly the same data, avoiding variable fishing that may work for a while, but is spurious.

The Bernanke model is proportional. It uses a P controller with 12 months lag. It means the prediction is 12 months out.

We used P and added integral I and derivative D elements (working on the same term spread data). That is, a P.I.D. controller. The periods for both I and D were found to be nine months, while P remains at 12 months. This P.I.D model has an optimum at 9 months prediction horizon (found by reviewing the [differenced cross-correlation function](assets/images/tellusant-recession-ccf.svg)).

Comparing the Aikake Information Criterion tells us that there is close to zero probability that the Bernanke model is better. This is seen visually because the Tellusant model gives significantly stronger positives than the Bernanke model).

Neither the Tellusant nor Bernanke model are perfect. Both give false positives occasionally (notably in 2025; although once NBER makes its determination there may be a recession in 2025, although shallow), but so far no false negatives. 

---
For more on the Bernanke and Federal Reserve's method:  
[Bernanke (1990): *Predictive Powers of Interest Rates*. NBER.](assets/pdf/bernanke-predictive-powers-of-interest-rates.pdf)  
[Estrella and Rubin (2006): *The Yield Curve as a Leading Indicator*. Federal Reserve Bank of New York](assets/pdf/estrella-and-rubin-the-yield-curve-as-a-leading-indicator.pdf)
