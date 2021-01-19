//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Nov 24 16:34:50 2020 by ROOT version 6.22/02
// from TTree tree/Cosmic Muon Tree
// found on file: cristmorMSI_proto_100mill_0_leadbrickProto1B_1.root
//////////////////////////////////////////////////////////

#ifndef sc8muontree2_h
#define sc8muontree2_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class sc8muontree2 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           trigger;
   Int_t           nGenPar;
   Int_t           GenParId[39];   //[nGenPar]
   Int_t           GenParTk[39];   //[nGenPar]
   Int_t           GenParHit[39];   //[nGenPar]
   Float_t         GenParPx[39];   //[nGenPar]
   Float_t         GenParPy[39];   //[nGenPar]
   Float_t         GenParPz[39];   //[nGenPar]
   Float_t         GenParP[39];   //[nGenPar]
   Float_t         GenParM[39];   //[nGenPar]
   Float_t         GenParVx[39];   //[nGenPar]
   Float_t         GenParVy[39];   //[nGenPar]
   Float_t         GenParVz[39];   //[nGenPar]
   Int_t           nBar;
   Float_t         EdepS1[10];   //[nBar]
   Float_t         EdepS2[10];   //[nBar]
   Float_t         EdepS3[10];   //[nBar]
   Float_t         EdepS4[10];   //[nBar]
   Float_t         SteplS1[10];   //[nBar]
   Float_t         SteplS2[10];   //[nBar]
   Float_t         SteplS3[10];   //[nBar]
   Float_t         SteplS4[10];   //[nBar]
   Int_t           nTray;
   Float_t         EdepT1;
   Float_t         EdepT2;
   Float_t         EdepT3;
   Float_t         EdepT4;
   Float_t         SteplT1;
   Float_t         SteplT2;
   Float_t         SteplT3;
   Float_t         SteplT4;
   Float_t         EdepTestObj;
   Float_t         mStepTestObj;
   Int_t           nHitsR1;
   Int_t           HitsR1Id[13];   //[nHitsR1]
   Int_t           HitsR1Tk[13];   //[nHitsR1]
   Int_t           HitsR1Hit[13];   //[nHitsR1]
   Float_t         HitsR1Px[13];   //[nHitsR1]
   Float_t         HitsR1Py[13];   //[nHitsR1]
   Float_t         HitsR1Pz[13];   //[nHitsR1]
   Float_t         HitsR1P[13];   //[nHitsR1]
   Float_t         HitsR1M[13];   //[nHitsR1]
   Float_t         HitsR1Vx[13];   //[nHitsR1]
   Float_t         HitsR1Vy[13];   //[nHitsR1]
   Float_t         HitsR1Vz[13];   //[nHitsR1]
   Int_t           nHitsT1;
   Float_t         HitsT1Vx[6];   //[nHitsT1]
   Float_t         HitsT1Vy[6];   //[nHitsT1]
   Float_t         HitsT1Vz[6];   //[nHitsT1]
   Int_t           nHitsT2;
   Float_t         HitsT2Vx[6];   //[nHitsT2]
   Float_t         HitsT2Vy[6];   //[nHitsT2]
   Float_t         HitsT2Vz[6];   //[nHitsT2]
   Int_t           nMuons;
   Int_t           MuonId[1];   //[nMuons]
   Int_t           MuonTk[1];   //[nMuons]
   Int_t           MuonHit[1];   //[nMuons]
   Float_t         MuonPxE[1];   //[nMuons]
   Float_t         MuonPyE[1];   //[nMuons]
   Float_t         MuonPzE[1];   //[nMuons]
   Float_t         MuonPE[1];   //[nMuons]
   Float_t         MuonME[1];   //[nMuons]
   Float_t         MuonVxE[1];   //[nMuons]
   Float_t         MuonVyE[1];   //[nMuons]
   Float_t         MuonVzE[1];   //[nMuons]
   Float_t         MuonLength[1];   //[nMuons]
   Float_t         MuonEdep[1];   //[nMuons]

   // List of branches
   TBranch        *b_trigger;   //!
   TBranch        *b_nGenPar;   //!
   TBranch        *b_GenParId;   //!
   TBranch        *b_GenParTk;   //!
   TBranch        *b_GenParHit;   //!
   TBranch        *b_GenParPx;   //!
   TBranch        *b_GenParPy;   //!
   TBranch        *b_GenParPz;   //!
   TBranch        *b_GenParP;   //!
   TBranch        *b_GenParM;   //!
   TBranch        *b_GenParVx;   //!
   TBranch        *b_GenParVy;   //!
   TBranch        *b_GenParVz;   //!
   TBranch        *b_nBar;   //!
   TBranch        *b_EdepS1;   //!
   TBranch        *b_EdepS2;   //!
   TBranch        *b_EdepS3;   //!
   TBranch        *b_EdepS4;   //!
   TBranch        *b_SteplS1;   //!
   TBranch        *b_SteplS2;   //!
   TBranch        *b_SteplS3;   //!
   TBranch        *b_SteplS4;   //!
   TBranch        *b_nTray;   //!
   TBranch        *b_EdepT1;   //!
   TBranch        *b_EdepT2;   //!
   TBranch        *b_EdepT3;   //!
   TBranch        *b_EdepT4;   //!
   TBranch        *b_SteplT1;   //!
   TBranch        *b_SteplT2;   //!
   TBranch        *b_SteplT3;   //!
   TBranch        *b_SteplT4;   //!
   TBranch        *b_EdepTestObj;   //!
   TBranch        *b_StepTestObj;   //!
   TBranch        *b_nHitsR1;   //!
   TBranch        *b_HitsR1Id;   //!
   TBranch        *b_HitsR1Tk;   //!
   TBranch        *b_HitsR1Hit;   //!
   TBranch        *b_HitsR1Px;   //!
   TBranch        *b_HitsR1Py;   //!
   TBranch        *b_HitsR1Pz;   //!
   TBranch        *b_HitsR1P;   //!
   TBranch        *b_HitsR1M;   //!
   TBranch        *b_HitsR1Vx;   //!
   TBranch        *b_HitsR1Vy;   //!
   TBranch        *b_HitsR1Vz;   //!
   TBranch        *b_nHitsT1;   //!
   TBranch        *b_HitsT1Vx;   //!
   TBranch        *b_HitsT1Vy;   //!
   TBranch        *b_HitsT1Vz;   //!
   TBranch        *b_nHitsT2;   //!
   TBranch        *b_HitsT2Vx;   //!
   TBranch        *b_HitsT2Vy;   //!
   TBranch        *b_HitsT2Vz;   //!
   TBranch        *b_nMuons;   //!
   TBranch        *b_MuonId;   //!
   TBranch        *b_MuonTk;   //!
   TBranch        *b_MuonHit;   //!
   TBranch        *b_MuonPxE;   //!
   TBranch        *b_MuonPyE;   //!
   TBranch        *b_MuonPzE;   //!
   TBranch        *b_MuonPE;   //!
   TBranch        *b_MuonME;   //!
   TBranch        *b_MuonVxE;   //!
   TBranch        *b_MuonVyE;   //!
   TBranch        *b_MuonVzE;   //!
   TBranch        *b_MuonLength;   //!
   TBranch        *b_MuonEdep;   //!

   sc8muontree2(TTree *tree=0);
   virtual ~sc8muontree2();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef sc8muontree2_cxx
sc8muontree2::sc8muontree2(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("cristmorMSI_proto_100mill_0_leadbrickProto1B_1.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("cristmorMSI_proto_100mill_0_leadbrickProto1B_1.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

sc8muontree2::~sc8muontree2()
{
   //if (!fChain) return;
   //delete fChain->GetCurrentFile();
}

Int_t sc8muontree2::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t sc8muontree2::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void sc8muontree2::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("trigger", &trigger, &b_trigger);
   fChain->SetBranchAddress("nGenPar", &nGenPar, &b_nGenPar);
   fChain->SetBranchAddress("GenParId", GenParId, &b_GenParId);
   fChain->SetBranchAddress("GenParTk", GenParTk, &b_GenParTk);
   fChain->SetBranchAddress("GenParHit", GenParHit, &b_GenParHit);
   fChain->SetBranchAddress("GenParPx", GenParPx, &b_GenParPx);
   fChain->SetBranchAddress("GenParPy", GenParPy, &b_GenParPy);
   fChain->SetBranchAddress("GenParPz", GenParPz, &b_GenParPz);
   fChain->SetBranchAddress("GenParP", GenParP, &b_GenParP);
   fChain->SetBranchAddress("GenParM", GenParM, &b_GenParM);
   fChain->SetBranchAddress("GenParVx", GenParVx, &b_GenParVx);
   fChain->SetBranchAddress("GenParVy", GenParVy, &b_GenParVy);
   fChain->SetBranchAddress("GenParVz", GenParVz, &b_GenParVz);
   fChain->SetBranchAddress("nBar", &nBar, &b_nBar);
   fChain->SetBranchAddress("EdepS1", EdepS1, &b_EdepS1);
   fChain->SetBranchAddress("EdepS2", EdepS2, &b_EdepS2);
   fChain->SetBranchAddress("EdepS3", EdepS3, &b_EdepS3);
   fChain->SetBranchAddress("EdepS4", EdepS4, &b_EdepS4);
   fChain->SetBranchAddress("SteplS1", SteplS1, &b_SteplS1);
   fChain->SetBranchAddress("SteplS2", SteplS2, &b_SteplS2);
   fChain->SetBranchAddress("SteplS3", SteplS3, &b_SteplS3);
   fChain->SetBranchAddress("SteplS4", SteplS4, &b_SteplS4);
   fChain->SetBranchAddress("nTray", &nTray, &b_nTray);
   fChain->SetBranchAddress("EdepT1", &EdepT1, &b_EdepT1);
   fChain->SetBranchAddress("EdepT2", &EdepT2, &b_EdepT2);
   fChain->SetBranchAddress("EdepT3", &EdepT3, &b_EdepT3);
   fChain->SetBranchAddress("EdepT4", &EdepT4, &b_EdepT4);
   fChain->SetBranchAddress("SteplT1", &SteplT1, &b_SteplT1);
   fChain->SetBranchAddress("SteplT2", &SteplT2, &b_SteplT2);
   fChain->SetBranchAddress("SteplT3", &SteplT3, &b_SteplT3);
   fChain->SetBranchAddress("SteplT4", &SteplT4, &b_SteplT4);
   fChain->SetBranchAddress("EdepTestObj", &EdepTestObj, &b_EdepTestObj);
   fChain->SetBranchAddress("mStepTestObj", &mStepTestObj, &b_StepTestObj);
   fChain->SetBranchAddress("nHitsR1", &nHitsR1, &b_nHitsR1);
   fChain->SetBranchAddress("HitsR1Id", HitsR1Id, &b_HitsR1Id);
   fChain->SetBranchAddress("HitsR1Tk", HitsR1Tk, &b_HitsR1Tk);
   fChain->SetBranchAddress("HitsR1Hit", HitsR1Hit, &b_HitsR1Hit);
   fChain->SetBranchAddress("HitsR1Px", HitsR1Px, &b_HitsR1Px);
   fChain->SetBranchAddress("HitsR1Py", HitsR1Py, &b_HitsR1Py);
   fChain->SetBranchAddress("HitsR1Pz", HitsR1Pz, &b_HitsR1Pz);
   fChain->SetBranchAddress("HitsR1P", HitsR1P, &b_HitsR1P);
   fChain->SetBranchAddress("HitsR1M", HitsR1M, &b_HitsR1M);
   fChain->SetBranchAddress("HitsR1Vx", HitsR1Vx, &b_HitsR1Vx);
   fChain->SetBranchAddress("HitsR1Vy", HitsR1Vy, &b_HitsR1Vy);
   fChain->SetBranchAddress("HitsR1Vz", HitsR1Vz, &b_HitsR1Vz);
   fChain->SetBranchAddress("nHitsT1", &nHitsT1, &b_nHitsT1);
   fChain->SetBranchAddress("HitsT1Vx", HitsT1Vx, &b_HitsT1Vx);
   fChain->SetBranchAddress("HitsT1Vy", HitsT1Vy, &b_HitsT1Vy);
   fChain->SetBranchAddress("HitsT1Vz", HitsT1Vz, &b_HitsT1Vz);
   fChain->SetBranchAddress("nHitsT2", &nHitsT2, &b_nHitsT2);
   fChain->SetBranchAddress("HitsT2Vx", HitsT2Vx, &b_HitsT2Vx);
   fChain->SetBranchAddress("HitsT2Vy", HitsT2Vy, &b_HitsT2Vy);
   fChain->SetBranchAddress("HitsT2Vz", HitsT2Vz, &b_HitsT2Vz);
   fChain->SetBranchAddress("nMuons", &nMuons, &b_nMuons);
   fChain->SetBranchAddress("MuonId", &MuonId, &b_MuonId);
   fChain->SetBranchAddress("MuonTk", &MuonTk, &b_MuonTk);
   fChain->SetBranchAddress("MuonHit", &MuonHit, &b_MuonHit);
   fChain->SetBranchAddress("MuonPxE", &MuonPxE, &b_MuonPxE);
   fChain->SetBranchAddress("MuonPyE", &MuonPyE, &b_MuonPyE);
   fChain->SetBranchAddress("MuonPzE", &MuonPzE, &b_MuonPzE);
   fChain->SetBranchAddress("MuonPE", &MuonPE, &b_MuonPE);
   fChain->SetBranchAddress("MuonME", &MuonME, &b_MuonME);
   fChain->SetBranchAddress("MuonVxE", &MuonVxE, &b_MuonVxE);
   fChain->SetBranchAddress("MuonVyE", &MuonVyE, &b_MuonVyE);
   fChain->SetBranchAddress("MuonVzE", &MuonVzE, &b_MuonVzE);
   fChain->SetBranchAddress("MuonLength", &MuonLength, &b_MuonLength);
   fChain->SetBranchAddress("MuonEdep", &MuonEdep, &b_MuonEdep);
   Notify();
}

Bool_t sc8muontree2::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void sc8muontree2::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t sc8muontree2::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef sc8muontree2_cxx
