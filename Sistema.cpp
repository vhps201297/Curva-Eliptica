#include "Sistema.h"
/*
 * Constructor
 */

Sistema::Sistema(Curva C,Punto G){
    this->C=C;
    this->G=G;
    this->privateKey=8209;
    calcPublicKey();
    this->k=1317;
}
/*
 * Método calcPublicKey:
 * Calcula la clave publica segun la definicion de privateKey * G.
 * No retorna nada.
 */
void Sistema::calcPublicKey(){
  this->publicKey= Aritmetica::MultEyP(this->privateKey,this->G,this->C.getA(),this->C.getP());  
}

/*
 * Método Decodifica:
 * Decodifica el mensaje dado dos puntos que envia el usuario con el que se esta comunicando.
 * Parámetros: 
 * Punto M: dado por M=kG generado por el que envia el mensaje.
 * Punto N: dado por N=Pm + kPb dado por el que envia el mensaje.
 * Retorna el caracter decodificado.
 */
char Sistema::Desencriptar(Punto M,Punto N){
    Punto P,Mm;
    char c;
    Mm=Aritmetica::MultEyP(this->privateKey,M,this->C.getA(),this->C.getP() );
    P=Aritmetica::RestaPyQ(N,Mm,this->C.getP());
    P.Print();
    c = Mensaje::Decodifica(P,this->C.getH());
    return c;
  }
Punto Sistema::Encriptar(Punto M,Punto publicKeyB){
      Punto N;
      Punto Aux;
      Aux = Aritmetica::MultEyP(this->k,publicKeyB,this->C.getA(),this->C.getP());
      N = Aritmetica::SumaPyQ(M,Aux,this->C.getP());
      return N;    
  }
Punto Sistema::getkG(){
    return Aritmetica::MultEyP(this->k,this->G,this->C.getA(),this->C.getP() );
  }

/*
 * Métodos Accesores
 */
Punto Sistema::getPublicKey(){return this->publicKey;}
Punto Sistema::getG(){return this->G;}
Curva Sistema::getCurva(){return this->C;}
void Sistema::setG(Punto G){this->G=G;}
void Sistema::setCurva(Curva C){this->C=C;}
