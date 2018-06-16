#ifndef MODULARARITH_H
#define MODULARARITH_H

#include "Print.h"
/*
 * Clase ModularArith:
 * Clase que contiene operaciones escenciales en la aritmética modular.
 */
class ModularArith{
  public:
    static long long MCD(long long a,long long b);
    static long long InvMod(long long a,long long b);
    static long long PowMod(long long a,long long x,long long m);   
    static long long SqrtMod(long long n,long long p);

};



#endif

