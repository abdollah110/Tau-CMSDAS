Jet to Tau Fake Rate
=================

-----

Both on Data (Single Muon data set) and MC (W+Jet events) 


How likely is  a jet to be mis-identified as a tau lepton?

0) Select W events (W-->munu events). To do so find a good muon in event and check the TMass of muon and MET to be compatible with W TMass.

1) Find a tau jet which pass decay mode finding and anti muon and anti electron discriminator 

2) Find how often this object can pass different working points of the Tau Isolation

3) One can parametrize this fake rate v.s. Tau Pt or closet Jet pt to Tau or eta, etc.

4) Try all eta ranges- Remember to always make an eta cut for your taus! Need the tracker!

5) Compare tau fake rate between data and MC

6) See the fake rate of different working points! Add in other tauIDs from the TreeReader.h 

7) after measuring tau ID from ZTT MC sample, make the ROC curve



The ratio(fake rate) we want is the number of  tau jets  passing an ID . 


Create a new file named jetToTauFakeRate.cc
paste at the top 
```
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//   Compiling the code:   ./Make.sh tauEfficiency.cc
//   Running the code:     ./tauEfficiency.exe OutPut.root   Input.root
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "TreeReader.h"
#include <string>
#include <ostream>


int main(int argc, char** argv) {
    using namespace std;

    std::string out = *(argv + 1);
    
    cout << "\n\n\n OUTPUT NAME IS:    " << out << endl;     //PRINTING THE OUTPUT File name
    TFile *fout = TFile::Open(out.c_str(), "RECREATE");
    
    std::string input = *(argv + 2);
    cout << "\n\n\n InPUT NAME IS:    " << input << endl;     //PRINTING THE Input File name
    TFile * myFile = new TFile(input.c_str());
 
    //add the histrograms of All gen-matched taus, and all gen-matched taus passing numerator
    TH1F *    histoDenumerator = new TH1F ("histoDenumerator","histoDenumerator", 300, 0, 300);
    TH1F *    histoNumerator = new TH1F ("histoNumerator","histoNumerator", 300, 0, 300);
    
    
    TTree *Run_Tree = (TTree*) myFile->Get("EventTree");
    cout.setf(ios::fixed, ios::floatfield);




}

```

You want to read specific branches from the provided Ntuples, so add the following lines to access the branches you want after opening the file i.e. after 'cout.setf(ios::fixed, ios::floatfield);' 

``` 


    Run_Tree->SetBranchAddress("nTau", &nTau);
    Run_Tree->SetBranchAddress("tauPt"  ,&tauPt);
    Run_Tree->SetBranchAddress("tauEta"  ,&tauEta);
    Run_Tree->SetBranchAddress("tauPhi"  ,&tauPhi);
    Run_Tree->SetBranchAddress("tauMass"  ,&tauMass);
    Run_Tree->SetBranchAddress("tauDxy",&tauDxy);
    Run_Tree->SetBranchAddress("tauByTightMuonRejection3", &tauByTightMuonRejection3);
    Run_Tree->SetBranchAddress("tauByMVA5LooseElectronRejection", &tauByMVA5LooseElectronRejection);
    Run_Tree->SetBranchAddress("tauByLooseCombinedIsolationDeltaBetaCorr3Hits",&tauByLooseCombinedIsolationDeltaBetaCorr3Hits);

```

Now you want to process all events so add a loop to process all events after you've declared the branches. 

```
    Int_t nentries_wtn = (Int_t) Run_Tree->GetEntries();
    cout<<"nentries_wtn===="<<nentries_wtn<<"\n";
    for (Int_t i = 0; i < nentries_wtn; i++) {
        Run_Tree->GetEntry(i);
        if (i % 1000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
        fflush(stdout);
 
       ////////////////////////////////////////////////
       //Important analysis stuff will happen here!!!//
       ////////////////////////////////////////////////


   } //End Processing all entries

```

Select W events in data and MC.

Start from looping over muons

Select a muon with pt > 25 GeV and |eta| < 2.1 (do not forget to apply single Muon Trigger)

Aplly muon Isolation as following:

float IsoMu=muPFChIso->at(imu)/muPt->at(imu);
if ( (muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu) )  > 0.0)
IsoMu= ( muPFChIso->at(imu)/muPt->at(imu) + muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu))/muPt->at(imu);

And medium working point of the muon Id.

Require the Transverse Mass between muon and MET to be greater than 50 GeV.


Then loop over tau collection

Tau Pt > 20 GeV and |eta| < 2.3



Check dR between muon and tau is greater than 0.5.
Then make the numerator and denumerator plot.  denumerator is taus with pt and eta cuts.
Numerator is denumerator + tau Isolation

Use the plotFakeRate.py macro to plot the jet to tau fake rate.


In the nentries loop paste 
```
	TLorentzVector MC4Momentum, Tau4Momentum;


	for  (int itau=0 ; itau < nTau; itau++){
		Tau4Momentum.SetPtEtaPhiM(tauPt->at(itau),tauEta->at(itau),tauPhi->at(itau),tauMass->at(itau));

		bool TauPtCut = tauPt->at(itau) > 20  && fabs(tauEta->at(itau)) < 2.3 ;
		bool TauPreSelection = fabs(tauDxy->at(itau)) < 0.05 ;



	}//end reconstructed tau loop
```

Now your code is all set up. You can ```/Make.sh jetToTauFakeRate.cc``` and then ```./jetToTauFakeRate.cc outputFR.root tot_job_spring15_ggNtuple_WJetsToLNu_amcatnlo_pythia8_25ns_miniAOD.root ``` 



