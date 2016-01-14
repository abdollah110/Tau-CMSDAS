#! /usr/bin/python

# To change this template, choose Tools | Templates
# and open the template in the editor.

__author__ = "abdollahmohammadi"
__date__ = "$Oct 31, 2013 12:02:55 PM$"

#! /usr/bin/python

# To change this template, choose Tools | Templates
# and open the template in the editor.

__author__ = "abdollahmohammadi"
__date__ = "$Mar 8, 2013 3:00:22 PM$"

import math

import ROOT
from ROOT import Double
from ROOT import TAxis
from ROOT import TCanvas
from ROOT import TFile
from ROOT import TH1F
from ROOT import TH2F
from ROOT import TLatex
from ROOT import TLegend
from ROOT import TNtuple
from ROOT import TProfile
from ROOT import gBenchmark
from ROOT import gROOT
from ROOT import gRandom
from ROOT import gStyle
from ROOT import gSystem



def _PlotMaker():


    Data_F=TFile("SingleMu.root", "OPEN")
    W_F=TFile("WJetsToLNu.root", "OPEN")
    DY_F=TFile("DYJetsToLL.root", "OPEN")
    TT_F=TFile("TTJets.root", "OPEN")


    Data_OS=Data_F.Get("visibleMassOS")
    W_OS=W_F.Get("visibleMassOS")
    DY_OS=DY_F.Get("visibleMassOS")
    TT_OS=TT_F.Get("visibleMassOS")


    Data_SS=Data_F.Get("visibleMassSS")
    W_SS=W_F.Get("visibleMassSS")
    DY_SS=DY_F.Get("visibleMassSS")
    TT_SS=TT_F.Get("visibleMassSS")
    

    QCD_OS = Data_OS.Integral() - (W_OS.Integral() + DY_OS.Integral() + TT_OS.Integral() )
    QCD_SS = Data_SS.Integral() - (W_SS.Integral() + DY_SS.Integral() + TT_SS.Integral() )

    print "OS/SS ratio is= ", QCD_OS/QCD_SS
    print "OS contamination is = ", (W_OS.Integral() + DY_OS.Integral() + TT_OS.Integral())/Data_OS.Integral()
    print "SS contamination is = ", (W_SS.Integral() + DY_SS.Integral() + TT_SS.Integral())/Data_SS.Integral()






if __name__ == "__main__":
    _PlotMaker()


