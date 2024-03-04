#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

void processFile(FILE * f) {
  char ** lines = NULL;
  char * curr = NULL;
  size_t sz;
  size_t i = 0;

  //processing: building string array
  while (getline(&curr, &sz, f) >= 0) {
    lines = realloc(lines, (i+1) * sizeof(*lines));
    lines[i] = curr;
    curr = NULL;
    i++;
  }

  //sorting
  free(curr);
  sortData(lines, i);

  //printing then freeing each line
  for (size_t j = 0; j < i; j++) {
    printf("%s", lines[j]);
    free(lines[j]);
  }

  //clean up
  free(lines);
}

int main(int argc, char ** argv) {
  
  if (argc == 1) {
    // stdin
    processFile(stdin);
  }
  else {
    for (int i = 1; i < argc; i++) {
      // process each file one by one
        FILE *f = fopen(argv[i], "r");
        if (f == NULL) {
            fprintf(stderr, "Could not open file\n");
            return EXIT_FAILURE;
        }
        processFile(f);
        if (fclose(f) != 0) {
            fprintf(stderr, "Could not close file\n");
            return EXIT_FAILURE;
        }
    }
  }
  return EXIT_SUCCESS;
}
