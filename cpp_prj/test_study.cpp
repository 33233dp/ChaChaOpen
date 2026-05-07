#include <cassert>
#include <iostream>
#include <vector>

#include "study.cpp"

static void expectTwoSum(std::vector<int> nums, int target, std::vector<int> expected)
{
    Solution solution;
    std::vector<int> actual = solution.twoSum(nums, target);
    assert(actual == expected);
}

int main()
{
    expectTwoSum({2, 7, 11, 15}, 9, {0, 1});
    expectTwoSum({3, 2, 4}, 6, {1, 2});
    expectTwoSum({3, 3}, 6, {0, 1});
    expectTwoSum({-1, -2, -3, -4, -5}, -8, {2, 4});
    expectTwoSum({0, 4, 3, 0}, 0, {0, 3});
    expectTwoSum({1, 2, 3}, 7, {});

    std::cout << "All study.cpp tests passed.\n";
    return 0;
}
