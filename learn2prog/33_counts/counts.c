#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  counts_t * c = malloc(sizeof(* c));
  c->countArray = NULL;
  c->arraySize = 0;
  c->count_of_unknowns = 0;
  return c;
}
void addCount(counts_t * c, const char * name) {
  if (name == NULL) {
    c->count_of_unknowns++;
    return;
  }

  for (int i = 0; i < c->arraySize; i++) {
    if (strcmp(name, c->countArray[i].string) == 0) {
      c->countArray[i].count++;
      return;
    }
  }

  one_count_t * newCount = malloc(sizeof(one_count_t));
  newCount->string = malloc((strlen(name) + 1) * sizeof(char));
  strcpy(newCount->string, name);
  newCount->count = 1;
  c->countArray = realloc(c->countArray, (c->arraySize + 1) * sizeof(one_count_t));
  c->countArray[c->arraySize] = *newCount;
  c->arraySize++;
  free(newCount);
}

void printCounts(counts_t * c, FILE * outFile) {
  for (int i = 0; i < c->arraySize; i++) {
    fprintf(outFile, "%s: %d\n", c->countArray[i].string, c->countArray[i].count);
  }

  if (c->count_of_unknowns > 0) {
    fprintf(outFile, "%s: %d\n", "<unknown> ", c->count_of_unknowns);
  }

  if(fclose(outFile) != 0) {
    fprintf(stderr, "oh no, couldn't close the file!\n");
  }
}

void freeCounts(counts_t * c) {
  for (int i = 0; i < c->arraySize; i++) {
    free(c->countArray[i].string);
  }
  free(c->countArray);
  free(c);
}
