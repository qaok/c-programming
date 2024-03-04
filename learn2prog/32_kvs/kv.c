#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

char *splitLine2KV(char *line, const char *delim) {
  char *v = strstr(line, delim);

  if (v == NULL)
    return NULL;

  *v = '\0';

  v = v + strlen(delim);
  strtok(v, "\n");

  char *ans = malloc((strlen(v) + 1) * sizeof(*ans));
  strcpy(ans, v);
  // return v + strlen(delim);
  return ans;
}

kvarray_t * readKVs(const char * fname) {
  FILE *f = fopen(fname, "r");
  if (f == NULL) {
    fprintf(stderr, "Could not open file\n");
    return NULL;
  }

  kvarray_t *kvArray = malloc(sizeof(*kvArray));
  kvArray->kvarray = NULL;
  kvArray->kvarrayLength = 0;
  char *line = NULL;
  size_t sz = 0;
  int i = 0;
  char *v = NULL;

  while (getline(&line, &sz, f) >= 0) {
    v = splitLine2KV(line, "=");
    if (v) {
      kvpair_t *kvPair = malloc(sizeof(*kvPair));
      kvPair->key = malloc((strlen(line) + 1) * sizeof(kvPair->key));
      kvPair->value = malloc((strlen(v) + 1) * sizeof(kvPair->value));
      strcpy(kvPair->key, line);
      strcpy(kvPair->value, v);
      kvArray->kvarray = realloc(kvArray->kvarray, (i + 1) * sizeof(kvpair_t));
      kvArray->kvarray[i] = *kvPair;
      i++;
      kvArray->kvarrayLength = i;
      free(kvPair);
    }
    free(v);
  }
  free(line);

  if (fclose(f) != 0) {
    fprintf(stderr, "Could not close file\n");
    return NULL;
  }

  return kvArray;
}

void freeKVs(kvarray_t * pairs) {
  for (int i = 0; i < pairs->kvarrayLength; i++) {
    free(pairs->kvarray[i].key);
    free(pairs->kvarray[i].value);
  }
  free(pairs->kvarray);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  for (int i = 0; i < pairs->kvarrayLength; i++) {
    printf("key = '%s' value = '%s'\n", pairs->kvarray[i].key,
           pairs->kvarray[i].value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  for (int i = 0; i < pairs->kvarrayLength; i++) {
    if (strcmp(pairs->kvarray[i].key, key) == 0) {
      return pairs->kvarray[i].value;
    }
  }
  return NULL;
}
