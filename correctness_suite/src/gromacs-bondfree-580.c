#include <math.h>
#include <stdio.h>

void start_slice(){
  __asm__ __volatile__ ("");
}

void end_slice(){
  __asm__ __volatile__ ("");
}

float iprod(float* a,float* b)
{
  return (a[0]*b[0]+a[1]*b[1]+a[2]*b[2]);
}

float r_kj[10][3] = {
  {268453443323035648, 0.71653062105178833008, 1389.514892578125},
  {2.0770905828637609147e-10, 4.5552733528942065653e-24, 2.793811015866509706e-10},
  {0.092040725052356719971, 0.0022920905612409114838, 5.4301075065642613301e-21},
  {943433600, 5.7629808612905003154e-30, 1.9748078868190349535e-40},
  {3.715846901286568027e-07, 184.290313720703125, 1.8683431344172884485e-29},
  {4.208303749919650727e-08, 1.8677865192031556994e-39, 3.7274539151040134087e-43},
  {5.8237964177339397468e-42, 4.9045446251368597482e-44, 3.2664267203411485923e-42},
  {340.728424072265625, 2.7634128318965167637e-10, 1205.4989013671875},
  {1056530038784, 1067773132800, 4.8185892015429297611e-37},
  {0.0053226999007165431976, 1.2250422945568828905e-22, 8.1286535331538631898e-39}
};

int main() {
  start_slice();
  float nrkj2, nrkj;
  for (int i = 0; i < 10; i++){
    nrkj2 = iprod(r_kj[i], r_kj[i]);
    nrkj = sqrt(nrkj2);
    printf("%e\n", nrkj);
  }
  end_slice();
  return 0;
}