# Corporate Operating Risk – Discussion Notes

---
## Current Approach
- Measuring operating risk as standard deviation of YoY revenue growth over 40 quarters
- Using Möbius transformation for symmetry: f(x) = x / (x + 2)
- Including both revenue and cost volatility

---

## Möbius Transformation Details

Using parameters (a=1, b=0, c=1, d=2):

f(x) = x / (x + 2)

### Properties
- f(0) = 0
- Increasing function
- Maps [-1, ∞) → [-1, 1)
- f(-1) = -1 (respects -100% bound)
- Compresses large positive values

### Behavior
- Near zero: approximately linear (slope ≈ 0.5)
- Downside: more spread near -1
- Upside: increasingly compressed

### Implication
- Not mathematically symmetric
- Economically meaningful asymmetry (downside bounded, upside unbounded)

---

## Key Model Enhancements

### 1. Detrending
- Remove growth trend before computing volatility
- Use residual-based volatility

### 2. Downside Risk
- Semi-variance (focus on negative outcomes)
- Compare with transformed volatility

### 3. Cost–Revenue Interaction
- Compute elasticity: ΔCost / ΔRevenue
- Or correlation between cost and revenue changes

Interpretation:
- High elasticity → flexible cost structure → lower risk
- Low elasticity → rigid costs → higher risk

---

### 4. Shock vs Structural Volatility
- Use AR(1) model
- Decompose:
  - Persistent variance (cyclical)
  - Residual variance (true uncertainty)

---

### 5. Time-Scale Effects
- Compare:
  - Quarterly YoY volatility
  - Multi-year (e.g., 3-year CAGR) volatility

---

### 6. Macro Sensitivity (GDP)
Model:
g_firm = α + β g_GDP + ε

Decompose:
- Systematic risk: β × σ_GDP
- Idiosyncratic risk: σ(ε)

---

### 7. Regime Instability
- Rolling volatility (e.g., 12 quarters)
- Variance of volatility

---

### 8. Distribution Shape
- Skewness
- Kurtosis (tail risk)

---

## Composite Structure

### A. Core Uncertainty
- Detrended revenue volatility
- Idiosyncratic volatility

### B. Operating Leverage
- Cost elasticity
- Margin volatility

### C. Downside / Convexity
- Semi-variance
- Transform vs raw gap

### D. Stability
- Volatility of volatility
- Regime shifts

---

## Generalization of Möbius Transform

f_k(x) = x / (x + k), k > 1

- Smaller k → stronger curvature
- Larger k → closer to linear
- k = 2 is a balanced choice

---

## Practical Recommendation
- Keep current Möbius transform
- Report both raw and transformed volatility
- Add:
  - Cost–revenue elasticity
  - GDP decomposition
  - Volatility-of-volatility

---

## Key Insight
The model is already strong; further improvements come from:
- Structure
- Decomposition
- Interpretation

rather than adding more raw metrics.
