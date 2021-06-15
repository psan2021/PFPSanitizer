#include <stdio.h>
#include <math.h>

void start_slice(){
  __asm__ __volatile__ ("");
}

void end_slice(){
  __asm__ __volatile__ ("");
}

double foo(double a) {
  return (a*sqrt(a))/(a+0.1);
}

double sum(double (*fn)(double)) {
  start_slice();
  int i;
  double b = 0;

  for (i = 0; i < 100; ++i) {
    b += fn(b);
  }
  end_slice();
  return b;
}

int main(int argc, char *argv[]) {
  double x = sum(foo);
  printf("x:%e", x);
}
