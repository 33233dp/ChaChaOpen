#include <iostream>
#include <vector>

class solution {
    public:
        void select_sort(std::vector<int>& nums) {
		int n = nums.size();
		int foot = 0;//最大值的下标
		for(int i = n, k = 0; i > 0; i--,k++) {
			//找到每一轮中的最大值
            //重置最大值的下标为当前轮的起始位置
            //如果不重置，foot的值会一直是上一次循环中找到的最大值的下标,
            //这样就找不到剩余元素中的最大值，导致错误的结果
            foot = k;
			for(int j = k; j < n; j++) {
				if(nums[foot] < nums[j]) {
					foot = j;
				}
			}//循环结束退出之后得到最大值
			//最大值放在最前面(交换)
			int t = nums[foot];
			nums[foot] = nums[k];
			nums[k] = t;
		}         
    }
};

int main() {
    int nums[] = {64, 25, 12, 22, 11};
    int n = sizeof(nums) / sizeof(nums[0]);
    //选择排序
    solution s;
    std::vector<int> numss(nums, nums + n);
    s.select_sort(numss);
    for(int i = 0; i < n; i++) {
        std::cout << numss[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
