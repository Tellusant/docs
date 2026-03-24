# The General and Special Models for Demand Forecasting

## General Model

Schematically, the general model looks like this:

<p align="center">
<img  src="images/eq/tgde.svg" width="500" alt="">
</p>

This is the equation for a "raw" regression:

$$(1) \quad \Delta y_t= \alpha+ \sum_{k \in \mathcal{LF}} \beta_k(L)\,\Delta x_{k,t}+ \sum_{j \in \mathcal{HF}} \gamma_j(L)\,\Delta w_{j,t}+ u_t,\quad u_t \sim \text{ARIMA(p,d,q)}$$

We often prefer to run a de-trended, stationary model in differences which has a slight modification in the timeseries part:

$$(2) \quad \Delta y_t= \alpha+ \sum_{k \in \mathcal{LF}} \beta_k(L)\,\Delta x_{k,t}+ \sum_{j \in \mathcal{HF}} \gamma_j(L)\,w_{j,t}+ u_t,\quad u_t \sim \text{ARMA(p,q)}$$

*(L)* means that a lag term may be included. *LF* = Low frequency (long-term influences on demand) such as population growth; *HF* = High frequency (short-term influences on demand) such as unemployment. Price often shows up as both *LF* and *HF*  with *HF* usually more important.

Note the subtle variations: *(1)* has *Δw* while (2) has *w* since it is already differenced. *(1)* has *ARIMA(p,d,q)* while (2) has *ARMA(p,q)* since *d* disappears when differencing. 

Note that *LF* or *HF* coefficients may be calculated in a separate model and elasticities then set as static.

These are ARIMAX equations, but with a clear distinction between long-term and short-term independent variables and the timeseries component.

## Special Models

<p align="center">
<img  src="../assets/images/eq/tgdelt1.svg" width="500" alt="">
</p>

Once one of these basic equations are modelled and understood, more complex models may be pursued.
