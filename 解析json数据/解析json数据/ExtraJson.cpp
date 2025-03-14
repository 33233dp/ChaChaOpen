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
        // ���������ڵļ�
        if (*ptr == '"') {
            ptr++;
            char key[50];
            int i = 0;
            while (*ptr && *ptr != '"' && i < 49) {
                key[i++] = *ptr++;
            }
            key[i] = '\0';
            ptr++;  // ����������

            // ����ð�ż��ո�
            while (*ptr && (*ptr == ':' || isspace((unsigned char)*ptr))) {
                ptr++;
            }

            // ��ȡ��ֵ
            int value = atoi(ptr);

            // ����ṹ������
            strcpy_s(result[count].key, sizeof(result[count].key), key);
            result[count].value = value;
            count++;

            // ������ֵ����
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
    const char* s = "{\"Kp\":22,\"Ki\":3,\"Kd\":87}\n"; //Ҫ���������ݰ�
    KeyValuePair result[MAX_ENTRIES];   //���ڴ洢����
    int count = parse_brace_numbers(s, result); //���ַ���s�����ݽ��������洢�ڽṹ��result��

    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", result[i].key, result[i].value);    //��ӡ���ṹ���ڵ���Ϣ
    }
    return 0;
}