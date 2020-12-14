#include <cstdlib>

#include <CppUnitTest.h>

#include "even.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace eventest
{

static const int GremlinTestSize = 10000;

TEST_CLASS(evenTest) {
public:
  TEST_METHOD(test1to1000) {
    for (int i = 1; i <= 1000; ++i)
      Assert::AreEqual(isEven1(i), isEven2(i));
  }

  TEST_METHOD(testMinus1000to0) {
    for (int i = -1000; i <= 0; ++i)
      Assert::AreEqual(isEven1(i), isEven2(i));
  }

  TEST_METHOD(gremlinTest) {
    for (int i = 0; i < GremlinTestSize; ++i) {
      int num = rand();
      Assert::AreEqual(isEven1(num), isEven2(num));
    }
  }
};

}
