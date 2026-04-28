#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // char map[256] = "";
        unordered_map<char, int> map;
        int right = 0,left = 0;
        int result = 0;
        // int n = s.size();
        for(int right = 0; right<s.size(); right++) {
            map[s[right]]++;
            while(map[s[right]] > 1) {
                map[s[left]]--;
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main() {
    Solution s;
    string str = "qwwlkew";
    int result = s.lengthOfLongestSubstring(str);
    //打印结果
    cout << "The length of the longest substring without repeating characters is: " << result << endl;
    return 0;
}
