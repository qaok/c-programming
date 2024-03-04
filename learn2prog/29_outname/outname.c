#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  char * outFileName = malloc((strlen(inputName) + 8) * sizeof(*inputName));
  strcpy(outFileName,inputName);
  strcat(outFileName, ".counts");
  return outFileName;
}
