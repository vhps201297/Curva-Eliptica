#include "Print.h"

void print_int64_t(int64_t num) {

  char rev[128]; 
  char *p = rev+1;

  while (num > 0) {
    *p++ = '0' + ( num % 10);
    num/= 10;
  }
  p--;
  while (p > rev) {
    Serial.print(*p--);
  }
}
