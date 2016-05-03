#include "TreeReader.h"
#include "WeightCalculator.h"
#include <string>
#include <ostream>

int main(int argc, char** argv) {
    using namespace std;
    
    
    std::string out = *(argv + 1);
    
    cout << "\n\n\n OUTPUT NAME IS:    " << out << endl;     //PRINTING THE OUTPUT File name
    TFile *fout = TFile::Open(out.c_str(), "RECREATE");
    
    std::string input = *(argv + 2);
    cout << "\n\n\n InPUT NAME IS:    " << input << endl;     //PRINTING THE Input File name
    TFile * myFile = TFile::Open(input.c_str());
    TH1F * HistoTot = (TH1F*) myFile->Get("hcount");
    TH1F * HistohPU = (TH1F*) myFile->Get("hPU");
    TH1F * HistohPUTrue = (TH1F*) myFile->Get("hPUTrue");
    
    TFile * PUData= TFile::Open("pileup-hists/Data_Pileup_2015D_Nov17.root");
    TH1F * HistoPUData= (TH1F *) PUData->Get("pileup");
    HistoPUData->Scale(1.0/HistoPUData->Integral());
    
    TFile * PUMC= TFile::Open("pileup-hists/MC_Spring15_PU25_Startup.root");
    TH1F * HistoPUMC= (TH1F *) PUMC->Get("pileup");
    HistoPUMC->Scale(1.0/HistoPUMC->Integral());

    
    
    
    TH1F *    visibleMassOS = new TH1F ("visibleMassOS","visibleMassOS", 300, 0, 300);
    TH1F *    visibleMassSS = new TH1F ("visibleMassSS","visibleMassSS", 300, 0, 300);
    TH1F *    visibleMassOSRelaxedTauIso = new TH1F ("visibleMassOSRelaxedTauIso","visibleMassOSRelaxedTauIso", 300, 0, 300);
    TH1F *    visibleMassSSRelaxedTauIso = new TH1F ("visibleMassSSRelaxedTauIso","visibleMassSSRelaxedTauIso", 300, 0, 300);
    
    
    
    
    TTree *Run_Tree = (TTree*) myFile->Get("EventTree");
    
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(6);
    
    
    Run_Tree->SetBranchAddress("run", &run);
    Run_Tree->SetBranchAddress("lumis", &lumis);
    Run_Tree->SetBranchAddress("event", &event);
    
    Run_Tree->SetBranchAddress("nTau", &nTau);
    Run_Tree->SetBranchAddress("tauPt"  ,&tauPt);
    Run_Tree->SetBranchAddress("tauEta"  ,&tauEta);
    Run_Tree->SetBranchAddress("tauPhi"  ,&tauPhi);
    Run_Tree->SetBranchAddress("tauMass"  ,&tauMass);
    Run_Tree->SetBranchAddress("tauCharge"  ,&tauCharge);
    Run_Tree->SetBranchAddress("pfTausDiscriminationByDecayModeFinding", &pfTausDiscriminationByDecayModeFinding);
    Run_Tree->SetBranchAddress("tauByTightMuonRejection3", &tauByTightMuonRejection3);
    Run_Tree->SetBranchAddress("tauByLooseMuonRejection3", &tauByLooseMuonRejection3);
    Run_Tree->SetBranchAddress("tauByMVA5MediumElectronRejection"  ,&tauByMVA5MediumElectronRejection);
    Run_Tree->SetBranchAddress("tauByLooseCombinedIsolationDeltaBetaCorr3Hits",&tauByLooseCombinedIsolationDeltaBetaCorr3Hits);
    Run_Tree->SetBranchAddress("tauByMediumCombinedIsolationDeltaBetaCorr3Hits",&tauByMediumCombinedIsolationDeltaBetaCorr3Hits);
    Run_Tree->SetBranchAddress("tauByTightCombinedIsolationDeltaBetaCorr3Hits",&tauByTightCombinedIsolationDeltaBetaCorr3Hits);
    Run_Tree->SetBranchAddress("tauByMVA5LooseElectronRejection", &tauByMVA5LooseElectronRejection);
    Run_Tree->SetBranchAddress("tauDxy",&tauDxy);
    
    Run_Tree->SetBranchAddress("nMu", &nMu);
    Run_Tree->SetBranchAddress("muPt"  ,&muPt);
    Run_Tree->SetBranchAddress("muEta"  ,&muEta);
    Run_Tree->SetBranchAddress("muPhi"  ,&muPhi);
    Run_Tree->SetBranchAddress("muIsoTrk", &muIsoTrk);
    Run_Tree->SetBranchAddress("muCharge",&muCharge);
    Run_Tree->SetBranchAddress("muIsMediumID",&muIsMediumID);
    Run_Tree->SetBranchAddress("muIsLooseID",&muIsLooseID);
    Run_Tree->SetBranchAddress("muPFChIso", &muPFChIso);
    Run_Tree->SetBranchAddress("muPFPhoIso", &muPFPhoIso);
    Run_Tree->SetBranchAddress("muPFNeuIso", &muPFNeuIso);
    Run_Tree->SetBranchAddress("muPFPUIso", &muPFPUIso);
    Run_Tree->SetBranchAddress("muD0",&muD0);
    Run_Tree->SetBranchAddress("muDz",&muDz);
    
    
    Run_Tree->SetBranchAddress("pfMET",&pfMET);
    Run_Tree->SetBranchAddress("pfMETPhi",&pfMETPhi);
    
    /////////////////////////   Jet Info
    Run_Tree->SetBranchAddress("nJet",&nJet);
    Run_Tree->SetBranchAddress("jetPt",&jetPt);
    Run_Tree->SetBranchAddress("jetEta",&jetEta);
    Run_Tree->SetBranchAddress("jetPhi",&jetPhi);
    Run_Tree->SetBranchAddress("jetEn",&jetEn);
    Run_Tree->SetBranchAddress("jetpfCombinedInclusiveSecondaryVertexV2BJetTags",&jetpfCombinedInclusiveSecondaryVertexV2BJetTags);
    Run_Tree->SetBranchAddress("jetPFLooseId",&jetPFLooseId);
    Run_Tree->SetBranchAddress("jetPUidFullDiscriminant",&jetPUidFullDiscriminant);
    
    
    Run_Tree->SetBranchAddress("genWeight",&genWeight);
    
    Run_Tree->SetBranchAddress("HLTEleMuX", &HLTEleMuX);
    Run_Tree->SetBranchAddress("puTrue", &puTrue);
    
    
    float MuMass= 0.10565837;
    float eleMass= 0.000511;
    
    //        float LumiWeight = 1;
    //        if (HistoTot) LumiWeight = weightCalc(HistoTot, input);
    //        cout<<"LumiWeight is "<<LumiWeight<<"\n";
    
    
    
    Int_t nentries_wtn = (Int_t) Run_Tree->GetEntries();
    cout<<"nentries_wtn===="<<nentries_wtn<<"\n";
    for (Int_t i = 0; i < nentries_wtn; i++) {
        Run_Tree->GetEntry(i);
        if (i % 10000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
        fflush(stdout);
        
        
        //            float GetGenWeight=1;
        //            if (HistoTot) GetGenWeight=genWeight;
        
        //###############################################################################################
        //  Weight Calculation
        //###############################################################################################
        float LumiWeight = 1;
        float GetGenWeight=1;
        float PUWeight = 1;
        
        if (!isData){
            
            if (HistoTot) LumiWeight = weightCalc(HistoTot, input);
            GetGenWeight=genWeight;
            
            int puNUmmc=int(puTrue->at(0)*10);
            int puNUmdata=int(puTrue->at(0)*10);
            float PUMC_=HistoPUMC->GetBinContent(puNUmmc+1);
            float PUData_=HistoPUData->GetBinContent(puNUmdata+1);
            PUWeight= PUData_/PUMC_;
        }
        float TotalWeight = LumiWeight * GetGenWeight * PUWeight;
        
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Loop over Di-Mu events  We need to veto these events later
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool IsthereDiMuon= false;
        
        for  (int imu=0 ; imu < nMu; imu++){
            for  (int jmu=0 ; jmu < nMu; jmu++){
                
                
                // Select first good muon
                bool MuPtCut1 = muPt->at(imu) > 15 && fabs(muEta->at(imu)) < 2.4 ;
                float IsoMu1=muPFChIso->at(imu)/muPt->at(imu);
                if ( (muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu) )  > 0.0)
                    IsoMu1= ( muPFChIso->at(imu)/muPt->at(imu) + muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu))/muPt->at(imu);
                bool MuIdIso1=(muIsLooseID->at(imu) > 0 && IsoMu1 < 0.30 && fabs(muD0->at(imu)) < 0.045 && fabs(muDz->at(imu)) < 0.2);
                
                
                // Select second good muon
                bool MuPtCut2 = muPt->at(jmu) > 15 && fabs(muEta->at(jmu)) < 2.4 ;
                float IsoMu2=muPFChIso->at(jmu)/muPt->at(jmu);
                if ( (muPFNeuIso->at(jmu) + muPFPhoIso->at(jmu) - 0.5* muPFPUIso->at(jmu) )  > 0.0)
                    IsoMu2= ( muPFChIso->at(jmu)/muPt->at(jmu) + muPFNeuIso->at(jmu) + muPFPhoIso->at(jmu) - 0.5* muPFPUIso->at(jmu))/muPt->at(jmu);
                bool MuIdIso2=(muIsLooseID->at(jmu) > 0 && IsoMu2 < 0.30 && fabs(muD0->at(jmu)) < 0.045 && fabs(muDz->at(jmu)) < 0.2);
                
                
                bool  OS = muCharge->at(imu) * muCharge->at(jmu) < 0;
                
                if(MuIdIso1 && MuIdIso2 && OS)
                    IsthereDiMuon=true;
                
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  Loop Over events with one muon and one Taus
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TLorentzVector Mu4Momentum, Tau4Momentum, Z4Momentum, BJet4Momentum;
        
        for  (int imu=0 ; imu < nMu; imu++){
            for  (int itau=0 ; itau < nTau; itau++){
                
                // Check Single Muon Trigger  (Maybe we need to add Mu+Tau Trigger)
                bool PassTrigger = ((HLTEleMuX >> 29 & 1) == 1 || (HLTEleMuX >> 30 & 1) == 1 );
                
                //  Muon Pt and Eta cuts
                bool MuPtCut = muPt->at(imu) > 20 && fabs(muEta->at(imu)) < 2.1 ;
                
                // Check Muon Isolation   (delta beta correction is applied)
                float IsoMu=muPFChIso->at(imu)/muPt->at(imu);
                if ( (muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu) )  > 0.0)
                    IsoMu= ( muPFChIso->at(imu)/muPt->at(imu) + muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu))/muPt->at(imu);
                
                //Apply Muon Id and Isolation and dxy/dz cuts
                bool MuIdIso=(muIsMediumID->at(imu) > 0 && IsoMu < 0.10 && fabs(muD0->at(imu)) < 0.045 && fabs(muDz->at(imu)) < 0.2);
                
                // Tau Pt and Eta cuts
                bool TauPtCut = tauPt->at(itau) > 20  && fabs(tauEta->at(itau)) < 2.3 ;
                
                //Apply tau Id and Isolation and dxy
                bool TauIdIso =  tauByMediumCombinedIsolationDeltaBetaCorr3Hits->at(itau) && tauByTightMuonRejection3->at(itau) > 0 && tauByMVA5LooseElectronRejection->at(itau) > 0 && fabs(tauDxy->at(itau)) < 0.05 ;
                
                // Check charge of the muon and Taus
                bool  OS = muCharge->at(imu) * tauCharge->at(itau) < 0;
                bool  SS = muCharge->at(imu) * tauCharge->at(itau) > 0;
                
                
                // Get the 4-,omuntum on tau/mu/Z
                Mu4Momentum.SetPtEtaPhiM(muPt->at(imu),muEta->at(imu),muPhi->at(imu),MuMass);
                Tau4Momentum.SetPtEtaPhiM(tauPt->at(itau),tauEta->at(itau),tauPhi->at(itau),tauMass->at(itau));
                Z4Momentum=Mu4Momentum+Tau4Momentum;
                
                
                // Measuring the TMass to apply a cutr on that later on and Kill W+Jets events
                float tmass= TMass_F(muPt->at(imu), muPt->at(imu)*cos(muPhi->at(imu)),muPt->at(imu)*sin(muPhi->at(imu)) ,  pfMET, pfMETPhi);
                

                // Check the b jet multiplicity in the event. (veto events which have a b jet to suppress ttbar)
                vector<TLorentzVector> BJetVector;
                BJetVector.clear();
                
                for (int ijet= 0 ; ijet < nJet ; ijet++){
                    BJet4Momentum.SetPtEtaPhiE(jetPt->at(ijet),jetEta->at(ijet),jetPhi->at(ijet),jetEn->at(ijet));
                    if (jetPFLooseId->at(ijet) > 0.5 && jetPt->at(ijet) > 20 && fabs(jetEta->at(ijet)) < 2.4 && BJet4Momentum.DeltaR(Tau4Momentum) > 0.5 && BJet4Momentum.DeltaR(Mu4Momentum) > 0.5 && jetpfCombinedInclusiveSecondaryVertexV2BJetTags->at(ijet) >  0.89  ){
                        BJetVector.push_back(BJet4Momentum);
                    }
                }
                
                
                
                //  Fill out the Visible mass for OS events that pass all events cuts
                if (OS && !IsthereDiMuon && MuPtCut && TauPtCut && MuIdIso && TauIdIso && tmass < 30 && Mu4Momentum.DeltaR(Tau4Momentum) > 0.5 && PassTrigger && BJetVector.size()==0)
                    visibleMassOS->Fill(Z4Momentum.M(),TotalWeight);
                
                
                //  Fill out the Visible mass for SS events that pass all events cuts
                if (SS && !IsthereDiMuon && MuPtCut && TauPtCut && MuIdIso && TauIdIso &&  tmass < 30 && Mu4Momentum.DeltaR(Tau4Momentum) > 0.5 && PassTrigger && BJetVector.size()==0)
                    visibleMassSS->Fill(Z4Momentum.M(),TotalWeight);
                
                //Apply Relaxed tau Id and Isolation
                bool RelaxedTauIdIso = tauByTightMuonRejection3->at(itau) > 0 && tauByMVA5LooseElectronRejection->at(itau) > 0 && fabs(tauDxy->at(itau)) < 0.05 ;
                
                //  Fill out the Visible mass for OS events that pass all events cuts with relax Tau Isolation
                if (OS && !IsthereDiMuon && MuPtCut && TauPtCut && MuIdIso && RelaxedTauIdIso && tmass < 30 && Mu4Momentum.DeltaR(Tau4Momentum) > 0.5 && PassTrigger && BJetVector.size()==0)
                    visibleMassOSRelaxedTauIso->Fill(Z4Momentum.M(),TotalWeight);
                
                
                //  Fill out the Visible mass for SS events that pass all events cuts with relax Tau Isolation
                if (SS && !IsthereDiMuon && MuPtCut && TauPtCut && MuIdIso && RelaxedTauIdIso &&  tmass < 30 && Mu4Momentum.DeltaR(Tau4Momentum) > 0.5 && PassTrigger && BJetVector.size()==0)
                    visibleMassSSRelaxedTauIso->Fill(Z4Momentum.M(),TotalWeight);
                
                
                
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        
    }
    
    fout->cd();
    visibleMassOS->Write();
    visibleMassSS->Write();
    visibleMassOSRelaxedTauIso->Write();
    visibleMassSSRelaxedTauIso->Write();
    fout->Close();
    
    
}




