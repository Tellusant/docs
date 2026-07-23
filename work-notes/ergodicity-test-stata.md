# Testing Ergodicity in Panel Data (Stata)

## Key Point

There is **no standard Stata command that directly tests ergodicity**.
Ergodicity is a property of the underlying stochastic process rather
than a finite sample. Instead, researchers test properties that imply or
are consistent with ergodicity.

------------------------------------------------------------------------

## 1. Test for Stationarity

Most econometric applications assume a process is ergodic if it is:

-   Stationary
-   Weakly dependent (mixing)
-   Has finite moments

Typical Stata commands:

``` stata
xtunitroot llc y
xtunitroot ips y
xtunitroot fisher y

* Single time series
dfuller y
pperron y
kpss y
```

------------------------------------------------------------------------

## 2. Compare Time and Cross-Sectional Averages

A defining property of ergodicity is that long-run time averages
converge to the corresponding ensemble (cross-sectional) averages.

Compute both:

``` stata
bysort year: egen csmean = mean(y)
bysort id: egen timemean = mean(y)

summ csmean
summ timemean

histogram timemean
```

Evidence supporting ergodicity would be that the distribution of time
averages approaches the cross-sectional distribution as the time
dimension grows.

------------------------------------------------------------------------

## 3. Examine Heterogeneity

Persistent differences across individuals may indicate non-ergodicity.

``` stata
bys id: egen mu = mean(y)
bys id: egen sd = sd(y)
```

Large differences in means or variances suggest heterogeneous underlying
processes.

------------------------------------------------------------------------

## 4. Examine Persistence

Ergodic stationary processes generally exhibit declining
autocorrelation.

Useful commands:

``` stata
corrgram y
xtreg y L.y
xtregar
```

Near-unit-root behavior or highly persistent autocorrelation argues
against practical ergodicity.

------------------------------------------------------------------------

## 5. Ergodicity Economics (Ole Peters)

In ergodicity economics, compare:

-   **Ensemble-average growth**
-   **Time-average growth**

Example:

``` stata
gen growth = (wealth-L.wealth)/L.wealth
gen loggrowth = ln(1+growth)

summ growth
summ loggrowth
```

If the arithmetic and logarithmic growth rates differ substantially, the
process is non-ergodic.

------------------------------------------------------------------------

## Practical Workflow

For a panel dataset, a practical assessment of ergodicity consists of:

1.  Testing for stationarity.
2.  Examining heterogeneity across units.
3.  Evaluating autocorrelation and persistence.
4.  Comparing time averages with cross-sectional averages.
5.  Checking parameter stability over time.

This combination provides much stronger evidence than any single
"ergodicity test."
