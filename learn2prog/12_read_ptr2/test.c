#include <stdio.h>
#include <stdlib.h>

int f(int ** r, int ** s) {
  int temp = ** r;    
  int temp2 = **s;
  int * z = *r;      // 这里的*r其实指的是p的方框
  *r = *s;           // *r即为*p，所以*p指向b
  *s = z;            // *s即为*q，所以*q指向了a
  printf("**r = %d\n",**r); // **r指的是a
  printf("**s = %d\n",**s); // **s指的是b
  *z += 3;               // 此处指的是a
  **s -= 8;
  **r -= 19;
  return temp + temp2;
}

int main(void) {
  int a = 80;
  int b = 12;
  int * p = &a;
  int * q = &b;
  int x = f(&p, &q);
  printf("x = %d\n", x);
  printf("*p = %d\n", *p);
  printf("*q = %d\n", *q);
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  return EXIT_SUCCESS;
}
