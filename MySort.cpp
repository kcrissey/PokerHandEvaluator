#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "MySort.h"

using namespace std;

void Sort (char *Array[], long NumElements) {

  bool Sorted;
  char c;
  char *ptr;
  long Found;

    do {
      NumElements--;
      Sorted = true;
      for (long i = 0; i < NumElements; i++) {
          if ((strcasecmp(Array[i], Array[i + 1])) > 0) {
            ptr = Array[i];
            Array[i] = Array[i + 1];
            Array[i + 1] = ptr;
            Sorted = false;
            }
          else;
        }
      } while (!Sorted);
}
