#include "Conversion.h"
/*
 * Funcion que convierte un String a long long
 */
 
long long stringToLong(String s){
   char arr[20];
   s.toCharArray(arr, sizeof(arr));
   return atoll(arr);
}
/*
 * Funcion que convierte una cadena de caracteres a long long
 */
long long atoll(const char* ptr) {
  long long result = 0;
  while (*ptr && isdigit(*ptr)) {
    result *= 10;
    result += *ptr++ - '0';
  }
  return result;
}
/*
 * Convierte String a Punto
 */
Punto stringToPunto(String s){
  int coma;
  String x,y;
  long long X,Y;
  
  coma=s.indexOf(",");
  x=s.substring(1,coma);
  y=s.substring(coma+1,s.length()-1);
  
  X=stringToLong(x);
  Y=stringToLong(y);
  
  return Punto(X,Y);
}
