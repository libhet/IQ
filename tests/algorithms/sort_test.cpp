
#include "gmock/gmock.h"

#include <sstream>
#include <list>

#include "../../src/algorithms/sort.h"

using namespace testing;

TEST(CountingListSize, Size) {
    List list_of_ints;
    list_of_ints.append(2);
    list_of_ints.append(4);

    Iterate(list_of_ints.top, [](int a){std::cout << a << std::endl;});
}