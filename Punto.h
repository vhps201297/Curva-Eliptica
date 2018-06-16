#ifndef PUNTO_H
#define PUNTO_H

#include "Print.h"

/*
 * Clase Punto:
 * Representa un punto con dos componentes.
 */
class Punto{
  private:
      long long x;
      long long y;
  public:
    Punto();
    Punto(long long x,long long y);
    void setX(long long x);
    void setY(long long y);
    long long getX();
    long long getY();
    void Print();
};

#endif
