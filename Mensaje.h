#ifndef MENSAJE_H
#define MENSAJE_H

#include "Punto.h"
#include "ModularArith.h"
#include "Print.h"
/*
 * Clase Mensaje: 
 * Codifica un caracter conforme a la criptografáa de curva eliptica
 */
class Mensaje{
  public:
    static Punto Codifica(char letra,long long h,long long a,long long b,long long p);
    static char Decodifica(Punto p,long long h);
};

#endif
