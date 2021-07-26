// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#endif

#include <iostream>
#include <stdlib.h>

// #include "exampleConfig.h"
#include "algorithms/quick_find.h"

int main() {
  // UnionFind *union_find = new QuickFind();

  // union_find->join(1, 2);

  // delete union_find;

  return 0;
}
