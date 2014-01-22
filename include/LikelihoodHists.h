#ifndef LikelihoodHists_H
#define LikelihoodHists_H

#include "SFrameTools/include/BaseHists.h"
#include "TF1.h"
#include "TH1.h"
#include "TFile.h"

/**
 *   Class for booking Ht and Higgs mass likelihood hists
 *
 *   
 */

class LikelihoodHists : public BaseHists {

public:
   /// Named constructor
  LikelihoodHists(const char* name,  TString filename="", TString HypoMass="", TString mode="default", TString btagfilename="");

   /// Default destructor
   ~LikelihoodHists() {
     delete HTSignalsingle;
     delete HTSignalmulti;
     delete mHSignalsingle;
     delete mHSignalmulti;
     delete HTQCDsingle;
     delete HTQCDmulti;
     delete HTttbarsingle;
     delete HTttbarmulti;
     delete mHQCDsingle;
     delete mHQCDmulti;
     delete mHttbarsingle;
     delete mHttbarmulti;
     delete HTbacksingle;
     delete HTbackmulti;
     delete mHbacksingle;
     delete mHbackmulti;
     file_mc->Close();
     delete file_mc;
   };

   void Init();

   void Fill();

   private:

   TString m_HypoMass;
   TString m_filename;
   TFile *file_mc;
   TH1F * HTSignalsingle;
   TH1F * HTSignalmulti;
   TH1F * mHSignalsingle;
   TH1F * mHSignalmulti;
   TH1F * HTQCDsingle;
   TH1F * HTQCDmulti;
   TH1F * HTttbarsingle;
   TH1F * HTttbarmulti;
   TH1F * mHQCDsingle;
   TH1F * mHQCDmulti;
   TH1F * mHttbarsingle;
   TH1F * mHttbarmulti;
   TH1F * HTbacksingle;
   TH1F * HTbackmulti;
   TH1F * mHbacksingle;
   TH1F * mHbackmulti;

   TString m_BTagEffiFilenameMC;
   TString m_BTaggingMode;

}; // class LikelihoodHists


#endif // LikelihoodHists_H

