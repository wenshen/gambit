//#
//# FILE: purenash.cc -- Find all pure strategy Nash equilibria
//#
//# $Id$
//#

#include "gambitio.h"
#include "normal.h"
#include "normiter.h"
#include "contiter.h"
#include "rational.h"
#include "glist.h"
#include "mixed.h"

template <class T> int FindPureNash(const NormalForm<T> &N,
				    gList<MixedProfile<T> > &eqs)
{
  ContIter<T> citer((NormalForm<T> &) N);
  
  do  {
    int flag = 1;
    NormalIter<T> niter(citer);
    
    for (int pl = 1; flag && pl <= N.NumPlayers(); pl++)  {
      T current = citer.Payoff(pl);
      for (int i = 1; i <= N.Dimensionality()[pl]; i++)  {
	niter.Next(pl);
	if (niter.Payoff(pl) > current)  {
	  flag = 0;
	  break;
	}
      }
    }
    
    if (flag)  {
      MixedProfile<T> temp(N);
      // zero out all the entries, since any equlibria are pure
      ((gVector<T> &) temp).operator=((T) 0);
      gArray<int> profile = citer.Get();
      for (int i = 1; i <= profile.Length(); i++)
	temp(i, profile[i]) = (T) 1;
      eqs.Append(temp);
    }
  }  while (citer.NextContingency());
  
  return eqs.Length();
}

#ifdef __GNUG__
#define TEMPLATE template
#elif defined __BORLANDC__
#define TEMPLATE
#pragma option -Jgd
#endif   // __GNUG__, __BORLANDC__

TEMPLATE int FindPureNash(const NormalForm<double> &, gList<MixedProfile<double> > &);
TEMPLATE int FindPureNash(const NormalForm<gRational> &,gList<MixedProfile<gRational> > &);

