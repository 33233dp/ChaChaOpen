//两数之和
#include <iostream>
#include <vector>
class Solution {
public:
	//vector 动态数组 int 类型
	//动态数组支持扩容
	//`std::vector` 是 C++ 中一种内存连续、支持 $O(1)$ 随机访问且能自动管理扩容与释放的动态数组。
	//定义动态数组需要包含头文件<vector>
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> foot;
		foot.reserve(2);

		int n = nums.size();
		for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
					//foot[0] = i;是错误写法，reverse只是预留了空间，但是数组的长度还是0,应当使用.push_back赋值
                    foot.push_back(i);
                    foot.push_back(j);
                    return foot;
                }
            }
        }
		
		return {-1, -1};
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

