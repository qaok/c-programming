#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n) {
  size_t cur = 0;
  size_t longest = 0;
  for (int i = 1; i < n; i++) {
    if (array[i-1] < array[i]) {
      cur += 1;
      if (cur > longest) {
	longest = cur;
      }
    }
    else {
      cur = 0;
    }
  }
  return cur;
}
