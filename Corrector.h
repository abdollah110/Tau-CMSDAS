#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include "TH1F.h"
#include "TH2F.h"
#include "TTree.h"
#include "TFile.h"
#include "TF1.h"
#include "TSystem.h"
#include "TMath.h" //M_PI is in TMath
#include "TRandom3.h"
#include <TLorentzVector.h>
using namespace std;








float p=0;
float h=0;
float s=0;

float trigEff_Mu(bool isData, float pt, float eta){

    if (isData)
    return 1.0;
    
    
    eta = fabs(eta);
    if (eta <= 0.8){
        p = 0.897 ;
        h =  5.1 ;
        s = 0.065 ;
    }
    else if (eta < 1.24) {
        p = 0.862;
        h = 12.6;
        s = 0.09; }
    else{
        p = 0.837 ;
        h = 16.6 ;
        s = 0.1 ;
    }
    return 0.5*p*(1+erf(s*(pt-h)/sqrt(2.)));
}

float trigEff_Ele(bool isData, float pt, float eta){
    
    if (isData)
        return 1.0;
    
    
    eta = fabs(eta);
    if (eta <= 1.479){
        p = 0.907 ;
        h =  8.7 ;
        s = 0.031 ;
    }
    else{
        p = 0.783 ;
        h = 21.2 ;
        s = 0.043 ;
    }
    return 0.5*p*(1+erf(s*(pt-h)/sqrt(2.)));
}


float TauID_ScaleFactor(){
    return 0.9;
}









