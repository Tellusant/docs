# Example of Stata Beeswarm Graph (stripplot)
Beeswarm graphs (made with stripplot) are excellent for showing a data series when there are 50-300 observations. Beyond 300, use violinplots.

This is an example with the world's coountries and the largest U.S. companies on the same metric: value-added.

[Beeswarm](../articles-posts/assets/images/country-firm/s.canback-tellusant-country-firm-comparison.svg)

The Stata code to generate this is:

```stata

//lva is the log of value-added / GDP. Type is country or company
//This looks good with 300 obsevations (200 country, 100 companies)

#delimit ;

stripplot lva,
    vertical
    stack
    width(0.1)
    center
    over(type_id) //This gives 2 columns. Comment out for 1 column
    separate(type_id)
    msymbol(t Oh)
    msize(small small)
    mcolor(navy "140 0 40")
	    ytitle("Log GDP / VA")
    ylabel(#10, angle(horizontal) grid)
    //legend(order(1 "Countries" 2 "Companies"))
    aspectratio(1.2)
    xsize(6)
    ysize(4)
    graphregion(color(white))
    plotregion(color(white))
	//legend(order(1 "Countries" 2 "Companies") region(lstyle(none)))
;

#delimit cr
```
