#ifndef ARITMETICA_H
#define ARITMETICA_H

#include <Arduino.h>
#include "Punto.h"
#include "ModularArith.h"
#include <math.h>
/*
 * Clase Aritmetica:
 * Contiene las principales operaciones correspondientes a la aritmetica en curvas elípticas.
 */
class Aritmetica{
  public:
      static Punto MultEyP(long long k,Punto P,long long a,long long p);
      static Punto SumaPyP(Punto P,long long a,long long p);
      static Punto RestaPyQ(Punto P, Punto Q,long long p);
      static Punto SumaPyQ(Punto P, Punto Q,long long p);
};

#endif
