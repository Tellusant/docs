# Normalized Differences and Bounded Transformations

*Discussion: September 8, 2026*

## Normalized difference

For the downside-risk work, the asymmetry measure is

$$
A=\frac{D-U}{D+U}
$$

where $D$ is cumulative downside deviation (positive magnitude) and $U$
is cumulative upside deviation.

The general form

$$
\frac{x-y}{x+y}
$$

is commonly described as a **normalized difference**. This is the
terminology adopted here.

For positive $x$ and $y$, it is bounded:

$$
-1 \leq \frac{x-y}{x+y} \leq 1
$$

and scale invariant:

$$
\frac{kx-ky}{kx+ky}=\frac{x-y}{x+y}.
$$

For operating risk:

-   $A=0$: balanced upside and downside.
-   $A>0$: downside dominates.
-   $A<0$: upside dominates.
-   $A=1$: entirely downside.
-   $A=-1$: entirely upside.

The associated amplification factor is

$$
1+A
$$

and downside-adjusted volatility is

$$
\sigma_{\mathrm{adj}}=\sigma(1+A).
$$

## A recurring preference in metric design

A broader methodological preference emerged: favor transformations that
improve mathematical behavior while preserving economic meaning.

Desirable properties often include:

1.  Boundedness, where appropriate.
2.  Scale invariance, where appropriate.
3.  Monotonicity.
4.  Dimensionlessness where useful.
5.  Economic interpretability.
6.  Ease of explanation.

A concise statement is:

> **Good transformations should simplify the mathematics without
> obscuring the economics.**

Examples include the Möbius transformation, normalized differences,
logarithms, and arithmetic-geometric interpolation.

## Existing Möbius transformation

The current transformation is

$$
M(x)=\frac{x}{x+2},
$$

corresponding to the general Möbius form

$$
\frac{ax+b}{cx+d}
$$

with $(a,b,c,d)=(1,0,1,2)$.

It has three useful economic anchors:

$$
M(0)=0,
$$

$$
M(-1)=-1,
$$

and

$$
\lim_{x\to+\infty}M(x)=1.
$$

Thus no change maps to $0$, a $-100\%$ change maps to $-1$, and
arbitrarily large positive growth approaches $+1$.

Its derivative is

$$
M'(x)=\frac{2}{(x+2)^2},
$$

so

$$
M'(0)=\frac{1}{2}.
$$

The drawback is therefore that small changes are approximately halved on
the transformed scale.

## Why the Möbius slope cannot simply be changed

For the general Möbius form

$$
f(x)=\frac{ax+b}{cx+d},
$$

requiring simultaneously

$$
f(0)=0,\qquad f(-1)=-1,\qquad
\lim_{x\to+\infty}f(x)=1
$$

fixes the relevant parameter relationships and reduces the
transformation, after normalization, to

$$
f(x)=\frac{x}{x+2}.
$$

Therefore

$$
f'(0)=\frac{1}{2}.
$$

There is no alternative within the Möbius family that preserves all
three anchors while doubling the slope at zero to $1$.

## Bounded extension with unit slope at zero

The desired properties can be obtained by extending the Möbius
transformation.

First define

$$
z=\frac{x}{x+2}.
$$

Then apply

$$
f(x)=\frac{2z}{1+z^2}.
$$

Substitution gives the closed form

$$
\boxed{f(x)=\frac{x^2+2x}{x^2+2x+2}}.
$$

This preserves

$$
f(-1)=-1,
$$

$$
f(0)=0,
$$

and

$$
\lim_{x\to+\infty}f(x)=1.
$$

But now

$$
\boxed{f'(0)=1}.
$$

Thus near zero,

$$
f(x)\approx x.
$$

Small changes retain approximately their original magnitude while large
changes remain compressed toward the bounds.

## Monotonicity

The derivative is

$$
f'(x)=\frac{4(x+1)}{(x^2+2x+2)^2}.
$$

On the economically feasible growth domain $x\geq-1$,

$$
f'(x)\geq0.
$$

The transformation is therefore monotonic throughout the relevant
domain.

## Interpretation

The extended transformation combines four desirable properties:

-   $-100\% \mapsto -1$;
-   $0\% \mapsto 0$;
-   $+\infty \mapsto +1$;
-   local slope at zero equals $1$.

The last property is especially intuitive because ordinary small changes
are approximately preserved:

$$
f(x)\approx x.
$$

The function is **not itself a Möbius transformation**. A suitable
description is a **Möbius-based bounded transformation**.

## Design implication

The comparison illustrates the broader design principle. The original
Möbius transformation has excellent bounds and economic anchors, but its
local scaling is less intuitive. Moving slightly beyond the Möbius
family preserves those anchors while obtaining unit local sensitivity.

A useful general criterion for applied economic metrics is therefore:

> **Preserve economically meaningful anchors and ordering, while
> choosing local behavior that remains intuitive around normal
> observations.**

## Inverse of the Möbius-based bounded transformation

For

$$
y=\frac{x^2+2x}{x^2+2x+2},
$$

multiply through by the denominator:

$$
y(x^2+2x+2)=x^2+2x.
$$

Rearranging gives

$$
(1-y)(x^2+2x)=2y,
$$

and therefore

$$
x^2+2x=\frac{2y}{1-y}.
$$

Completing the square,

$$
(x+1)^2
=
1+\frac{2y}{1-y}
=
\frac{1+y}{1-y}.
$$

On the economically relevant domain $x\geq-1$, take the positive square
root:

$$
\boxed{x=\sqrt{\frac{1+y}{1-y}}-1}.
$$

Thus the forward and inverse transformations are

$$
\boxed{y=\frac{x^2+2x}{x^2+2x+2}}
$$

and

$$
\boxed{x=\sqrt{\frac{1+y}{1-y}}-1}.
$$

Their domains are

$$
x\in[-1,\infty)
$$

and

$$
y\in[-1,1).
$$

For example, if $y=0.5$,

$$
x=\sqrt{3}-1\approx0.732.
$$

Thus a transformed value of $0.5$ corresponds to approximately $+73.2\%$
on the original growth scale.

The simple closed-form inverse is another useful property of the
transformation: transformed values can readily be converted back into
economically interpretable percentage changes.
