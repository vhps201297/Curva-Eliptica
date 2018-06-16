#include "Curva.h"
/*
 * Constructor Clase Curva.
 */
Curva::Curva(long long a,long long b,long long p,int M){
  this->p=p;
  this->a=a;
  this->b=b;
  this->h=CalcH(p,M);
}
Curva::Curva(){}
/* Método CalcH: 
 * Método que calcula el valor de H (espaciamiento) conforme al número de caracteres disponibles y cumpliendo la propiedad de p>M*H.
 * Parámetros:
 * long long p: Número primo que define el grupo de la curva.
 * int n: Número de caracteres disponibles.
 * Regresa el valor h que es el espaciamiento de los puntos.
 */
long long Curva::CalcH(long long p,int n){
  long long h;
  long long N=n;
  h=p/N;
  return h;
  }

/*
 * Métodos Accesores
 */
long long Curva::getA(){return this->a;}
long long Curva::getB(){return this->b;}
long long Curva::getP(){return this->p;}
long long Curva::getH(){return this->h;}

