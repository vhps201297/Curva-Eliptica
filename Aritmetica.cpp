#include "Aritmetica.h"
/*
 * Método MultEyP:
 * Multiplica un escalar por un punto correspondiente a la aritmetica de curva eliptica.
 * Parámetros:
 * long long k: Escalar por el cual va a ser multiplicado el punto.
 * Punto P: Punto al cual se le va a aplicar la multiplicacion.
 * long long a: Parámetro a de la curva eliptica.
 * long long p: Parámetro p de la curva eliptica.
 * Regresa un punto correspondiente a la multiplicacion por un escalar.
 */
static Punto Aritmetica::MultEyP(long long k,Punto P,long long a,long long p){
    float c,d;
    int i,n;
    long long t;
    
    c=log10(k);
    d=log10(2);
    n=c/d + 1;
    int B[n];
    
    //Convierte de decimal a binario para multiplicar el escalar por el punto.
    i=n-1;
    t=k;
    while(i>-1){
      B[i]=t%2;
      t=t/2;
      i--;
    }    
    //
     
    Punto R(0,0);
    for(i=0;i<n;i++){
      R=SumaPyP(R,a,p);
      if(B[i]==1){
        R=SumaPyQ(R,P,p);
      }
    }
    return R;
  }

/*
 * Método SumaPyP: 
 * Multiplica por dos un punto (lo que es equivalente a sumarlo dos veces)
 * Parámetros:
 * Punto P:Punto a sumar.
 * long long a: Parámetro de la curva.
 * long long p: Parámetro de la curva.
 */
static Punto Aritmetica::SumaPyP(Punto P,long long a,long long p){

  if(P.getX()==0 && P.getY() == 0){
      return P;
    }
  
  long long l;
  long long Rx;
  long long Ry;

  //Cálculo de lambda
  l=3*(P.getX()*P.getX()) + a;
  l=l*ModularArith::InvMod(2*P.getY(),p);
  l=l%p;
  //Calculo de la componente X dado por X=(l^2 - 2Xp) mod p;
  Rx=(l*l-2*P.getX() )%p;
  //Ya que solo se trabaja con enteros positivos,si hay uno negativo, le corresponde su siguiente número congruente.
  if(Rx<0){
    Rx=Rx+p;
  }
  //Calculo de la componente Y dado por Y=(l*(Xp-Xr)-Yp) mod p.
  Ry=(l*(P.getX()-Rx)-P.getY() )%p;
  //Ya que solo se trabaja con enteros positivos,si hay uno negativo, le corresponde su siguiente número congruente.
  if(Ry<0){
    Ry=Ry+p;
  }
  return Punto(Rx,Ry);
  }
/*
 *Método RestaPyQ:
 *Calcula el inverso aditivo segun la aritmética de curva elíptica.
 *Regresa el punto correspondiente.
 */
static Punto Aritmetica::RestaPyQ(Punto P, Punto Q,long long p){
    Serial.println("Resta");
    long long y;
    Punto R;
    y=p-Q.getY();
    print_int64_t(y);
    Q.setY(y);
    Q.Print();
    R=SumaPyQ(P,Q,p);
    return R;
  }
/*  
 *Método SumaPYQ:   
 *Suma dos puntos segun la aritmética de curva elíptica.
 *Regresa el punto correspontiente.
 */
static Punto Aritmetica::SumaPyQ(Punto P, Punto Q,long long p){
  /*
  Serial.println("Suma PyQ");
  P.Print();
  Q.Print();
  */
  if(P.getX()==0 && P.getY()==0 ){
      return Q;
  } 
  long long l;
  long long Rx;
  long long Ry;

  l=P.getY() - Q.getY();
  l=l*ModularArith::InvMod((P.getX() - Q.getX() ) ,p);
  l=l%p; 

  Rx=(l*l -P.getX() - Q.getX())%p;

  if(Rx<0){
    Rx=Rx+p;
  }

  Ry=(l*(P.getX() -Rx) - P.getY())%p;
  
 if(Ry<0){
    Ry=Ry+p;
  }

  return Punto(Rx,Ry);
  }

