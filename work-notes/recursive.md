# Recursive Linear Regression
Work note

Stata can perform recursive linear regression from the command line, primarily using the rolling prefix command. In a recursive regression, the starting observation is held fixed while the ending observation advances, causing the window size to grow with each iteration. [1, 2, 3] 
## Core Command Syntax
To run a recursive regression, you must first set your data as a time series using tsset. The basic syntax is: [4, 5, 6] 
rolling _b, window(#) recursive: regress depvar indepvar [7] 

* _b: Tells Stata to store the regression coefficients.
* window(#): Specifies the initial number of observations to use for the first regression.
* recursive: This key option ensures the starting period stays fixed while the window expands forward.
* regress: The standard [Stata linear regression](https://www.stata.com/manuals/rregress.pdf) command. [1, 2, 8, 9] 

## Advanced Options and Alternatives

* Saving Results: Use the saving(filename, replace) option to store the resulting coefficients and standard errors in a separate .dta file for later analysis.
* Reverse Recursive: You can use the rrecursive option if you want the ending period to remain fixed while the starting period advances (shrinking the window).
* User-Written Commands: For large datasets, the community-contributed command asreg (available via SSC) is often faster than the native rolling command and includes a dedicated recursive option.
* Nested Regression: If by "recursive" you mean adding blocks of variables to a single model, use the [nestreg command](https://www.stata.com/manuals/rnestreg.pdf). [1, 2, 10, 11, 12] 

## Example Workflow

sysuse gnp96, clear
tsset date
rolling _b _se, window(20) recursive saving(myresults, replace): regress gnp f.gnp

This script initializes the data, runs a recursive regression starting with a 20-period window that grows by one period each step, and saves the coefficients and standard errors to myresults.dta. [1, 2] 
Would you like to see how to plot the coefficients over time once the recursive regression is complete?

[1] [https://www.stata.com](https://www.stata.com/manuals/tsrolling.pdf)
[2] [https://www.stata.com](https://www.stata.com/manuals15/tsrolling.pdf)
[3] [https://www.statalist.org](https://www.statalist.org/forums/forum/general-stata-discussion/general/1411316-code-for-out-of-sample-r-squared)
[4] [https://www.stata.com](https://www.stata.com/manuals13/tstimeseries.pdf#:~:text=tsset%20can%20also%20be%20used%20to%20declare,a%20variable%20that%20identifies%20the%20time%20periods.)
[5] [https://www.projectguru.in](https://www.projectguru.in/normality-test-stata/#:~:text=The%20first%20step%20is%20to%20set%20the,data.%20Thereafter%20proceed%20to%20the%20regression%20analysis.)
[6] [https://libguides.princeton.edu](https://libguides.princeton.edu/time_series_basics)
[7] [https://www.stata.com](https://www.stata.com/manuals13/tsrolling.pdf)
[8] [https://www.stata.com](https://www.stata.com/manuals/rregress.pdf)
[9] [https://www.reed.edu](https://www.reed.edu/psychology/stata/analyses/parametric/Regression/regress.html#:~:text=The%20basic%20linear%20regression%20command%20in%20Stata,relevant%20and%20migt%2C%20in%20fact%2C%20be%20suppressed.)
[10] [https://www.statalist.org](https://www.statalist.org/forums/forum/general-stata-discussion/general/1390199-asreg-rolling-window-regressions-and-by-groups-regressions-rolling-betas)
[11] [https://www.stata.com](https://www.stata.com/manuals/rnestreg.pdf)
[12] [https://www.statalist.org](https://www.statalist.org/forums/forum/general-stata-discussion/general/1469331-obtaining-residuals-with-by-command#:~:text=asreg%20%28can%20be%20downloaded%20from%20SSC%29%20can,both%20by%2Dgroup%20and%20rolling%20regressions%20with%20residuals.)
