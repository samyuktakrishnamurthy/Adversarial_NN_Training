#include "TTree.h"
#include "TChain.h"
#include "TFile.h"
#include "TString.h"
#include <iostream>
#include <typeinfo>
void Prep_slim_trees(){
  //Path where the minitrees are stored
  TString path="/gpfs3/umass/HZZ/MG_0j_Ana_Offshell/NN_Variables/NN_Adversarial/minitrees/";
  //the 3 different productions
  TString patha="mc16a/";
  TString pathd="mc16d/";
  TString pathe="mc16e/";
  //Adding the root TTreet to the chain
  TChain *chain_qqZZ= new TChain("tree_incl_all","");
  TChain *chain_ggZZ= new TChain("tree_incl_all","");
  TChain *chain_ggHZZ= new TChain("tree_incl_all","");
  //ggllll no higgs is the ggZZ background
  //llll are the qqZZ processes in different mass regions
  //ggllll is the SBI
  //ggllll higgs only is the signal
  chain_ggZZ->Add(path + patha + "mc16_13TeV.345706.*");
  chain_ggZZ->Add(path + pathd + "mc16_13TeV.345706.*");
  chain_ggZZ->Add(path + pathe + "mc16_13TeV.345706.*");

  chain_ggHZZ->Add(path +patha + "mc16_13TeV.345712.*");
  chain_ggHZZ->Add(path +pathd + "mc16_13TeV.345712.*");
  chain_ggHZZ->Add(path +pathe + "mc16_13TeV.345712.*");

  chain_qqZZ->Add(path + patha + "mc16_13TeV.36425*.Sherpa_222_NNPDF30NNLO_llll*");
  chain_qqZZ->Add(path + pathd + "mc16_13TeV.36425*.Sherpa_222_NNPDF30NNLO_llll*");
  chain_qqZZ->Add(path + pathe + "mc16_13TeV.36425*.Sherpa_222_NNPDF30NNLO_llll*");

}
