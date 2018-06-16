#include <EEPROM.h>
#include "Sistema.h"
#include "Conversion.h"

String defaultPass="7283615";
String password; 


//Parámetros de la curva
long long p=134217779;
long long a=13;
long long b=17;
//Objetos necesarios para el funcionamiento
Curva C (a,b,p,224);
Punto G (566031,86796771);
Sistema S(C,G);
Punto publicKeyB (93445459,89916351);
//Pin de salida:
int pin=13;
//tiempo en estado de espera de instrucciones.
int espera=30;
void setup() {
  
  Serial.begin(9600);
  //Declaramos el pin de salida
  pinMode(pin,OUTPUT);
  digitalWrite(pin,HIGH);
  //Recupera la contraseña almacenada en la eeprom, si no hay contraseña almacenada, se asigna la default, si si, se asigna esa.
  int eeAddress=0;
  String pass;
  EEPROM.get(eeAddress, pass);
  if(pass == ""){
      Serial.println("Escribió");
      EEPROM.put(eeAddress,defaultPass);
      password=defaultPass;   
   }else{
      Serial.println("Leyó correctamente");
      password=pass;
   }

}

void loop() {
    if (Serial.available()){
    String s=GetLine();
    /*
     * Regresa la Clave pública de Arduino.
     */
    if(s=="getPublicKey"){
          Punto Pk;
          Pk=S.getPublicKey();
          Serial.print("publicKey: ");
          Pk.Print();
          
    }
    /*
     * Regresa los datos de la curva p,a,b y m.
     */
   if(s=="getCurva"){
      Serial.print("P: ");
      print_int64_t(p);
      Serial.println();
      
      Serial.print("a: ");
      print_int64_t(a);
      Serial.println(); 

      Serial.print("b: ");
      print_int64_t(b);
      Serial.println();

      Serial.print("M: ");
      Serial.println(224); 
       
    }
    /*
     * Regresa el punto G (generador).
     */
    if(s=="getG"){
        Serial.print("Punto G: ");
        G.Print();
    }
    /*
     * Recibe la contraseña encriptada
     */
    if (s=="Pass:"){
        //Leemos la siguiente linea
        s=GetLine();
        //Creamos los puntos requeridos para desencriptar.
        Punto M, N [password.length()];
        //Convertimos el punto M de string a Punto.
        if(s=="M:"){
          s=GetLine();
          M=stringToPunto(s);
        }
        //Leemos la siguiente linea
        s=GetLine();
        //Leemos Los valores de N
        if(s=="N:"){
          //Leemos la contraseña encriptada y lo convertimos a puntos operables.
          s=GetLine();
          
          String P;
          int i=0,f;
          
          for(int k=0;k<password.length();k++){
               f=s.indexOf(";",i);
               P=s.substring(i,f);
               N[k]=stringToPunto(P);
               i=f+1;
               //print
               //N[k].Print();
            }

          
        }
       //Ya que tenemos los datos, procedemos a desencriptarlos.
       String contra;
       Punto Nn;
       for(int i=0;i<password.length();i++){
          Nn=N[i];
          char c=S.Desencriptar(M,Nn);
          contra+=c;
       }
       Punto Me;
       Me=S.getkG();
       Serial.println("M:");
       Me.Print();
       //Verificamos si la contraseña es correcta.
       if(contra==password){
            //Si Es correcta, le mandamos un mensaje de confirmacion a la app
            unsigned long long tiempo=millis();
            Punto N,C;
            C=Mensaje::Codifica('S',224,a,b,p);
            Serial.println("N:");
            N=S.Encriptar(C,publicKeyB);
            N.Print();
            //La parte de las acciones
            //Leemos la siguiente 
            while((tiempo/1000)<espera){
                Punto Nnn;
                s=GetLine();
                Nnn=stringToPunto(s);
                //Abrimos
                if(S.Desencriptar(M,Nnn)=='1'){
                  digitalWrite(pin,LOW);
                }
                //Cerramos 
                if(S.Desencriptar(M,Nnn)=='0'){
                  digitalWrite(pin,HIGH);
                }
                tiempo=millis();      
            }
        digitalWrite(pin,HIGH);    
       }else{
            Punto N,C;
            C=Mensaje::Codifica('N',224,a,b,p);
            Serial.println("N:");
            N=S.Encriptar(C,publicKeyB);
            N.Print();
        }
        //Cambio de contraseña
        s=GetLine();
        if(s=="Change Pass:"){
            s=GetLine();
            if(s=="N:"){
                //Leemos la nueva contraseña
                s=GetLine();
                Punto New [15];
                int k=0;
                int i=0,f;
                String D;
                String NewPass;
                //La convertimos a Puntos
                while(f!=-1){
                     
                   f=s.indexOf(";",i);
                   D=s.substring(i,f);
                   New[k]=stringToPunto(D);
                   i=f+1;
                   k++;
                  }
               //La desencriptamos
               for(int l=0;l<k;l++){
                   char c=S.Desencriptar(M,New[l]);
                   NewPass+=c;
                } 
               //La escribimos en la memoria
               EEPROM.put(0,NewPass);
               password= NewPass;
               Serial.println("Listo");
              }
          } 
      }
  }

}


/*
 * Funcion para leer un string hasta que haya un salto de linea.s
 */
String GetLine(){   
  String S = "" ;
       if ( Serial.available() ){    
        char c = Serial.read(); 
                while ( c != '\n') {              
                    S = S + c ;
                    delay(25) ;
                    c = Serial.read();
                    }
                  }
  return( S + '\n') ;
}












