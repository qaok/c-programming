#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n) {
 if (n == 0) {
    return 0;
  }
  size_t cur = 1;
  size_t longest = 1;
  
  for (size_t i = 1; i < n; i++) {
    if (array[i-1] < array[i]) {
      cur++;
      if (cur > longest) {
	longest = cur;
      }
    }
    else {
      cur = 1;
    }
  }
  return longest;
}
