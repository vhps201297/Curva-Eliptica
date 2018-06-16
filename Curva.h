#ifndef CURVA_H
#define CURVA_H

#include "Punto.h"
#include "Aritmetica.h"
#include "ModularArith.h"
/*
 * Clase Curva:
 * Atributos:
 * long long p: Número primo en el cual se define la estructura de grupo sobre la curva elíptica.
 * long long a: Parámetro a de la curva conforme a la ecuacion y^2 = x^3 + ax + b;
 * long long b: Parámetro a de la curva.
 * long long h: Parámetro de espaciamiento de los puntos.
 */
class Curva
{ private:
    //Numero Primo 
    long long p;
    //Parametros de la curva y^2 = x^3 +ax+b
    long long a;
    long long b;
    //Cofactor 
    long long h;
    //Numero primo relativo a p donde se definira el grupo
    long long CalcH(long long p,int n);
  public:
    Curva();
    Curva(long long a,long long b,long long p,int M);
    Punto getG();
    long long getA();
    long long getB();
    long long getP();
    long long getH();
    
};

#endif
