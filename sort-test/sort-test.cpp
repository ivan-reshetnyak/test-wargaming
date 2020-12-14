#include <cstdlib>

#include <CppUnitTest.h>

#include "sort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace sorttest
{

static const int GremlinTestSize = 10000;

static bool isSorted( int *left, int *right ) {
  while (left < right) {
    if (*left > *(left + 1))
      return false;
    left++;
  }
  return true;
}

TEST_CLASS(sortTest) {
public:
  TEST_METHOD(sorted5) {
    int buf[] = { 1, 2, 3, 4, 5 };
    quickSort(buf, buf + 4);
    Assert::IsTrue(isSorted(buf, buf + 4));
  }

  TEST_METHOD(gremlinTest) {
    int buf[GremlinTestSize];
    for (int i = 0; i < GremlinTestSize; ++i)
      buf[i] = rand();
    quickSort(buf, buf + GremlinTestSize - 1);
    Assert::IsTrue(isSorted(buf, buf + GremlinTestSize - 1));
  }
};

}
