#include "TGraphAsymmErrors.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TH1.h"
#include "TF1.h"
#include <math.h>
#include <TEfficiency.h>
#include <TMath.h>
#include <TFormula.h>
#include <iostream>
#include <string>

#include <iostream>
#include <cmath>
#include "TLegend.h"
#include "TPad.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2.h"
#include "TF1.h"
#include "THStack.h"
#include "TStyle.h"
#include "TAxis.h"
#include "TGaxis.h"
#include "TTree.h"
#include "TPaveText.h"
//#include "/Users/isobelojalvo/Documents/work/Analysis/headerFiles/tdrstyle.C"
#include "TStyle.h"
#include "TAxis.h"
#include "TGaxis.h"
#include "StyleHeader.h"
void crossSections(){
  TCanvas* c1 = new TCanvas("c1","A Simple Graph with asymmetric error bars",200,10,700,500);
  c1->SetFillColor(42);
  //c1->SetGrid();
  TPad* pad1 = new TPad("pad1","The pad",0,0.0,1,1);
  applyPadStyle(pad1);
  gStyle->SetOptFit(0);
  gStyle->SetOptStat(0);
  gStyle->SetEndErrorSize(4);

  c1->cd();
  pad1->Draw();
  pad1->cd();

  TPaveText *pt = new TPaveText(0.4,5.5,0.55,6.5);
  applyTPaveTextStyle(pt);
  TPaveText *pt1 = new TPaveText(0.4,4.5,0.55,5.5);
  applyTPaveTextStyle(pt1);
  TPaveText *pt2 = new TPaveText(0.4,3.5,0.55,4.5);
  applyTPaveTextStyle(pt2);
  TPaveText          *pt3 = new TPaveText(0.4,2.5,0.55,3.5);
  applyTPaveTextStyle(pt3);
  TPaveText          *pt4 = new TPaveText(0.4,1.5,0.555,2.5);
  applyTPaveTextStyle(pt4);
  TPaveText          *pt5 = new TPaveText(0.4,0.5,0.555,1.5);
  applyTPaveTextStyle(pt5);
  TPaveText          *pt6 = new TPaveText(0.4,-0.5,0.555,0.5);
  applyTPaveTextStyle(pt6);
  /*
  TPaveText          *pt6 = new TPaveText(0.4,6.5,0.55,7.5);
  applyTPaveTextStyle(pt6);
  TPaveText          *pt7 = new TPaveText(0.4,5.5,0.55,6.5);
  applyTPaveTextStyle(pt7);
  */
  TPaveText *label  = new TPaveText(1.4,5.5,2,6.5);
  applyTPaveTextStyle(label);
  TPaveText *label1 = new TPaveText(1.4,4.5,2,5.5);
  applyTPaveTextStyle(label1);
  TPaveText *label2 = new TPaveText(1.4,3.5,2,4.5);
  applyTPaveTextStyle(label2);
  TPaveText *label3 = new TPaveText(1.4,2.5,2,3.5);
  applyTPaveTextStyle(label3);
  TPaveText *label4 = new TPaveText(1.4,1.5,2,2.5);
  applyTPaveTextStyle(label4);
  TPaveText *label5 = new TPaveText(1.4,0.5,2,1.5);
  applyTPaveTextStyle(label5);
  TPaveText *label6 = new TPaveText(1.4,-0.5,2,0.5);
  applyTPaveTextStyle(label6);


  const Int_t n = 16;
  ///first two values (0.2 and 2.5) are only for setting the range of the plot, they are dummies and should not be plotted.
  //e mu    ee mumu
  const Int_t nBoson = 9;
  Double_t xBoson[nBoson]   = { 0.2, 2.5 ,(5.94/5.84), (5.34/5.36), (0.45/0.45), (0.40/0.39), 1.04, 0.73, 0.88};
  Double_t exlBoson[nBoson] = { 0, 0, 0.02, 0.02, 0.01 , 0.01 , 0, 0, 0};
  Double_t exhBoson[nBoson] = { 0, 0, 0.21, 0.16, 0.017, 0.017, 0.18, 0.15, 0.16};
  Double_t yBoson[nBoson]   = {8, 7, 6, 5, 4, 3, 2, 1, 0};
  Double_t eyBoson[nBoson]  = {0, 0, 0, 0, 0, 0, 0, 0, 0};

  Double_t xBoson8[nBoson]   = { 0.2, 2.5 ,(5.94/5.84), (5.34/5.36), (0.45/0.45), (0.40/0.39), 0, 0, 0};
  Double_t exlBoson8[nBoson] = { 0, 0, 0.02, 0.02, 0.01 , 0.01 , 0, 0, 0};
  Double_t exhBoson8[nBoson] = { 0, 0, 0.21, 0.16, 0.017, 0.017, 0, 0, 0};
  Double_t yBoson8[nBoson]   = {8, 7, 6, 5, 4, 3, 2, 1, 0};
  Double_t eyBoson8[nBoson]  = {0, 0, 0, 0, 0, 0, 0, 0, 0};


  Double_t x[n]   = { 0.2, 2.5, 1.06 , 1.16 , 0.98 , 0.98 , 1.01 , 1.07 , 1.00 , 0.96 , 1.08 , 1.04 , 0.80 , 0.97 , 0.97 , 0.90 };
  Double_t exl[n] = {   0,   0, 0.01 , 0.03 , 0.01 , 0.01 , 0.13 , 0.04 , 0.02 , 0.05 , 0.07 , 0.03 , 0.06 , 0.13 , 0.06 , 0.11 };
  Double_t exh[n] = {   0,   0, 0.12 , 0.13 , 0.05 , 0.05 , 0.14 , 0.09 , 0.08 , 0.08 , 0.06 , 0.07 , 0.07 , 0.07 , 0.08 , 0.04 };

  Double_t y[n]   = {  15,  14,   13 ,   12 , 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  Double_t ey[n]  = { 0, 0, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };

  TGraphAsymmErrors* grT = new TGraphAsymmErrors(nBoson,xBoson,yBoson,exhBoson,exhBoson,eyBoson,eyBoson);
  grT->SetTitle("");
  grT->SetMarkerColor(kBlack);
  grT->SetMarkerStyle(8);
  grT->Draw("AP");
  grT->GetXaxis()->SetRangeUser(0.35,2.2);
  grT->GetXaxis()->SetTitle("Production Cross Section Ratio: #sigma_{exp.}/#sigma_{theo.}");
  grT->Draw("AP");
  c1->Update();

  TGraphAsymmErrors* grT8 = new TGraphAsymmErrors(nBoson,xBoson8,yBoson8,exhBoson8,exhBoson8,eyBoson8,eyBoson8);
  grT8->SetTitle("");
  grT8->SetMarkerColor(kRed);
  grT8->SetMarkerStyle(8);
  grT8->Draw("AP same");
  grT8->GetXaxis()->SetRangeUser(0.35,2.2);
  grT8->Draw("AP same");
  c1->Update();

  TLine Line1(1, -1, 1, 6.5);
  //TLine Line1(0, Line1v, rateRlxV1Iso->FindBin(29) - 0.5, Line1v);
  Line1.SetLineWidth(2);
  Line1.SetLineColor(kGray);
  Line1.DrawLine(1, -1, 1, 6.5);


  TGraphAsymmErrors* gr = new TGraphAsymmErrors(nBoson,xBoson,yBoson,exlBoson,exlBoson,eyBoson,eyBoson);
  gr->SetTitle("");
  gr->SetMarkerColor(kRed);
  gr->SetMarkerStyle(8);
  gr->SetLineColor(kRed);
  gr->Draw("Psame");

  grT->Draw("APsame");
  grT->SetMinimum(-1);
  grT8->SetMinimum(-1);
  grT8->Draw("Psame");

  grT->GetYaxis()->SetLabelOffset(999);
  grT->GetYaxis()->SetLabelSize(0);

  TLegend *leg = new TLegend(0.51,0.7,0.965,0.95);//  Leg = new TLegend(0.74,0.65,0.99,0.95); 

  applyLegStyle(leg);
  leg->AddEntry(grT8,"8 TeV CMS measurement","pl");
  leg->AddEntry(grT,"13 TeV CMS measurement","pl");
  leg->Draw();


  ///finish making the labels
  pt->AddText("W #rightarrow e#nu");      label->AddText("1.017 #pm 0.02 (stat.) #pm 0.16 (syst. +stat.) ");   pt->Draw();   label->Draw();
  pt1->AddText("W #rightarrow #mu#nu");  label1->AddText("0.996 #pm 0.02 (stat.) #pm 0.06 (syst. + stat.)");   pt1->Draw();   label1->Draw();
  pt2->AddText("Z #rightarrow ee");      label2->AddText("1.0 #pm 0.01 (stat.) #pm 0.01 (syst. + stat.)");    pt2->Draw();   label2->Draw();
  pt3->AddText("Z #rightarrow #mu#mu");  label3->AddText("1.025 #pm 0.01 (stat.) #pm 0.01 (syst. + stat.)");  pt3->Draw();  label3->Draw();
  pt4->AddText("Z#rightarrow e#tau");    label4->AddText("1.04 #pm 0.18  (syst. + stat.)"); pt4->Draw();  label4->Draw();
  pt5->AddText("Z#rightarrow #mu#tau");  label5->AddText("0.73 #pm 0.15  (syst. + stat.)"); pt5->Draw();  label5->Draw();
  pt6->AddText("Z#rightarrow l#tau");    label6->AddText("0.88 #pm 0.16  (syst. + stat.)"); pt6->Draw();  label6->Draw();
  //pt6->AddText("#gamma#gamma"); label6->AddText("W");
  //pt7->AddText("#gamma#gamma"); label7->AddText("W");


  TPaveText *ptext = new TPaveText(0.308,8.00,0.968,8.65,"");
  ptext->AddText("CMS #bf{#it{Preliminary}}");
  ptext->SetFillColor(0);
  ptext->SetFillStyle(0);
  ptext->SetBorderSize(0);
  ptext->SetShadowColor(0);
  ptext->Draw("E");
  /*
  pt4->Draw();
  pt5->Draw();
  pt6->Draw();
  pt7->Draw();

  label4->Draw();
  label5->Draw();
  label6->Draw();
  label7->Draw();
  */


  c1->SaveAs("~/Dropbox/TauDAS/crossSectionsComp.png");
  c1->SaveAs("~/Dropbox/TauDAS/crossSectionsComp.pdf");

}
/*

e
+e
− 0.45 \pm 0.01 (stat.) \pm 0.01 (syst.) \pm 0.01 (lum.) 0.45 \pm 0.02
Z µ
+µ
− 0.40 \pm 0.01 (stat.) \pm 0.01 (syst.) \pm 0.01 (lum.) 0.39 \pm 0.02
`
+`
− 0.41 \pm 0.01 (stat.) \pm 0.01 (syst.) \pm 0.01 (lum.) 0.40 \pm 0.01
 */


  /*
  Double_t x[n]   = {-0.22, 0.05, 0.25, 0.35, 0.5, 0.61,0.7,0.85,0.89,0.95};
  Double_t y[n]   = {1,2.9,5.6,7.4,9,9.6,8.7,6.3,4.5,1};
  Double_t exl[n] = {.05,.1,.07,.07,.04,.05,.06,.07,.08,.05};
  Double_t exh[n] = {.02,.08,.05,.05,.03,.03,.04,.05,.06,.03};
  */

/*


γγ 1.06 ± 0.01 ± 0.12 -1 5.0 fb
Wγ, (NLO th.) 1.16 ± 0.03 ± 0.13 -1 5.0 fb
Zγ, (NLO th.) 0.98 ± 0.01 ± 0.05 -1 5.0 fb
Zγ, (NLO th.) 0.98 ± 0.01 ± 0.05 -1 19.5 fb
WW+WZ 1.01 ± 0.13 ± 0.14 -1 4.9 fb
WW 1.07 ± 0.04 ± 0.09 -1 4.9 fb
WW 1.00 ± 0.02 ± 0.08 -1 19.4 fb
WW 0.96 ± 0.05 ± 0.08 -1 2.3 fb
WZ 1.08 ± 0.07 ± 0.06 -1 4.9 fb
WZ 1.04 ± 0.03 ± 0.07 -1 19.6 fb
WZ 0.80 ± 0.06 ± 0.07 -1 2.3 fb
ZZ 0.97 ± 0.13 ± 0.07 -1 4.9 fb
ZZ 0.97 ± 0.06 ± 0.08 -1 19.6 fb
ZZ 0.90 ± 0.11 ± 0.04 -1 2.6 fb




 */
