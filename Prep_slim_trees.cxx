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
  chain_qqZZ->Add(path + patha + "mc16_13TeV.36425*.Sherpa_222_NNPDF30NNLO_llll*");
  chain_qqZZ->Add(path + pathd + "mc16_13TeV.36425*.Sherpa_222_NNPDF30NNLO_llll*");
  chain_qqZZ->Add(path + pathe + "mc16_13TeV.36425*.Sherpa_222_NNPDF30NNLO_llll*");

  chain_ggZZ->Add(path + patha + "mc16_13TeV.345706.*");
  chain_ggZZ->Add(path + pathd + "mc16_13TeV.345706.*");
  chain_ggZZ->Add(path + pathe + "mc16_13TeV.345706.*");

  chain_ggHZZ->Add(path +patha + "mc16_13TeV.345712.*");
  chain_ggHZZ->Add(path +pathd + "mc16_13TeV.345712.*");
  chain_ggHZZ->Add(path +pathe + "mc16_13TeV.345712.*");
  
  
  //Declare the variables to be used
  Int_t n_jets;
  vector<float> *lepton_eta;
  vector<float> *lepton_m;
  vector<float> *lepton_phi;
  vector<float> *lepton_pt;
  Float_t m4l_unconstrained;
  Float_t weight;
  Float_t pt4l_fsr;

  //Declare the new variables
  Double_t cos_theta_str;
  Double_t cos_theta_1;
  Double_t phi_1;
  Double_t phi;
  Double_t Z1_m;
  Double_t Z2_m;

  //Initialize the variables used
  lepton_pt=0;
  lepton_eta=0;
  lepton_m=0;
  lepton_phi=0;
  cos_theta_str=0;
  cos_theta_1 =0;
  phi_1=0;
  phi=0;
  Z1_m=0;
  Z2_m=0;
  n_jets=0;

  //Chain1 is qqZZ  
  chain_qqZZ->SetBranchAddress("weight", &weight);
  chain_qqZZ->SetBranchAddress("n_jets", &n_jets);
  chain_qqZZ->SetBranchAddress("lepton_pt", &lepton_pt);
  chain_qqZZ->SetBranchAddress("lepton_m", &lepton_m);
  chain_qqZZ->SetBranchAddress("lepton_eta", &lepton_eta);
  chain_qqZZ->SetBranchAddress("lepton_phi", &lepton_phi);
  chain_qqZZ->SetBranchAddress("pt4l_fsr", &pt4l_fsr);
  chain_qqZZ->SetBranchAddress("m4l_unconstrained", &m4l_unconstrained);
  
  chain_qqZZ->SetBranchStatus("*",0);

  chain_qqZZ->SetBranchStatus("weight", 1);
  chain_qqZZ->SetBranchStatus("n_jets", 1);
  chain_qqZZ->SetBranchStatus("lepton_pt", 1);
  chain_qqZZ->SetBranchStatus("lepton_m", 1);
  chain_qqZZ->SetBranchStatus("lepton_eta", 1);
  chain_qqZZ->SetBranchStatus("lepton_phi", 1);
  chain_qqZZ->SetBranchStatus("pt4l_fsr", 1);
  chain_qqZZ->SetBranchStatus("m4l_unconstrained",1);
  

  //Chain2 is ggZZ  
  chain_ggZZ->SetBranchAddress("weight", &weight);
  chain_ggZZ->SetBranchAddress("n_jets", &n_jets);
  chain_ggZZ->SetBranchAddress("lepton_pt", &lepton_pt);
  chain_ggZZ->SetBranchAddress("lepton_m", &lepton_m);
  chain_ggZZ->SetBranchAddress("lepton_eta", &lepton_eta);
  chain_ggZZ->SetBranchAddress("lepton_phi", &lepton_phi);
  chain_ggZZ->SetBranchAddress("pt4l_fsr", &pt4l_fsr);
  chain_ggZZ->SetBranchAddress("m4l_unconstrained", &m4l_unconstrained);
  
  chain_ggZZ->SetBranchStatus("*",0);

  chain_ggZZ->SetBranchStatus("weight", 1);
  chain_ggZZ->SetBranchStatus("n_jets", 1);
  chain_ggZZ->SetBranchStatus("lepton_pt", 1);
  chain_ggZZ->SetBranchStatus("lepton_m", 1);
  chain_ggZZ->SetBranchStatus("lepton_eta", 1);
  chain_ggZZ->SetBranchStatus("lepton_phi", 1);
  chain_ggZZ->SetBranchStatus("pt4l_fsr", 1);
  chain_ggZZ->SetBranchStatus("m4l_unconstrained",1);
  
  //Chain3 is ggHZZ  
  chain_ggHZZ->SetBranchAddress("weight", &weight);
  chain_ggHZZ->SetBranchAddress("n_jets", &n_jets);
  chain_ggHZZ->SetBranchAddress("lepton_pt", &lepton_pt);
  chain_ggHZZ->SetBranchAddress("lepton_m", &lepton_m);
  chain_ggHZZ->SetBranchAddress("lepton_eta", &lepton_eta);
  chain_ggHZZ->SetBranchAddress("lepton_phi", &lepton_phi);
  chain_ggHZZ->SetBranchAddress("pt4l_fsr", &pt4l_fsr);
  chain_ggHZZ->SetBranchAddress("m4l_unconstrained", &m4l_unconstrained);
  
  chain_ggHZZ->SetBranchStatus("*",0);

  chain_ggHZZ->SetBranchStatus("weight", 1);
  chain_ggHZZ->SetBranchStatus("n_jets", 1);
  chain_ggHZZ->SetBranchStatus("lepton_pt", 1);
  chain_ggHZZ->SetBranchStatus("lepton_m", 1);
  chain_ggHZZ->SetBranchStatus("lepton_eta", 1);
  chain_ggHZZ->SetBranchStatus("lepton_phi", 1);
  chain_ggHZZ->SetBranchStatus("pt4l_fsr", 1);
  chain_ggHZZ->SetBranchStatus("m4l_unconstrained",1);
 
  //Declare new trees that the chains will fill, we have 3 new tree, ggHZZ (higgs only), ggZZ background and qqZZ background)
 
  //First the qqZZ background
  TFile *file_qqZZ=new TFile("qqZZ_130_NN.root","RECREATE");
  file_qqZZ->cd();
  TTree *ntree_qqZZ=new TTree("tree_incl_all","");
  ntree_qqZZ->Branch("m4l_unconstrained", &m4l_unconstrained);
  ntree_qqZZ->Branch("weight", &weight);
  ntree_qqZZ->Branch("n_jets", &n_jets);
  ntree_qqZZ->Branch("lepton_pt", &lepton_pt);
  ntree_qqZZ->Branch("lepton_eta", &lepton_eta);
  ntree_qqZZ->Branch("lepton_phi", &lepton_phi);
  ntree_qqZZ->Branch("lepton_m", &lepton_m);
  ntree_qqZZ->Branch("Z1_m", &Z1_m);
  ntree_qqZZ->Branch("Z2_m", &Z2_m);
  ntree_qqZZ->Branch("pt4l_fsr", &pt4l_fsr);
  ntree_qqZZ->Branch("cos_theta_str", &cos_theta_str);
  ntree_qqZZ->Branch("cos_theta_1", &cos_theta_1);
  ntree_qqZZ->Branch("phi_1", &phi_1);
  ntree_qqZZ->Branch("phi", &phi);
  
  //Second the ggZZ background
  TFile *file_ggZZ=new TFile("ggZZ_130_NN.root","RECREATE");
  file_ggZZ->cd();
  TTree *ntree_ggZZ=new TTree("tree_incl_all","");
  ntree_ggZZ->Branch("m4l_unconstrained", &m4l_unconstrained);
  ntree_ggZZ->Branch("weight", &weight);
  ntree_ggZZ->Branch("n_jets", &n_jets);
  ntree_ggZZ->Branch("lepton_pt", &lepton_pt);
  ntree_ggZZ->Branch("lepton_eta", &lepton_eta);
  ntree_ggZZ->Branch("lepton_phi", &lepton_phi);
  ntree_ggZZ->Branch("lepton_m", &lepton_m);
  ntree_ggZZ->Branch("Z1_m", &Z1_m);
  ntree_ggZZ->Branch("Z2_m", &Z2_m);
  ntree_ggZZ->Branch("pt4l_fsr", &pt4l_fsr);
  ntree_ggZZ->Branch("cos_theta_str", &cos_theta_str);
  ntree_ggZZ->Branch("cos_theta_1", &cos_theta_1);
  ntree_ggZZ->Branch("phi_1", &phi_1);
  ntree_ggZZ->Branch("phi", &phi);
  
  //Lastly the ggHZZ background
  TFile *file_ggHZZ=new TFile("ggHZZ_130_NN.root","RECREATE");
  file_ggHZZ->cd();
  TTree *ntree_ggHZZ=new TTree("tree_incl_all","");
  ntree_ggHZZ->Branch("m4l_unconstrained", &m4l_unconstrained);
  ntree_ggHZZ->Branch("weight", &weight);
  ntree_ggHZZ->Branch("n_jets", &n_jets);
  ntree_ggHZZ->Branch("lepton_pt", &lepton_pt);
  ntree_ggHZZ->Branch("lepton_eta", &lepton_eta);
  ntree_ggHZZ->Branch("lepton_phi", &lepton_phi);
  ntree_ggHZZ->Branch("lepton_m", &lepton_m);
  ntree_ggHZZ->Branch("Z1_m", &Z1_m);
  ntree_ggHZZ->Branch("Z2_m", &Z2_m);
  ntree_ggHZZ->Branch("pt4l_fsr", &pt4l_fsr);
  ntree_ggHZZ->Branch("cos_theta_str", &cos_theta_str);
  ntree_ggHZZ->Branch("cos_theta_1", &cos_theta_1);
  ntree_ggHZZ->Branch("phi_1", &phi_1);
  ntree_ggHZZ->Branch("phi", &phi);
  

  Long64_t nentries_qqZZ = chain_qqZZ->GetEntries();
  Long64_t nentries_ggZZ = chain_ggZZ->GetEntries();
  Long64_t nentries_ggHZZ = chain_ggHZZ->GetEntries();
  Long64_t nbytes = 0, nb = 0;
  
  cout <<" qqZZ " << nentries_qqZZ << endl;
  cout <<" ggZZ " << nentries_ggZZ << endl;
  cout <<" ggHZZ " << nentries_ggHZZ << endl;


}
