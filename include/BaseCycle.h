// Dear emacs, this is -*- c++ -*-
// $Id: BaseCycle.h,v 1.3 2012/04/04 13:08:57 peiffer Exp $
#ifndef BaseCycle_H
#define BaseCycle_H

// SFrame include(s):
#include "core/include/SCycleBase.h"

#include "Objects.h"
#include "Selection.h"
#include "BaseCycleContainer.h"
#include "PUWeightProducer.h"

/**
 *   @short Put short description of class here
 *
 *          Put a longer description over here...
 *
 *  @author Put your name here
 * @version $Revision: 1.3 $
 */


class BaseCycle : public SCycleBase {

public:
   /// Default constructor
   BaseCycle();
   /// Default destructor
   ~BaseCycle();

   /// Function called at the beginning of the cycle
   virtual void BeginCycle() throw( SError );
   /// Function called at the end of the cycle
   virtual void EndCycle() throw( SError );

   /// Function called at the beginning of a new input data
   virtual void BeginInputData( const SInputData& ) throw( SError );
   /// Function called after finishing to process an input data
   virtual void EndInputData  ( const SInputData& ) throw( SError );

   /// Function called after opening each new input file
   virtual void BeginInputFile( const SInputData& ) throw( SError );

   /// Function called for every event
   virtual void ExecuteEvent( const SInputData&, Double_t ) throw( SError );

private:
   //
   // Put all your private variables here
   //

  std::string JetCollection, ElectronCollection, MuonCollection, TauCollection, PhotonCollection, PrimaryVertexCollection, METName, TopJetCollection, PrunedJetCollection, GenParticleCollection;
  bool addGenInfo;
  std::string pu_filename_mc,  pu_filename_data,  pu_histname_mc, pu_histname_data;

  BaseCycleContainer bcc;

  //output variables
  std::vector< Electron > o_electrons;  
  std::vector< Muon > o_muons;
  std::vector< Tau > o_taus;
  std::vector< Photon > o_photons;
  std::vector< PrimaryVertex > o_pvs;
  std::vector< Jet > o_jets;
  std::vector< TopJet > o_topjets;
  std::vector< TopJet > o_prunedjets;
  MET o_met;
  std::vector<std::string> o_triggerNames;
  std::vector<bool> o_triggerResults;
  std::vector<int> o_L1_prescale;
  std::vector<int> o_HLT_prescale;
  std::vector< GenParticle > o_genparticles;
  GenInfo o_genInfo;

  bool newrun;

  PUWeightProducer *puwp;
  
  // Macro adding the functions for dictionary generation
  ClassDef( BaseCycle, 0 );

}; // class BaseCycle

#endif // BaseCycle_H

