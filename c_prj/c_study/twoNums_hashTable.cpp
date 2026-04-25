#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
	public:
		Solution() {
			std::cout << "ok" << std::endl;			
		}
		vector<int> twoSum(vector<int> & nums,int target) {
			vector<int> ans;
			unordered_map<int, int> hashTable;
			int n = nums.size();
			for(int i = 0; i < n; i++) {
				if(hashTable.find(nums[i]) == hashTable.end()) {
					hashTable.emplace(target - nums[i], i);
				} else {
					ans.push_back(hashTable.at(nums[i]));
					ans.push_back(i);
					return ans;
				}
			}
			return ans;
		}
};

int main()
{
	Solution sol;
	return 0;
}
