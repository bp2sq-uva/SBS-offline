#include "digsim_data.h"
#include <TTree.h>
#include <iostream>
#define DEBUG 0

namespace SBSDigSim{
  
  template<typename T>
  int VDetData_t::SetupBranch(TTree *tree, const char* prefix,
			      const char* varname, T &var)
  {
    TString branchname = TString::Format("%s.%s",prefix,varname);
#if DEBUG>0
    printf("%s\n", branchname.Data());
#endif
    if(!tree)
      return 1;
    var = 0;
    int ret = tree->SetBranchAddress(branchname.Data(),&var);
    if( ret != 0 ) {
      std::cerr << "Unable to set branch '" << branchname
		<< "' failed with error code: " << ret << std::endl;
      return 1;
    }
    
    return 0;
  }
  
  bool MCTrack_t::SetupBranches(TTree *tree, const char* prefix)
  {
    int ret = 0;
    ret += SetupBranch(tree,prefix,"ntracks", ntracks);
    ret += SetupBranch(tree,prefix,"source", source);
    ret += SetupBranch(tree,prefix,"trid", trid);
    ret += SetupBranch(tree,prefix,"pid", pid);
    ret += SetupBranch(tree,prefix,"x", x);
    ret += SetupBranch(tree,prefix,"y", y);
    ret += SetupBranch(tree,prefix,"t", t);
    ret += SetupBranch(tree,prefix,"p", p);
    ret += SetupBranch(tree,prefix,"dx", dx);
    ret += SetupBranch(tree,prefix,"dy", dy);
    ret += SetupBranch(tree,prefix,"xv", xv);
    ret += SetupBranch(tree,prefix,"yv", yv);
    ret += SetupBranch(tree,prefix,"zv", zv);
    ret += SetupBranch(tree,prefix,"pxv", pxv);
    ret += SetupBranch(tree,prefix,"pyv", pyv);
    ret += SetupBranch(tree,prefix,"pzv", pzv);
    ret += SetupBranch(tree,prefix,"weight", weight);
    return (ret ==0);
  }
  
  bool TrackMCHit_t::SetupBranches(TTree *tree, const char* prefix)
  {
    int ret = 0;
    ret += SetupBranch(tree,prefix,"nhits", nhits);
    ret += SetupBranch(tree,prefix,"source", source);
    ret += SetupBranch(tree,prefix,"trid", trid);
    ret += SetupBranch(tree,prefix,"pid", pid);
    ret += SetupBranch(tree,prefix,"xhit", xhit);
    ret += SetupBranch(tree,prefix,"yhit", yhit);
    ret += SetupBranch(tree,prefix,"thit", thit);
    ret += SetupBranch(tree,prefix,"e", e);
    ret += SetupBranch(tree,prefix,"weight", weight);
    return (ret ==0);
  }
  
  bool PMTSimHit_t::SetupBranches(TTree *tree, const char* prefix)
  {
    int ret = 0;
    ret += SetupBranch(tree,prefix,"nhits", nhits);
    ret += SetupBranch(tree,prefix,"src", src);
    //ret += SetupBranch(tree,prefix,"trid", trid);
    //ret += SetupBranch(tree,prefix,"pid", pid);
    ret += SetupBranch(tree,prefix,"chan", chan);
    if(fReadEdep)ret += SetupBranch(tree,prefix,"edep", edep);
    ret += SetupBranch(tree,prefix,"npe", npe);
    ret += SetupBranch(tree,prefix,"time", time);
    if(fReadTimes){
      ret += SetupBranch(tree,prefix,"t_lead", t_lead);
      ret += SetupBranch(tree,prefix,"t_trail", t_trail);
    }
    return (ret ==0);
  }

  bool GEMSimHit_t::SetupBranches(TTree *tree, const char* prefix)
  {
    int ret = 0;
    ret += SetupBranch(tree,prefix,"nhits", nhits);
    ret += SetupBranch(tree,prefix,"src", src);
    ret += SetupBranch(tree,prefix,"trid", trid);
    ret += SetupBranch(tree,prefix,"plane", plane);
    ret += SetupBranch(tree,prefix,"module", module);
    ret += SetupBranch(tree,prefix,"edep", edep);
    ret += SetupBranch(tree,prefix,"time", time);
    ret += SetupBranch(tree,prefix,"xpos", xpos);
    ret += SetupBranch(tree,prefix,"ypos", ypos);
    ret += SetupBranch(tree,prefix,"px", px);
    ret += SetupBranch(tree,prefix,"py", py);
    ret += SetupBranch(tree,prefix,"pz", pz);
    ret += SetupBranch(tree,prefix,"sizex", sizex);
    ret += SetupBranch(tree,prefix,"sizey", sizey);
    ret += SetupBranch(tree,prefix,"startx", startx);
    ret += SetupBranch(tree,prefix,"starty", starty);
    return (ret ==0);
  }
  
  /*  
  bool HitData_t::SetupBranches(TTree *tree, const char* prefix)
  {
    printf("%s\n", prefix);
    int ret = 0;
    ret += SetupBranch(tree,prefix,"nhits", nhits);
    ret += SetupBranch(tree,prefix,"chan", chan);
    ret += SetupBranch(tree,prefix,"dataword", dataword);
    if(fReadADC)ret += SetupBranch(tree,prefix,"adc", adc);
    if(fReadTDC){
      ret += SetupBranch(tree,prefix,"tdc_l", tdc_l);
      ret += SetupBranch(tree,prefix,"tdc_t", tdc_t);
    }
    return (ret ==0);
  }

  bool SampHitData_t::SetupBranches(TTree *tree, const char* prefix)
  {
    int ret = 0;
    ret += SetupBranch(tree,prefix,"nhits", nhits);
    ret += SetupBranch(tree,prefix,"chan", chan);
    // "dataword" could be the header, the number of sample words or the TDC word
    ret += SetupBranch(tree,prefix,"dataword", dataword);
    ret += SetupBranch(tree,prefix,"nsamps", nsamps);
    ret += SetupBranch(tree,prefix,"adcsum", adc);
    if(fReadTDC){
      ret += SetupBranch(tree,prefix,"tdc_l", tdc_l);
      ret += SetupBranch(tree,prefix,"tdc_t", tdc_t);
    }
    ret += SetupBranch(tree,prefix,"nsamps", nsamps);
    ret += SetupBranch(tree,prefix,"samps_adc", samps_adc);
    ret += SetupBranch(tree,prefix,"samps_datawords", samps_datawords);
    return (ret ==0);
  }
  */
  
  bool UHitData_t::SetupBranches(TTree *tree, const char* prefix)
  {
    printf("%s\n", prefix);
    int ret = 0;
    ret += SetupBranch(tree,prefix,"nhits", nhits);
    ret += SetupBranch(tree,prefix,"chan", chan);
    ret += SetupBranch(tree,prefix,"dataword", dataword);
    if(fReadADC)ret += SetupBranch(tree,prefix,"adc", adc);
    if(fReadTDC){
      ret += SetupBranch(tree,prefix,"tdc_l", tdc_l);
      ret += SetupBranch(tree,prefix,"tdc_t", tdc_t);
    }
    if(fReadSamples){
      ret += SetupBranch(tree,prefix,"nsamps", nsamps);
      ret += SetupBranch(tree,prefix,"samps_adc", samps_adc);
      ret += SetupBranch(tree,prefix,"samps_datawords", samps_datawords);
    }
    return (ret ==0);
  }
 
  
}
