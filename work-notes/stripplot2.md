# Comprehensive Guide: Creating a Symmetrical Beeswarm Plot in Stata

This document captures the full step-by-step development of creating an organic, curved, and perfectly symmetrical vertical beeswarm plot for 200 countries using log(GDP) data in Stata.

---

## Step 1: The Standard Horizontal Stacking Plot

### User Query
> how do I make a stripplot in stata so it looks like a beeswarm. 200 countries with log(gdp)

### Solution
To make a beeswarm-style plot in Stata, use the `stripplot` package with the `stack` option. This command algorithmically stacks the points, spreading out overlapping values into a symmetrical "swarm" shape. 

First, install the package from the SSC:
```stata
ssc install stripplot, replace
```

Assuming your variable for log(GDP) is named `log_gdp`, run this syntax:
```stata
stripplot log_gdp, over(country) stack width(0.1) mlabel(country) ///
    msymbol(circle_hollow) msize(small) yscale(off)
```

#### Key Options Explained:
* **`stack`**: This is the most critical option for the beeswarm effect. It automatically stacks duplicate or near-duplicate values next to each other so no data points are hidden.
* **`width( )`**: Controls how far the points are allowed to spread horizontally. If the points are packing too tightly, try increasing this number (e.g., `width(0.2)`).
* **`mlabel(country)`**: Optional but highly recommended if you have 200 countries. It attaches the country names so you can identify the extremes (e.g., the highest/lowest log GDP).
* **`yscale(off)`**: Hides the categorical country axis so the visualization looks clean and focused solely on the log(GDP) distribution.

---

## Step 2: Transitioning to a Single Vertical Swarm

### User Query
> starting with one swarm. Want it verically

### Solution
To create a single, vertical beeswarm plot for your 200 countries, you must include the `vertical` option and completely remove any reference to the `over()` option. By default, omitting `over()` forces Stata to plot everything as one unified distribution. 

Run this exact syntax:
```stata
stripplot log_gdp, vertical stack width(0.1) center ///
    msymbol(circle_hollow) msize(small)     ///
    xscale(off) xtitle("") ylabel(#10)
```

#### Key adjustments for a vertical swarm:
* **`vertical`**: Flips the log(GDP) to the vertical Y-axis. 
* **`center`**: Instructs Stata to stack the points symmetrically on both sides of the central axis line (creating the iconic "wasp-waist" or bee-body silhouette instead of stacking them all to one side).
* **`width(0.1)`**: Controls the bin width for the stacking algorithm. Because you are plotting 200 countries, if the dots spread out too wide horizontally, decrease this number (e.g., `width(0.05)`). If they clump up too vertically, increase it (e.g., `width(0.15)`).
* **`xscale(off) xtitle("")`**: Removes the horizontal axis lines, labels, and titles since there is no categorical grouping variable. This isolates your swarm beautifully.

#### 💡 Pro Tip for Country Labels:
With 200 data points, adding labels to *every* dot will make the plot unreadable. If you want to highlight specific country names, use a conditional `mlabel()` rule instead:
```stata
* This only prints the country name if log_gdp is exceptionally high or low
stripplot log_gdp, vertical stack width(0.1) center ///
    msymbol(circle_hollow) msize(small) xscale(off) xtitle("") ///
    mlabel(country) mlabvpos(12) if log_gdp > 11 | log_gdp < 6
```

---

## Step 3: Replicating a Curved Shape (Moving Away from Rigid Lines)

### User Query
> not now. Many beeswarms have a curved shape while yoy plot countries on horizontal lines. Can we replicate the curved?

### Solution
Yes, you can absolutely replicate that fluid, continuous organic shape. 

The rigid "horizontal line grid" look happens because the `stack` option forces data into distinct mathematical histogram-style bins. To get a smooth, curved shape where points glide naturally around each other, you need to switch from algorithmic stacking to a dense **random horizontal jitter combined with point transparency**.

Use this syntax to get a beautifully contoured, non-gridded vertical swarm:
```stata
stripplot log_gdp, vertical jitter(3) jitterseed(1234) ///
    msymbol(circle) msize(small) mcolor(navy%40)      ///
    xscale(off) xtitle("") ylabel(#10)
```

#### Why this creates the "Curved" look:
* **`jitter(3)`**: Instead of alignment lines, this adds continuous horizontal noise. Increasing this value (e.g., `jitter(4)`) spreads the swarm wider at its densest points; decreasing it narrows the curves. 
* **`mcolor(navy%40)`**: This adds **40% opacity** (transparency) to the markers. Where many countries share a similar log(GDP), the overlapping translucent dots blend together to form a darker, richly colored "core." In sparse areas, they remain faint. This instantly produces a curved density gradient similar to a violin plot.
* **`msymbol(circle)`**: Shifting to solid filled circles (instead of hollow ones) makes the opacity mapping significantly more effective at showcasing the curved shape of your distribution.
* **`jitterseed(1234)`**: Ensures that the random horizontal spread looks exactly the same every single time you replicate your code.

---

## Step 4: Expanding Plot Width

### User Query
> works, but there is hardly any width in the graph

### Solution
When Stata plots a single group vertically, it defaults to an ultra-skinny horizontal scale. To blow up the width and make the curves highly visible, you need to force the window to be wider with an aspect ratio and scale up the jitter value.

Run this modified code to get a wider, more expansive swarm:
```stata
stripplot log_gdp, vertical jitter(15) jitterseed(1234) ///
    msymbol(circle) msize(small) mcolor(navy%40)       ///
    xscale(range(0 2) off) xtitle("") ylabel(#10)       ///
    aspect(0.8)
```

#### What changed to fix the width:
* **`jitter(15)`**: Heavily scaled up from 3. This forces the random horizontal displacement to spread far wider, turning the skinny line into a true organic swarm.
* **`aspect(0.8)`**: Changes the geometric aspect ratio of the entire plot region. Setting it below 1 (`0.8` or `0.6`) forces Stata to draw a squat, wider graph instead of a tall, narrow pillar.
* **`xscale(range(0 2) off)`**: Artificially expands the coordinate grid behind the invisible horizontal axis. This pairs with the high jitter number to give the dots a broad "playground" to scatter across.

---

## Step 5: Achieving True Left/Right Symmetry

### User Query
> works. It is projecting to the right. Can it be symmetrical pos. and neg. on x-axis

### Solution
By default, Stata's `jitter()` option only projects points randomly to the **right** (positive side) of the axis line. To achieve a perfectly balanced, symmetrical swarm on both the positive and negative sides of the center axis, you need to use the `center` option alongside the jitter.

However, because Stata's native jittering inside `stripplot` is inherently one-sided, the clever workaround is to pair `center` with the **`stack`** option, but use a **very tiny bin width**. This mimics continuous random jittering while forcing Stata's symmetric balancing algorithm to kick in.

Run this updated syntax to center your swarm:
```stata
stripplot log_gdp, vertical stack width(0.01) center    ///
    msymbol(circle) msize(small) mcolor(navy%40)        ///
    xscale(off) xtitle("") ylabel(#10)                  ///
    aspectratio(1.5) xsize(4) ysize(6)
```

#### Why this forces symmetry:
* **`center`**: This is the magic switch. It tells Stata to split the data points equally to the left and right of the imaginary center line.
* **`width(0.01)`**: By making the stacking bins incredibly small (0.01), you break the rigid horizontal row grid. The points are forced to micro-stack so close together that they blend into a smooth, organic, curved silhouette that expands symmetrically on both sides—just like a true beeswarm.

---

## Final Micro-Adjustment Cheat Sheet
* **To widen the swarm:** Slightly increase the `width()` value (e.g., `width(0.02)`).
* **To narrow the swarm:** Slightly decrease the `width()` value (e.g., `width(0.005)`).
* **To change density blending:** Adjust the color percentage (e.g., `navy%30` for lighter overlays, `navy%60` for darker ones).
