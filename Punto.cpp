#include "Punto.h"
/*
 * Constructorres
 */
Punto::Punto(){
  this->x=0;
  this->y=0;
}
Punto::Punto(long long x,long long y){
  this->x=x;
  this->y=y;
}
/*
 * Métodos Accesores
 */
void Punto::setX(long long x){this->x=x;}
void Punto::setY(long long y){this->y=y;}
long long Punto::getX(){return this->x;}
long long Punto::getY(){return this->y;}
/*
 * Método Print:
 * Imprime en el monitor serial el punto de la forma (x,y).
 * No retorna nada.
 */
void Punto::Print(){

  Serial.print("(");
  print_int64_t(this->x);
  Serial.print(",");
  print_int64_t(this->y);
  Serial.print(")");
  Serial.println();

}
