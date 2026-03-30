#  Ex-post and Ex-ante Validation of Statistical Models

## Validation Design
We evaluate model performance using a pseudo out-of-sample holdout framework. For each specification, the model is estimated using data available up to a fixed forecast origin (training window of 5–20 years). Let Yₜ denote the dependent variable and Xₜ the vector of independent variables. The model is estimated using observations {Yₜ, Xₜ } for t ≤ T, and forecasts are generated for t = T+1, …, T+H (H = e.g., 5 years horizon in our application).  

[g]

Importantly, forecasts over the holdout period are constructed conditional on the realized values of the independent variables. That is, forecasts take the form Ŷ where Xₜ are the actual observed values in the holdout period, rather than forecasts of Xₜ that would have been available at time T.  

Forecast accuracy is assessed using symmetric Mean Absolute Percentage Error (MAPE) over the holdout period, using a Möbius[1,0,1,2] transformation.  

## Interpretation
This evaluation corresponds to a conditional ex-post forecast (conditional on X being known) rather than a fully operational ex-ante forecast. As such, it measures the model’s ability to map predictors Xₜ to outcomes Yₜ assuming perfect knowledge of future Xₜ.  

The resulting accuracy metrics therefore isolate the contribution of model specification and parameter estimation, and the structural relationship between X and Y, while avoiding errors arising from forecasting Xt themselves.  

This distinction is standard in the forecasting literature, where conditional (ex-post) forecasts are used to assess the intrinsic predictive power of a model separately from upstream predictor forecasts (Hyndman & Athanasopoulos, 2021).  

## Limitations
Because the evaluation assumes knowledge of future Xₜ, reported accuracy should not be interpreted as directly representative of real-time forecasting performance. In practical applications where Xₜ must themselves be forecast, total forecast error will generally be larger.  

To complement this, an operational ex-ante analysis should be conducted, if feasible, using only information available at time T, including forecasted independent variables Xₜ.  

## Summary
The conditional holdout approach provides a diagnostic of whether the model Yₜ = f(Xₜ) is well-specified. When paired with ex-ante validation, it enables decomposition of forecast error into model error (structure/fit) and input error (forecast error in Xₜ).   

This dual evaluation framework is widely used in empirical forecasting applications, including settings where forecasts are conditioned on realized predictors (Ferraro, Rogoff, and Rossi, 2015).  

---
**References**
Tashman, L.J. (2000). Out-of-Sample Tests of Forecasting Accuracy: An Analysis and Review. International Journal of Forecasting.  
Ferraro, D., K. Rogoff, and B. Rossi (2015). Can Oil Prices Forecast Exchange Rates? NBER Working Paper.  
Hynman, R.J., & G. Athanasopoulos (2021). Forecasting: Principles and Practice (3rd ed.).  
