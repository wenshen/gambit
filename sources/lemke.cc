//
// FILE: lemke.cc -- Lemke-Howson module
//
// $Id$
//
//

#include "lemke.imp"

//---------------------------------------------------------------------------
//                       LemkeParams: member functions
//---------------------------------------------------------------------------

LemkeParams::LemkeParams(void)
  : dup_strat(0), maxdepth(0)
{ }

int Lemke(const NFSupport &support, const LemkeParams &params, 
          gList<MixedSolution> &solutions, gStatus &p_status,
          int &npivots, double &time)
{
  if (params.precision == precDOUBLE)  {
    LemkeModule<double> module(support, params);
    module.Lemke(p_status, params.dup_strat);
    for (int i = 1; i <= module.GetSolutions().Length(); i++)  
      solutions.Append(MixedSolution(module.GetSolutions()[i]));
    npivots = module.NumPivots();
    time = module.Time();
  }
  else  {
    LemkeModule<gRational> module(support, params);
    module.Lemke(p_status, params.dup_strat);
    for (int i = 1; i <= module.GetSolutions().Length(); i++)  
      solutions.Append(MixedSolution(module.GetSolutions()[i]));
    npivots = module.NumPivots();
    time = module.Time();
  }

  return 1;
}

#include "math/rational.h"

template class LemkeModule<double>;
template class LemkeModule<gRational>;
