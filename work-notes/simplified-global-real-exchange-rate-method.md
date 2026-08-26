# Simplified Global Real Exchange Rate Method for Volatility Measurement
Thoughts for   Q-Risk

## Initial question by SC

*Idea for differential inflation adjusted exchange rates (real XR).*  

I have a model that calculates RER in such a way that the US exchange varies over time and is not the reference currency. However, while correct, the model is too cumbersome to use in practice.  

How about this. 1) I calculate global inflation and I assume I do this correctly (I will use Mobius transfromation to avoid high inflation countries to unduly influence the numbers). 2) I calculet a countries RER with its US exchange rate and adjusted for differential inflation against my global inflation (this would also apply to the USD with the difference between US inflation and my global inflation). 3) all currencies would then have a sort of RER, including the US. 

I am doing this to calculate XR volatility so I take the std dev of my results. Does this make sense? It is a much faster method than I currently have and I know exactly how to do this.

## Objective

The objective is to construct a practical measure of differential-inflation-adjusted exchange rates (real exchange rates, RERs) for a large set of countries and then use the standard deviation of the resulting changes as a measure of exchange-rate volatility.

The existing model calculates RERs in a way that allows the US dollar itself to vary over time rather than treating it as the fixed reference currency. While theoretically satisfactory, the model is cumbersome to use in practice. A simpler method is therefore desirable, provided it retains the essential economics.

## Initial Proposed Approach

The proposed simplification is:

1. Calculate a measure of **global inflation**. This is assumed to be calculated appropriately. A Möbius transformation can be used so that countries experiencing very high inflation do not unduly influence the global measure.

2. For each country, start with its nominal exchange rate against the US dollar and adjust it for the country's inflation differential relative to **global inflation**, rather than relative to US inflation.

3. Apply the same inflation adjustment to the United States. Thus, the US also receives an RER-like measure based on the difference between US inflation and global inflation.

4. Calculate the standard deviation of the resulting RER changes to obtain a measure of real exchange-rate volatility.

This approach is substantially faster and easier to implement than the existing model.

## Basic Formulation

Let:

- $e_{i,t}$ = log nominal exchange rate of country $i$ against USD,
- $\pi_{i,t}$ = inflation in country $i$,
- $\pi^G_t$ = global inflation.

Ignoring sign-convention differences in the definition of the nominal exchange rate, the proposed change in the inflation-adjusted exchange rate is:

$$
\Delta r_{i,t}=
\Delta e_{i,t}
+
\pi^G_t-\pi_{i,t}
$$

For the United States, the nominal USD/USD exchange rate is constant, so:

$$
\Delta e_{US,t}=0
$$

and therefore:

$$
\Delta r_{US,t}=
\pi^G_t-\pi_{US,t}
$$

This gives every country, including the United States, a measure relative to the same global inflation benchmark.

## An Attractive Consistency Property

Consider the difference between the measure for country $i$ and that for the United States:

$$
\Delta r_{i,t}-\Delta r_{US,t}
$$

Substitution gives:

$$
\Delta e_{i,t}+\pi^G_t-\pi_{i,t}-(\pi^G_t-\pi_{US,t})
$$

$$
\Delta e_{i,t}+\pi^G_t-\pi_{i,t}-(\pi^G_t-\pi_{US,t})
$$

so that:

$$
\boxed{\Delta r_{i,t}-\Delta r_{US,t}=\Delta e_{i,t}+\pi_{US,t}-\pi_{i,t}}
$$

This is the conventional bilateral real exchange-rate change against the United States.

Thus, introducing global inflation as the common benchmark does not destroy the standard bilateral economic relationship. The global inflation term cancels when two currencies are compared.

## Limitation of the Basic Approach

There is one important limitation.

For a non-US country, the measure contains both:

1. nominal exchange-rate movement against USD, and
2. the country's inflation differential against global inflation.

For the United States, however, it contains only:

$$
\pi^G_t-\pi_{US,t}
$$

There is no nominal exchange-rate movement for the USD itself.

Consequently, the USD is no longer the **inflation benchmark**, but it remains the implicit **nominal exchange-rate benchmark**.

This may be acceptable if the intended interpretation is:

> How volatile is a country's inflation-adjusted USD exchange rate relative to a common global inflation environment?

However, it is less satisfactory if the intended interpretation is:

> How volatile is each currency's real value relative to the world, treating the USD in the same way as every other currency?

For the latter objective, a small extension solves the problem.

## Preferred Method: Add a Global Nominal Exchange-Rate Factor

Construct a global nominal exchange-rate movement from the individual USD exchange rates:

$$
\Delta e^G_t=\sum_i w_i \Delta e_{i,t}
$$

where $w_i$ are appropriate country weights.

Then calculate each country's nominal movement relative to this global nominal factor:

$$
\Delta e_{i,t}-\Delta e^G_t
$$

The full global real exchange-rate change becomes:

$$
\boxed{
\Delta RER_{i,t}=(\Delta e_{i,t}-\Delta e^G_t)+(\pi^G_t-\pi_{i,t})}
$$

This is the preferred simplified method.

It has two components:

$$
\text{Global RER change}=\text{relative nominal FX change}+\text{relative inflation change}
$$

Both components are therefore measured relative to a global benchmark.

## Treatment of the United States

For the United States:

$$
\Delta e_{US,t}=0
$$

because the underlying exchange-rate database expresses currencies against USD.

The US measure nevertheless becomes:

$$
\boxed{\Delta RER_{US,t}=-\Delta e^G_t+(\pi^G_t-\pi_{US,t})}
$$

The USD now moves just like every other currency.

For example, if the USD appreciates broadly against world currencies, the average USD exchange rate of other currencies moves in the opposite direction. The global nominal factor captures this movement, and the US receives the corresponding relative nominal appreciation.

This eliminates the main weakness of the simpler initial proposal.

## Bilateral Consistency Is Preserved

An especially useful property is that the global terms disappear when two countries are compared.

For countries $i$ and $j$:

$$
\Delta RER_i-\Delta RER_j
$$

equals:

$$
(\Delta e_i-\Delta e^G+\pi^G-\pi_i)-(\Delta e_j-\Delta e^G+\pi^G-\pi_j)
$$

and therefore:

$$
\boxed{\Delta RER_i-\Delta RER_j=\Delta e_i-\Delta e_j+\pi_j-\pi_i}
$$

Both global inflation and the global nominal exchange-rate factor cancel.

Thus, the simplified global construction preserves the economically relevant bilateral real exchange-rate relationships while providing a common global reference point.

## Volatility Measure

Because the purpose of the exercise is to measure exchange-rate volatility, the standard deviation should preferably be calculated from **changes** in the RER rather than from its level:

$$
\boxed{\sigma_{RER,i}=SD(\Delta RER_{i,t})}
$$

Using changes avoids confusing a persistent trend in the real exchange-rate level with volatility.

The resulting statistic can therefore be interpreted as the typical variability of a country's real currency movement relative to the global benchmark.

## Möbius Transformation

The Möbius transformation can be useful in constructing the global benchmark, particularly for inflation.

Very high inflation countries can otherwise have disproportionate influence on an arithmetic global inflation measure. Transforming the underlying inflation changes before aggregation can bound the influence of extreme observations while retaining their direction and relative magnitude.

The same principle could potentially be applied to extreme nominal exchange-rate changes if large devaluations create similar aggregation problems.

The important point is that the global inflation and nominal FX aggregates should be constructed consistently and with weights appropriate to the intended economic interpretation.

## Recommended Practical Specification

The preferred practical approach is therefore:

$$
\boxed{\Delta RER_{i,t}=(\Delta e_{i,t}-\Delta e^G_t)+(\pi^G_t-\pi_{i,t})}
$$

with:

$$
\Delta e^G_t=\sum_i w_i\Delta e_{i,t}
$$

and a robust global inflation measure $\pi^G_t$, potentially using the Möbius transformation to limit the influence of extreme inflation.

Finally:

$$
\boxed{RERVol_i=SD(\Delta RER_{i,t})}
$$

This approach appears to capture most of the conceptual advantage of the existing more cumbersome model while being substantially easier to calculate, explain, maintain, and reproduce.

## Conclusion

Three approaches can be distinguished:

1. **Global inflation adjustment only.** Simple and useful, but USD remains the implicit nominal exchange-rate anchor.

2. **Global inflation adjustment plus a global nominal FX factor.** Still straightforward to calculate, treats the USD as a moving currency, and preserves bilateral real exchange-rate relationships.

3. **Full existing RER model.** Potentially more theoretically elaborate, but operationally cumbersome.

**Approach 2 is the preferred solution.** It provides a global rather than US-centered measure of real currency movement without requiring the complexity of the existing model. For the ultimate purpose—cross-country measurement of real exchange-rate volatility—it offers a particularly attractive balance between theoretical consistency and practical usability.
