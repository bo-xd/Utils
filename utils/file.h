#ifndef FILE_HELPER_H
#define FILE_HELPER_H

#include <stdio.h>
#include <stdlib.h>

#define NITEMS(arr) (sizeof(arr) / sizeof((arr)[0]))

static size_t ReadAFile(const char* path, const char* readmode) {
  FILE file = fopen(path, readmode);

  if (!file) {
    fprintf(stderr, "Couldnt open file");
    return -1;
  }
}

#endif
