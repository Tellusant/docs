---
title: "Background to Beige Book Nowcast by Tellusant"
description: "We provide a snapshot of current economic activity. It is easy to past data and future projections. We provide the here and now to bridge the gap."
image: /assets/social-card-beig.png
---
# Background to Beige Book Nowcast by Tellusant

## Description

We provide a snapshot of current economic activity. It is easy to past data and future projections. We provide the here and now to bridge the gap.

The Fed's Beige Book, *[Summary of Commentary on Current Economic Conditions](https://www.federalreserve.gov/monetarypolicy/publications/beige-book-default.htm)*, covers current economic activity for the 12 Federal Reserve Districts. It is published sesqui-monthly (every 1½
months). Tellusant converts it into a quantitative nowcast.  

The Beige Book is useful for, among others, CEOs and management teams who want to quickly assess where the economy is at present.  

We compute a composite score for each of the twelve districts based on a **semantic analysis** of the report, then sum the scores weighted by the GDP of each district.  

We have published these nowcasts since June 2015 on LinkedIn. The new series published here starts in October 2025. The LinkedIn series can still be found there.

>Ther analysis is now entirely performed by our Fedora AI agent (v1.1.4). It consists of five parts:
>
>- ChatGPT = runtime environment
>- YAML = analytical serialization
>- Excel = model + parameters
>- Mermaid v11 = workflow graphing
>
>In the next cycle, we will implemenent a scheduler such as *cron* in GitHub Action to make the updating instant upon report release.

## Workflow

# Semantic Analysis Workflow: The Fedora Example
How can a previously manual workflow be automated with AI and other components? We use our [Fed Beige Book analysis agent called Fedora](https://tellusant.github.io/docs/nowcasts-ongoing-analyses/beige-book.html) as a case study to show the new automated workflow in GPT. No human need to be involved in the process any more, except for the occasional quality control.  

Just like the workflow is automated, the workflow graph generation is also automated using Mermaid v11.  

<div class="mermaid">

%%{init: {'themeVariables': { 'fontFamily': 'Arial'}}}%%

flowchart TD

    A["`**New Beige Book Release**`"]:::blue

    subgraph S1["`*1. Ingestion*`"]
        B["`**Fetch Beige Book**<br/>HTML / PDF`"]:::base
        C["`**Store Source & Metadata**`"]:::base
    end

    subgraph S2["`*2. Extraction*`"]
        D["`**Parse District Sections**`"]:::base
        E["`**Extract First Sentences**`"]:::base
        F["`**Extract Full District Text**`"]:::base
    end

    subgraph S3["`*3. Scoring*`"]
        G["`**Apply Growth LUT**<br/>First Sentence`"]:::base
        H["`**Apply Semantic LUT**<br/>Full Text`"]:::base
        I["`**Generate District Scores**`"]:::base
    end

    subgraph S4["`*4. Aggregation*`"]
        J["`**Apply GDP Weights<br/>from Workbook**`"]:::base
        K["`**Compute Metrics: Weighted Mean, DI, WDI**`"]:::base
        L["`**Compute Semantic Indices**`"]:::base
        M["`**Compute Composite Macro Index**`"]:::base
    end

    subgraph S5["`⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀*5. Output*`"]
        N["`**Write to Workbook**<br/>Main, Semantic, History`"]:::base
        O["`**Generate Tellusant Summary**`"]:::base
        P["`**Generate Charts (Python)**`"]:::base
        Q["`**Store Audit Trail**`"]:::base
    end

    subgraph S6["`*0. Automation*`"]
        R["`**Scheduled Trigger**<br/>GitHub Actions`"]:::base
        S["`**Check for New Release**`"]:::base
    end

    subgraph S7["`⠀⠀⠀⠀⠀⠀⠀*6. Feedback Loop*`"]
        T["`**Human Review**`"]:::green
        U["`**Update in Workbook**`"]:::base
    end

        V["`**Final Output**`"]:::red
        
    R --> S --> A
    A --> B --> C --> D --> E
    D --> F
    E --> G --> I
    F --> H --> I
    I --> J --> K
    I --> L --> M
    K --> N
    M --> N
    N --> O
    N --> P
    N --> Q
    O --> T
    P --> T
    Q --> T -->|⠀if error⠀| U --> G
    T -->|⠀if correct⠀| V
    O --> V
    
linkStyle 24 stroke:blue,stroke-width:1;
linkStyle 26 stroke:transparent,stroke-width:0;


%% ========= STYLES =========
classDef green   fill:#E8F5E9,stroke:#1B5E20,stroke-width:2px,color:#111;
classDef blue    fill:#E3F2FD,stroke:#0D47A1,stroke-width:2px,color:#111;
classDef orange  fill:#FFF8E1,stroke:#FF6F00,stroke-width:2px,color:#111;
classDef red     fill:#FDECEA,stroke:#B71C1C,stroke-width:2px,color:#111;
classDef grey    fill:#F5F5F5,stroke:#424242,stroke-width:2px,color:#111;
classDef base    fill:#ECECFF,stroke:#9370DB,stroke-width:2px,color:#111;
classDef clear   fill:transparent,stroke:transparent;

    </div>

The details of the workflow is best understand by studying the graph.  

[The details of the workflow are found here](https://canback.net/docs/articles-posts/fedora.html)
