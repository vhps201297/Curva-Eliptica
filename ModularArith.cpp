#include "ModularArith.h"  
/*
 * Método MCD:
 * Obtiene el Máxmimo Común Divisor de dos números.
 * Regresa el Máximo Común Divisor.
 */
static long long ModularArith::MCD(long long a,long long b){
    while ( b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;  
 }

/*
 * Método InvMod:
 * Obtiene el inverso multiplicativo modular.
 * Regresa el inverso multiplicativo.
 */
static long long ModularArith::InvMod(long long a,long long b){

  if (a<0){
    a=a+b;
  }

  long long c1=1;
  long long c2=-(b/a);
  long long t1=0;
  long long t2 =1;
  long long r=b%a;
  long long x=a,y=r,c;
  while (r!=0){
    c=x/y;
    r=x%y;
    c1*=-c;
    c2*=-c;
    c1+=t1;
    c2+=t2;
    t1=-(c1-t1)/c;
    t2=-(c2-t2)/c;
    x=y;
    y=r; 
    }
    if(x==1){
        if(t2<0){
            return t2+b;
         }
        return t2;
    }else{
      return 0;
    }

  
}
/*
 * Método PowMod:
 * Calcula la potencia modular sin calcular la potencia a^x .
 * Regresa la potencia a^x mod m.
 */
static long long ModularArith::PowMod(long long a,long long x,long long m){

  long long res=1;
  a=a%m;
  while(x>0){
      if((x & 1) == 1){
          res=(res*a)%m;
       }
      x=x /2;
      a=(a*a)%m;
    }

   return res; 
  }
/*
 * Método SqrtMod:
 * Calcula la raiz cuadrada modular correspondiente a la congruencia y^2 mod p = n mod p.
 * Regresa la raiz cuadrada, en dado caso que no exista regresa 0.
 */
static long long ModularArith::SqrtMod(long long n,long long p){

     long long q=p-1;
     long long s=0;
     while(q%2 == 0){
        q/=2;
        s++;
     }
     
     if(s==1){
        long long r = PowMod(n,(p+1)/4,p);

        if(PowMod(r,2,p) == n%p){
            return r;
          }
          return 0;
      }
  
  long long z;
  for(z=2;z<p;z++){
    if (p-1 ==  PowMod(z,(p-1)/2,p)){
        break;
      }
   }
 
  long long c = PowMod(z, q, p);
  long long r = PowMod(n, (q+1)/2, p);
  long long t = PowMod(n, q, p);
  long long m = s;
  long long t2=0;
  long long i;
  long long b;
  while ( (t-1)%p != 0 ) {
      t2 = PowMod(t,2,p);
      for(i=1;i<m;i++){
          if( ( (t2-1)%p ) == 0){
              break;
            }
            t2=PowMod(t2,2,p);
        }
        
      b = PowMod(c , pow(2,m-i-1) ,p);
      r = (r*b)%p;
      c = PowMod(b,2,p);
      t = (t*c)%p;
      m=i;
    }
    return r;
  }


