DY XS estimation
------------

The aim is to measure ZTauTau cross-section @ 13 TeV.

What we plan to do is select Z-->tautau-->muTau events both in data (single muon dataset) and MC (DYJets as signal and QCD, WJet and TTbar, and possibily diboson as backgrounds)

Subtrac all background from Data. Different bween data and background would be considered as ZTT.

All background are estimated from MC, except QCD, which is coumputed from data using mu-tau same-sign control region.


------------
First step:

Select a pair of muTau events: Follow the exercise of the Jet to tau fake rate and/or Tau Id efficiency:

select events with one good identified and isolated muon and taus with TMass(muon_MET) < 30 GeV and fill the visible mass distribution of the muon and Tau.

Use the file RunOnMCandData.txt to run on Data and MC ntuples.
The input files are located in:
/uscms_data/d3/abdollah/CMSDAS/rootFiles/

Second step:



Within some visiable mass region, e.g (25, 125)

Data_OST - xDY_OST - MC_None_DY_OST - QCD_OST = 0 <br />
1) x = DY_XS/6025.2 <br />
2) QCD_OST = 1.06(Data_SST - xDY_SST - MC_None_DY_SST) <br />

=> x = (Data_OST - MC_None_DY_OST - 1.06(Data_SST - MC_None_DY_SST))/(DY_OST - 1.06DY_SST) <br />
=> DY_XS = x6025.2

Similarly, one can independently calculate DY_XS in tau iso relaxed region.


Running script
------------
Edit lines 184-195 in xs_calculator.py
```bash
python xs_calculator.py
```

The script will output the DY xs in tight and relaxed regions.
It'll also make 2 stacked plots in those regions.