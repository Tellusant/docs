# Downside Risk Adjustment for Corporate Operating Risk

## Motivation

Traditional downside measures such as semivariance ignore all positive
observations. While appropriate in some contexts, they discard useful
information.

The proposed approach retains **all observations** while adjusting total
volatility according to whether variability has historically been
dominated by downside or upside outcomes.

## Step 1. Compute total volatility

\[ `\sigma `{=tex}= `\mathrm{StdDev}`{=tex}(g_t) \]

where (g_t) is the detrended growth series.

## Step 2. Compute upside and downside deviations

Using deviations from the expected growth path (preferred) or,
initially, the sample median:

\[ d_t=g_t-`\hat `{=tex}g_t \]

Define

\[ U=`\sum`{=tex}*{d_t\>0} d_t,`\qquad`{=tex}
D=`\sum`{=tex}*{d_t\<0}\|d_t\| \]

## Step 3. Downside asymmetry factor

\[ A=`\frac{D-U}{D+U}`{=tex} \]

Properties:

-   (A=0): balanced upside and downside
-   (A\>0): downside dominates
-   (A\<0): upside dominates
-   (-1`\le `{=tex}A`\le1`{=tex})

## Step 4. Amplification factor

\[ `\text{Amplification Factor}`{=tex}=1+A \]

## Step 5. Downside-adjusted volatility

\[ `\sigma`{=tex}\_{`\rm adj`{=tex}}=`\sigma`{=tex}(1+A) \]

## Interpretation

Separate two concepts:

1.  **Volatility ((`\sigma`{=tex}))** --- magnitude of fluctuations.
2.  **Downside asymmetry ((A))** --- whether fluctuations are
    predominantly unfavorable.

## Advantages

-   Uses all observations.
-   Preserves the interpretation of standard deviation.
-   Produces a bounded asymmetry measure.
-   Avoids the instability of the ratio (D/U).
-   Easy to explain.

## Suggested Reporting

For each company report:

-   Total volatility ((`\sigma`{=tex}))
-   Downside asymmetry factor ((A))
-   Amplification factor ((1+A))
-   Downside-adjusted volatility ((`\sigma`{=tex}\_{`\rm adj`{=tex}}))

## Future refinement

Use deviations from the expected growth path rather than the sample
median:

\[ d_t=g_t-`\hat `{=tex}g_t \]

This compares upside and downside relative to expected performance
rather than the historical center of the sample.
