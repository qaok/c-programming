#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(void) {
  int array1[] = { 77, 33, 19, 99, 42, 6, 27, 4};
  int array2[] = { -3, -42, -99, -1000, -999, -88, -77};
  int array3[] = { 425, 59, -3, 77, 0, 36};
  int array4[] = { 2};
  int array5[] = {2,2,2,3};
  int array6[] = {-2};
  int array7[] = {2, 4, 3, 6, 10, 15, -1, 7, 8, 2};
  
  if (maxSeq(array1, 0)) {
    return EXIT_FAILURE;
  }
  if (maxSeq(array7, 10) != 4) {
    return EXIT_FAILURE;
  }  
  if (maxSeq(array1, 8) != 2) {
    return EXIT_FAILURE;
  }
  if (maxSeq(array6, 1) != 1) {
    return EXIT_FAILURE;
  }
  if (maxSeq(array5, 4) != 2) {
    return EXIT_FAILURE;
  }
  if (maxSeq(array4, 1) != 1) {
    return EXIT_FAILURE;
  }
  if (maxSeq(array2, 7) != 4) {
    return EXIT_FAILURE;
  }
  if (maxSeq(array3, 6) != 2) {
    return EXIT_FAILURE;
  }
  if (maxSeq(array1, 0)) {
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}
