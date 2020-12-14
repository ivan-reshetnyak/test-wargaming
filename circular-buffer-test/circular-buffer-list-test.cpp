#include <cstdlib>

#include <array>

#include <CppUnitTest.h>

#include "circular-buffer-list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace circularbuffertest
{

TEST_CLASS(circularBufferListTest) {
public:
  TEST_METHOD(testConstructor) {
    try {
      circular_buffer_list<int> buf(5);
    } catch (std::exception) {
      // Something went terribly wrong if we're here
      Assert::Fail();
    }
  }

  TEST_METHOD(testSingleWR) {
    circular_buffer_list<int> buf(5);
    int toWrite = rand();
    buf.write(toWrite);
    Assert::AreEqual(toWrite, buf.read());
  }

  TEST_METHOD(testFullSizeWR) {
    circular_buffer_list<int> buf(5);
    std::array<int, 5> strip;
    for (int &it : strip)
      it = rand();
    for (const int &it : strip)
      buf.write(it);
    for (const int &it : strip)
      Assert::AreEqual(it, buf.read());
  }

  TEST_METHOD(testLoopWR) {
    circular_buffer_list<int> buf(5);
    std::array<int, 10> strip;
    for (int &it : strip)
      it = rand();
    for (const int &it : strip)
      buf.write(it);
    for (int i = 5; i < 10; ++i)
      Assert::AreEqual(strip[i], buf.read());
  }
};

}
