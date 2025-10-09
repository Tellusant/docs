# Subnational ICT Opportunities in South Africa
## Case Example for How to Use TelluBase Income Distribution Data  

There is a strong trend among global companies toward understanding markets at subnational levels. They always face local players who have a keen sense for subnational opportunities.  

**TelluBase** is immensely useful for understanding subnational markets. It contains macro and consumer data for 218 countries, 2600 cities, and 2500 subdivisions (states, provinces, regions, etc.)  

The power of TelluBase is when its statistically data are combined with industry and category. The data on their own can be illuminating ("the middle class and above in Lima is growing at 8% per year"), but the combination with other data is what leads to true insights and action ("we see an untapped market opportunity for our toothpaste at a mainstream price point of 200 million people in 2035, up from 80 million today").  

To illustrate with numbers, we turn to South Africa. 

#### The South African Internet Opportunity

It is rare to find subnational industry or category data in the public domain. We always source this from our clients with requisite permissions.  

We did however find a public report in South Africa when working for an investment bank on local ICT opportunities.

The ICASA report [*The State of the ICT Sector*](assets/support/State-of-ICT-Sector-Report-March-2022.pdf) among other things showed the number of internet users for major cities and all states. How is this converted into something analytically useful?  

We set as our objective to identify the internet over- and under-penetration for each of these geographic entities and then derive the latent market opportunity. The process was to:

1. Develop the internet penetration metric. ICASA did not have this in a clean fashion. We therefore used AND and OR statements to combine ICASA data into a singular metric.
2. Match the entities in the ICASA report to TelluBase. This was easy because the cities in ICASA were covered in **TelluBase**
3. Establish which part of the population uses the internet. We knew from prior experience that this correpnded to the middle class and above.
   - We tested various **TelluBase**'s income brackets to find the highest goodness-of-fit (R²). It turned out that our existing global middle class definition worked best. This was a nice confirmation of what we already knew.
   - We ran a regression with internet penetration as a function of middle class share of total population. It is typically better to run on absloute values (i.e. total number of households with internet vs total number of middle class households) but in this case results were similar.
   - R² was 0.8 and there was no heteroscedasticity
4. Establish the ***envelope***. The ***trendline*** does not show what is possible, it just shows the fitted curve. The envelope on the other hand establishes what is possible. It typically is drawn at one standard deviation from the trendline.

The graph below shows the finished analysis. The vertical distance between the envelope and the entities plot point is the opportunity.

<img  src="assets/images/tellusant-south-africa-ict-subnational-trend.svg" width="500" alt="South Africa ICT Subnational Trend">  

Note that 

<img  src="assets/images/tellusant-south-africa-ict-market-opportunities.svg" width="400" alt="South Africa ICT Market Opportunities">  

---
This effort built on Tellusant's long and deep telecom knowledge (see [Staffan Canback](https:https://www.linkedin.com/in/scanback/) and [Kennet Rådne](https://www.linkedin.com/in/kennetradne/)).  
