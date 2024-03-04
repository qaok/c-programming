#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y) {
  if (y == 0) {
    return 1;
  }
  if (y == 1) {
    return x;
  }
  else {
    return x * power(x, y-1);
  }
}

int main(void) {
  unsigned x;
  unsigned y;
  unsigned ans;

  x = 2;
  y = 1;
  ans = 2;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }

  x = -2;
  y = 2;
  ans = 4;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }

  x = 3;
  y = 2;
  ans = 9;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }

  x = 0;
  y = 0;
  ans = 1;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }

  x = -2;
  y = 3;
  ans = -8;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }

  x = 1;
  y = 3;
  ans = 1;
  if (ans != power(x, y)) {
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}
