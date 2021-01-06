#include <iostream>
#include <string>
#include <cassert>

#include "IndexFreeList.hpp"

using namespace std;

int main()
{
    IndexFreeList<int> test;
    int ind0 = test.Insert(2);
    int ind1 = test.Insert(3);
    int ind2 = test.Insert(4);
    test.Remove(ind0);
    int ind3 = test.Insert(12);
    int ind4 = test.Insert(11);
    int ind5 = test.Insert(6);
    test.Remove(ind4);
    test.Insert(8);
    test.Remove(ind2);
    test.Remove(ind5);

    assert(test[ind0] != 2);
    std::cout << "1st test succeeded" << std::endl;
    assert(ind0 == ind3);
    std::cout << "2nd test succeeded" << std::endl;
    assert(test[ind4] != 11);
    std::cout << "3rd test succeeded" << std::endl;
}