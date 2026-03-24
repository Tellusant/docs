# The General and Special Forecasting Models for Demand

Schematically, the general model looks like this:

<p align="center">
<img  src="../assets/images/eq/tgde.svg" width="500" alt="">
</p>

This is the equation for a "raw" regression:

$$\Delta y_t= \alpha+ \sum_{k \in \mathcal{LF}} \beta_k(L)\,\Delta x_{k,t}+ \sum_{j \in \mathcal{HF}} \gamma_j(L)\,w_{j,t}+ u_t,\quad u_t \sim \text{ARIMA(p,d,q)}$$

We often prefer to run a de-trended, stationary model in differences which has a slight modification in the timeseries part:

$$\Delta y_t= \alpha+ \sum_{k \in \mathcal{LF}} \beta_k(L)\,\Delta x_{k,t}+ \sum_{j \in \mathcal{HF}} \gamma_j(L)\,w_{j,t}+ u_t,\quad u_t \sim \text{ARMA(p,q)}$$

*(L)* means that a lag term may be included. *LF* = Low frequency (long-term influences on demand) such as population growth; *HF* = High frequency (short-term influences on demand) such as unemployment. Price often shows up as both *LF* and *HF*  with *HF* usually more important.

Note that *LF* or *HF* coefficients may be calculated in a separate model and elasticities then set as statics.

These are ARIMAX equations, but with a clear distinction between long-term and short-term independent variables.

Once one of these basic equations are modelled and understood, more complex models may be pursued.
