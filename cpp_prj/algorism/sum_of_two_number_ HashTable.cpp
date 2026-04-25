//两数之和
#include <iostream>
#include <vector>
class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
        //利用哈希表
	}
};

int main()
{
	int n;
	std::cout << "input n:";
	std::cin >> n;

	std::vector<int> nums;
	nums.reserve(n);//预留动态数组的空间
	
	std::cout << "input" << n << "int numbers" << std::endl;
	for(int i = 0; i < n; i++){
		int temp;
		std::cin >> temp;
		nums.push_back(temp);//在动态数组尾部赋值temp
	}
	
	std::cout << "intput target number" << std::endl;
	int target;
	std::cin >> target;
	
	Solution sl;
	//std::vector<int> result = Solution::twoSum(nums,target);是错误的，还没有实例化对象！
	std::vector<int> result = sl.twoSum(nums,target);
	std::cout << "result:";
	if (result[0] == -1) {
    	std::cout << "No solution found!" << std::endl;
	} 
	else {
		for (int i = 0; i < result.size(); i++) {
			int index = result[i];
			std::cout << "Index: " << index << ", Value: " << nums[index] << std::endl;
		}
	}
	return 0;
}

