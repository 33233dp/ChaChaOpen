#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	unordered_map<char, int> hashTable;
	int s_maxLenth = 0;
	int t_lenth = 0;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		if(hashTable.find(s[i]) == hashTable.end()) {
			hashTable.emplace(s[i], i);
			t_lenth++;
		} else {
			s_maxLenth = s_maxLenth > t_lenth ? s_maxLenth : t_lenth;

			i = hashTable[s[i]];
			t_lenth = 0;		
			hashTable = unordered_map<char, int>();
		}
	}
	return max(s_maxLenth, t_lenth);
    }
};

int main() {
	Solution sol;
	char s[100] = " hb *cadb";
	int m = sol.lengthOfLongestSubstring(string(s));
	std::cout << m << std::endl;
	return 0;
}
