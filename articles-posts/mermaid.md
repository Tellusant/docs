<div class="mermaid">
flowchart TD
    IMF[IMF Assessment]
    IMF --> Growth[Growth]
    IMF --> Fiscal[Fiscal Policy]
    Fiscal --> Confidence[Confidence]
</div>

<div class="mermaid">
flowchart TD
    GE["Global Environment\nScore: 3/10"]
    FP["Fiscal Policy\nScore: 3/10"]
    GJ["Growth & Jobs\nScore: 4/10"]
    MP["Monetary Policy\nScore: 8/10"]
    MS["Macro Stability\nScore: 6/10"]
    FS["Financial Sector\nScore: 8/10"]
    SR["Structural Reforms\nScore: 5/10"]
    LC["Long-Term Confidence\nScore: 5/10"]

    GE -->|Downside risks| GJ
    FP -->|Constrains growth| GJ
    MP -->|Anchors inflation| MS
    MS -->|Enables| GJ
    MP -->|Strengthens| FS
    FS <-->|Depends on progress| SR
    SR -->|Pace insufficient| LC
    LC -->|Feedback loop| GJ
</div>
