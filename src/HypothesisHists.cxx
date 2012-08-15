#include "include/HypothesisHists.h"

using namespace std;

HypothesisHists::HypothesisHists(const char* name, HypothesisDiscriminator *discr) : BaseHists(name)
{
  // named default constructor
  m_discr = discr;
}

HypothesisHists::~HypothesisHists()
{
  // default destructor, does nothing
}

void HypothesisHists::Init()
{

  Book( TH1F( "M_ttbar_rec", "M_{t#bar{t}}^{rec} [GeV/c^{2}]", 1000, 0, 3000 ) );
  Book( TH1F("M_ttbar_resolution", "(M_{t#bar{t}}^{gen} - M_{t#bar{t}}^{rec})/M_{t#bar{t}}^{rec}", 1000, -5,5) );

  TString name = m_discr->GetLabel();
  name += " discriminator";
  double min=0;
  double max=500;
  if( m_discr->GetLabel()=="BestPossible"){
    min=0;
    max=6;
  }
  Book( TH1F("Discriminator", name , 100, min,max) );

  Book( TH2F("M_ttbar_rec_vs_M_ttbar_gen","M_{t#bar{t}}^{rec} [GeV/c^{2}] vs M_{t#bar{t}}^{gen} [GeV/c^{2}]",100,0,3000,100,0,3000));
  
}

void HypothesisHists::Fill()
{
  // fill the histograms

  EventCalc* calc = EventCalc::Instance();

  // important: get the event weight
  double weight = calc->GetWeight();

  ReconstructionHypothesis* hyp = m_discr->GetBestHypothesis();
  
  double mttbar_rec = (hyp->top_v4()+hyp->antitop_v4()).M();
  double mttbar_gen = ( calc->GetTTbarGen()->Top().v4() + calc->GetTTbarGen()->Antitop().v4()).M();

  Hist("M_ttbar_rec")->Fill(mttbar_rec, weight);
  Hist("M_ttbar_rec_vs_M_ttbar_gen")->Fill(mttbar_rec, mttbar_gen);
  Hist("M_ttbar_resolution")->Fill( (mttbar_gen-mttbar_rec)/mttbar_gen, weight);
  Hist("Discriminator")->Fill(hyp->discriminator(m_discr->GetLabel()), weight);
}

void HypothesisHists::Finish()
{
  // final calculations, like division and addition of certain histograms


}
