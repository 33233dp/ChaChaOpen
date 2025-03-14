#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100

typedef struct {
    char key[50];
    int value;
} KeyValuePair;

int parse_brace_numbers(const char* s, KeyValuePair* result) {
    int count = 0;
    const char* ptr = s;
    while (*ptr) {
        // 查找引号内的键
        if (*ptr == '"') {
            ptr++;
            char key[50];
            int i = 0;
            while (*ptr && *ptr != '"' && i < 49) {
                key[i++] = *ptr++;
            }
            key[i] = '\0';
            ptr++;  // 跳过右引号

            // 跳过冒号及空格
            while (*ptr && (*ptr == ':' || isspace((unsigned char)*ptr))) {
                ptr++;
            }

            // 读取数值
            int value = atoi(ptr);

            // 存入结构体数组
            strcpy_s(result[count].key, sizeof(result[count].key), key);
            result[count].value = value;
            count++;

            // 跳过数值部分
            while (*ptr && (isdigit((unsigned char)*ptr) || *ptr == '-')) {
                ptr++;
            }
        }
        else {
            ptr++;
        }
    }
    return count;
}

int main() {
    const char* s = "{\"Kp\":22,\"Ki\":3,\"Kd\":87}\n"; //要解析的数据包
    KeyValuePair result[MAX_ENTRIES];   //用于存储数据
    int count = parse_brace_numbers(s, result); //将字符串s的内容解析出并存储在结构体result中

    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", result[i].key, result[i].value);    //打印出结构体内的信息
    }
    return 0;
}