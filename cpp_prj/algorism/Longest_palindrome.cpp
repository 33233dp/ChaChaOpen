#include <iostream>
#include <vector>

// 返回字符串中最长回文子串的长度
class Solution {
    public:
        int  longestPalindrome(stirng s) {
            int head,tail;
            int n  = s.size();
            for(head = 0; head < n; head++) {
                for(tail = n; tail > head; tail--) {
                    if(s[tail] == s[head]) {
                        //判断是否达到回文条件
                    }
                    //否则继续缩短窗口
                }
            }
        }
};

int main() {
    std::cout<<"hello"<<std::endl;
}