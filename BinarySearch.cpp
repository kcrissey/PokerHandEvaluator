#include <iostream>
#include <string.h>
using namespace std;

#include "BinarySearch.h"

int BinarySearch (long Array[], long NumToSearch, long NumElements)
  {
  long First;
  long Middle;
  long Last;

  First = 0;
  Last  = NumElements - 1;
	
  do {
    Middle = (First + Last) / 2;
    if (NumToSearch == Array[Middle])
      return Middle;
    else
      if (NumToSearch < Array[Middle])
        Last = Middle - 1;
      else
        First = Middle + 1;
  } while (First <= Last);
  
  return -1;
}
