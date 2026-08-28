---
title: " Country and Firm Productivity Decomposition Using Cobb-Douglas and Solow"
description: "There are three primitives in the Tellusant strategy grid: growth, productivity, and risk. Here I show how productivity is defined and easily calculated."
image: /assets/social-card-pub.png
---

# Country and Firm Productivity Decomposition Using Cobb-Douglas and Solow
*By Dr Staffan Canback, Tellusant*

I have worked on developing the [Tellusant strategy grid](../articles-posts/strategy-grid.md). There are three primitives in the Tellusant strategy grid: growth, productivity, and risk. Here I show how productivity is defined and easily calculated.

One of the strengths of my productivity framework is that it works for both countries and companies. Because I use the same underlying definitions, I can directly compare national productivity and firm productivity.

The math is simple. This is a mechanical, deterministic model, not statistical. It is fully explained in Solow growth economics. The growth model is widely used at the national level, less so at the firm level. Hardly any CEOs know their company's productivity levels or how to measure them.  

Only five data series need to be collected and are readily available at country and firm level. I used UN National Accounts and TelluBase for countries, and MacroTrends (complemented by Gemini) for companies.

---
## Starting Point
The basic production function is:  

$$
Y = A K^{\alpha} L^{1-\alpha}
$$

where:  

- $(Y) = \text{output (GDP, value added, gross profit, or revenue)}$
- $(A) = \text{total factor productivity (TFP) = Solow residual}$  
- $(K) = \text{capital input, with capitalized } \mathrm{R\&D} \text{ included}$ 
- $(L) = \text{labor input}$  
- $(\alpha) = \text{capital share}$  
- $(1-\alpha) = \text{labor share}$

---

## Growth Accounting

Establishing growth rates (that follow from taking logarithms of above equation):

$$
g_Y = g_A + \alpha g_K + (1-\alpha)g_L
$$

where:

- $(g_Y) = \text{output growth}$
- $(g_A) = \text{TFP growth}$
- $(g_K) = \text{capital growth}$
- $(g_L) = \text{labor growth}$

Rearranging:

$$
g_A = g_Y - \alpha g_K - (1-\alpha)g_L
$$

This is the standard TFP calculation from economic theory already implemented in my model.

---

## Labor Productivity

Labor productivity is:

$$
\frac{Y}{L}
$$

Substituting the Cobb-Douglas production function:

$$
\frac{Y}{L}
=
A\left(\frac{K}{L}\right)^{\alpha}
$$

Taking growth rates:

$$
g_{Y/L}
=
g_A
+
\alpha(g_K-g_L)
$$

This yields an intuitive decomposition:

$$
\text{Labor Productivity Growth}
=
\text{TFP Growth}
+
\text{Capital Deepening}
$$

where:

$$
\text{Capital Deepening Contribution}
=
\alpha(g_K-g_L)
$$

---

## Capital Productivity

Capital productivity is:

$$
\frac{Y}{K}
$$

Substituting the Cobb-Douglas production function:

$$
\frac{Y}{K}
=
A\left(\frac{L}{K}\right)^{1-\alpha}
$$

Taking growth rates:

$$
g_{Y/K}
=
g_A
+
(1-\alpha)(g_L-g_K)
$$

This yields:

$$
\text{Capital Productivity Growth}
=
\text{TFP Growth}
+
\text{Labor Deepening}
$$

where:

$$
\text{Labor Deepening Contribution}
=
(1-\alpha)(g_L-g_K)
$$

---

## Interpretation

Three productivity measures can now be reported:

| Measure | Formula |
|----------|----------|
| TFP Growth | $\(g_A\)$ |
| Labor Productivity Growth | $\(g_A+\alpha(g_K-g_L)\)$ |
| Capital Productivity Growth | $\(g_A+(1-\alpha)(g_L-g_K)\)$ |

The decomposition separates:

1. Pure efficiency improvement (TFP)
2. Capital deepening
3. Labor deepening

---

## Why This Matters

For countries:

- Capital and labor growth tend to be relatively smooth.
- Labor productivity and TFP often move together.

For firms:

- Capital growth and labor growth can diverge dramatically.
- Labor productivity may rise because of capital deepening rather than efficiency gains.
- TFP helps identify genuine operational improvement.

Examples:

- Amazon: strong capital accumulation and labor growth, but weak measured TFP.
- Microsoft: both capital deepening and positive TFP.
- Coca-Cola: labor reduction can boost labor productivity even when TFP is modest.

As a result, the decomposition is often more informative at the firm level than at the country level.

---

## Reporting Framework

| Metric | Growth |
|----------|----------:|
| Output Growth | x.x% |
| TFP Growth | x.x% |
| Labor Productivity Growth | x.x% |
| Capital Deepening Contribution | x.x% |
| Capital Productivity Growth | x.x% |
| Labor Deepening Contribution | x.x% |

Identities:

$$
\text{Labor Productivity Growth}
=
\text{TFP Growth}
+
\text{Capital Deepening Contribution}
$$

and

$$
\text{Capital Productivity Growth}
=
\text{TFP Growth}
+
\text{Labor Deepening Contribution}
$$

This provides a consistent framework for analyzing both countries and companies.
