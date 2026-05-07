# Akaike Information Criterion (AIC) for Comparing Models

$$AIC = - 2\ln(\hat{L}) + 2k\qquad\ (general\ definition)$$

$$AIC = n\ln\left(\frac{SSE}{n}\right) + 2k\qquad\ (statistical\ analysis\ definition)$$

$$ n = \text{number of observations}$$

$$SSE = sum\ of\ squared\ errors = \sum_{i=1}^{n}(y_i - \hat{y}_i)^2$$

$$k = \text{number of estimated parameters}$$

AIC evaluation works by taking the difference between AIC (model A) and AIC (model B): AIC(A) – AIC(B)

Burnham-Anderson criteria

| ΔAIC | Interpretation |
|----------|----------|
| 0–2 | Essentially equivalent |
| 4–7 | Some support for lower model |
| >10 | Very strong evidence for lower AIC model |

Akaike called it an "entropy maximization principle". Compare with Shannon information entropy equation (one of many ways to express it):

$$H = -\sum_{i=1}^{n} p_i \ln p_i$$
