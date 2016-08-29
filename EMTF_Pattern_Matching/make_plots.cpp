//
//  make_plots.cpp
//  EMTF_Pattern_Matching
//
//  Created by Jamal Rorie on 8/18/16.
//  Copyright © 2016 Rice. All rights reserved.
//

#include "make_plots.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "TTree.h"
#include "TLeaf.h"
#include "TFile.h"
#include "TH1F.h"
//#include "TTreeReader.h"
//#include "TTreeReaderValue.h

using namespace std;


void first_plots(char *in_file)
{

    //CONFIGURE THIS SECTION BEFORE RUNNING
    bool verbose = true;                //Toggle "true" and "false" to readout debugging information
    //ofstream csv_test("csv_test.txt");  //Replace
    //gSystem->Load("/Applications/MadGraph5/MG5_aMC_v2_3_2_2/Delphes/libDelphes.so");    //For use on Emiri-OS X

    
    //Get old file, old tree and set top branch address
    TFile *f_emtf  = new TFile(in_file);
    TTree * tree = f_emtf->Get("ntuple/tree");
    int nentries = tree->GetEntries();
    //TTree *oldtree  = oldfile->Get("Delphes");
    //Int_t nentries  = (Int_t)oldtree->GetEntries();
    if(verbose){cout << "Track entries= "<<nentries<<endl;}
    
    
      ///////////////////////////////////////
  // Set branches for variables in NTuple
  ///////////////////////////////////////

  // RECO muon
  TTreeReaderValue<Int_t> my_numRecoMuons(myReader, "numRecoMuons");
  TTreeReaderArray<Float_t> my_recoEta(myReader, "recoEta");
  TTreeReaderArray<Float_t> my_recoPhi(myReader, "recoPhi");
  TTreeReaderArray<Float_t> my_recoPt(myReader, "recoPt");
  TTreeReaderArray<Float_t> my_recoSamPt(myReader, "recoSamPt");
  TTreeReaderArray<Int_t> my_recoIsTight(myReader, "recoIsTight");
  TTreeReaderArray<Int_t> my_recoCharge(myReader, "recoCharge");
  TTreeReaderArray<Int_t> my_recoMatchedStations(myReader, "recoMatchedStations");
  TTreeReaderArray<Int_t> my_recoNumCscSegs(myReader, "recoNumCscSegs");
  TTreeReaderArray<Int_t> my_recoCscSeg_endcap(myReader, "recoCscSeg_endcap");
  TTreeReaderArray<Int_t> my_recoCscSeg_station(myReader, "recoCscSeg_station");
  TTreeReaderArray<Int_t> my_recoCscSeg_sector(myReader, "recoCscSeg_sector");
  TTreeReaderArray<Int_t> my_recoCscSeg_ring(myReader, "recoCscSeg_ring");
  TTreeReaderArray<Int_t> my_recoCscSeg_chamber(myReader, "recoCscSeg_chamber");
  TTreeReaderArray<Int_t> my_recoCscSeg_lctId(myReader, "recoCscSeg_lctId");
  TTreeReaderArray<Float_t> my_recoCscSeg_glob_eta(myReader, "recoCscSeg_glob_eta");
  TTreeReaderArray<Float_t> my_recoCscSeg_glob_phi(myReader, "recoCscSeg_glob_phi");

  // All LCTs received by EMTF
  TTreeReaderValue<Int_t> my_numLCTs(myReader, "numLCTs");
  TTreeReaderArray<Int_t> my_lctBx(myReader, "lctBx");
  TTreeReaderArray<Int_t> my_lctEndcap(myReader, "lctEndcap");
  TTreeReaderArray<Int_t> my_lctStation(myReader, "lctStation");
  TTreeReaderArray<Int_t> my_lctSector(myReader, "lctSector");
  TTreeReaderArray<Int_t> my_lctRing(myReader, "lctRing");
  TTreeReaderArray<Int_t> my_lctChamber(myReader, "lctChamber");
  TTreeReaderArray<Int_t> my_lctCscId(myReader, "lctTriggerCSCID");
  TTreeReaderArray<Int_t> my_lctStrip(myReader, "lctStrip");
  TTreeReaderArray<Int_t> my_lctWire(myReader, "lctWire");
  TTreeReaderArray<Float_t> my_lctGlobalPhi(myReader, "lctGlobalPhi");
  TTreeReaderArray<Float_t> my_lctEta(myReader, "lctEta");

  // EMTF output tracks and their hits
  TTreeReaderValue<Int_t> my_numTrks(myReader, "numTrks");
  TTreeReaderArray<Float_t> my_trkEta(myReader, "trkEta");
  TTreeReaderArray<Float_t> my_trkPt(myReader, "trkPt");
  TTreeReaderArray<Int_t> my_trkMode(myReader, "trkMode");
  TTreeReaderArray<Int_t> my_numTrkLCTs(myReader, "numTrkLCTs");
  TTreeReaderArray<Int_t> my_trkLct_bx(myReader, "trkLct_bx");
  TTreeReaderArray<Int_t> my_trkLct_endcap(myReader, "trkLct_endcap");
  TTreeReaderArray<Int_t> my_trkLct_station(myReader, "trkLct_station");
  TTreeReaderArray<Int_t> my_trkLct_sector(myReader, "trkLct_sector");
  TTreeReaderArray<Int_t> my_trkLct_ring(myReader, "trkLct_ring");
  TTreeReaderArray<Int_t> my_trkLct_chamber(myReader, "trkLct_chamber");
  TTreeReaderArray<Int_t> my_trkLct_cscId(myReader, "trkLct_cscId");
  TTreeReaderArray<Int_t> my_trkLct_strip(myReader, "trkLct_strip");
  TTreeReaderArray<Int_t> my_trkLct_wire(myReader, "trkLct_wire");
  TTreeReaderArray<Float_t> my_trkLct_globPhi(myReader, "trkLct_globPhi");
  TTreeReaderArray<Float_t> my_trkLct_eta(myReader, "trkLct_eta");

  // CSCTF output tracks
  TTreeReaderValue<Int_t> my_numLegTrks(myReader, "numLegTrks");
  TTreeReaderArray<Float_t> my_leg_trkEta(myReader, "leg_trkEta");
  TTreeReaderArray<Float_t> my_leg_trkPt(myReader, "leg_trkPt");
  TTreeReaderArray<Int_t> my_numLegTrkLCTs(myReader, "numLegTrkLCTs");
  TTreeReaderArray<Int_t> my_leg_trkLct_endcap(myReader, "leg_trkLct_endcap");
  TTreeReaderArray<Int_t> my_leg_trkLct_station(myReader, "leg_trkLct_station");


        
}