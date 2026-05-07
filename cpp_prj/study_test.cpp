#include <cassert>
#include <vector>

#include "study.cpp"

static void assertVectorEqual(const std::vector<int>& actual, const std::vector<int>& expected)
{
    assert(actual == expected);
}

int main()
{
    Solution solution;

    std::vector<int> nums1{2, 7, 11, 15};
    assertVectorEqual(solution.twoSum(nums1, 9), {0, 1});

    std::vector<int> nums2{3, 2, 4};
    assertVectorEqual(solution.twoSum(nums2, 6), {1, 2});

    std::vector<int> nums3{3, 3};
    assertVectorEqual(solution.twoSum(nums3, 6), {0, 1});

    std::vector<int> nums4{-1, -2, -3, -4, -5};
    assertVectorEqual(solution.twoSum(nums4, -8), {2, 4});

    std::vector<int> nums5{1, 2, 3};
    assertVectorEqual(solution.twoSum(nums5, 100), {});

    return 0;
}
