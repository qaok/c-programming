#include <stdio.h>
#include <stdlib.h>


int main(void) {
  int anArray[] = {5,16,33,99};
  int * p = anArray;
  printf("*p = %d\n", *p);
  p++;
  printf("Now *p = %d\n", *p);
  int * q = &anArray[3];
  int ** x = &q;
  **x = 12;     // 此处anArray[3]=12
  *x = p;       // 此处的*x其实并不是**x，其实指的是*q，即此处为*p的指针指向了*p
  **x = 42;     // 结合上面所说，则此时是改变了*p所指地址处的值，则anArray[1]=42
  q[1] = 9;     // 由于*q指的是*p，而*p此时所指的index为1，则q[1]应该就是*p后移一位，则anArray[2]=9
  for (int i =0; i < 4; i++){
    printf("anArray[%d] = %d\n",i, anArray[i]);
  }
  return EXIT_SUCCESS;
}
