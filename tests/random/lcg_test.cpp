
#include "gmock/gmock.h"

#include <sstream>
#include <list>

#include "../../src/random/lcg.h"

using namespace testing;


TEST(ALinearCongruentialGenerator, GeneratesPseudoRandomSequence) {
    
    lcg generator = lcg(7, 5, 11);
    generator.set_seed(0);

    std::list<int> generated;

    for(size_t i = 0u; i < 11u; ++i) {
        generated.push_back(generator.get());
    }

//  X 0 = 0
//  X 1 = (7 u 0 + 5) mod 11 = 5
//  X 2 = (7 u 5 + 5) mod 11 = 40 mod 11 = 7
//  X 3 = (7 u 7 + 5) mod 11 = 54 mod 11 = 10
//  X 4 = (7 u 10 + 5) mod 11 = 75 mod 11 = 9
//  X 5 = (7 u 9 + 5) mod 11 = 68 mod 11 = 2
//  X 6 = (7 u 2 + 5) mod 11 = 19 mod 11 = 8
//  X 7 = (7 u 8 + 5) mod 11 = 61 mod 11 = 6
//  X 8 = (7 u 6 + 5) mod 11 = 47 mod 11 = 3
//  X 9 = (7 u 3 + 5) mod 11 = 26 mod 11 = 4
//  X 10 = (7 u 4 + 5) mod 11 = 33 mod 11 = 0

    std::list<int> expected = {0,5,7,10,9,2,8,6,3,4,0};

    ASSERT_THAT(generated, expected);
}