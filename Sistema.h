#ifndef SISTEMA_H
#define SISTEMA_H

#include "Curva.h"
#include "Mensaje.h"
#include "Punto.h"
/*
 * Clase Sistema:
 * Codifica y decodifica un mensaje segun el cifrado ElGamal.
 * Atributos:
 * long long privateKey: Clave privada del dispositivo.
 * Punto publicKey: Clave publica del dispositivo.
 * Curva C: Curva donde esta definido el cifrado.
 * Punto G: Punto Base de la curva donde se realizan las operaciones
 * long long k: Número aleatorio para cifrar los mensajes.
 * 
 */
class Sistema{
  private:
    long long privateKey;
    Punto publicKey;
    Curva C;
    Punto G;
    long long k;
    void calcPublicKey();
  public:
    Sistema(Curva C,Punto G);
    Punto getPublicKey();
    Punto getG();
    Curva getCurva();
    char Desencriptar(Punto M,Punto N);
    Punto Encriptar(Punto M,Punto publicKeyB);
    //Punto publicKeyB();
    Punto getkG();
    void setG(Punto G);
    void setCurva(Curva C);
    
 
};

#endif
