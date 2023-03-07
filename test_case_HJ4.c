#include "test_case_HJ4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// HJ4 字符串分隔

// 描述
// •输入一个字符串，请按长度为8拆分每个输入字符串并进行输出；

// •长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
// 输入描述：
// 连续输入字符串(每个字符串长度小于等于100)

// 输出描述：
// 依次输出所有分割后的长度为8的新字符串

// 示例1
// 输入：
// abc
// 输出：
// abc00000

#define SEPARATE_NUM 8
#define SINGLE_LENGTH (SEPARATE_NUM + 1)


void separate_string(char* str)
{
    if (str == NULL) {
        return;
    }

    int len = strlen(str);
    if (len == 0) {
        return;
    }

    int count = len / SEPARATE_NUM;
    int remain = len % SEPARATE_NUM;
    char single_str[SINGLE_LENGTH] = {0};
    int pos = 0;
    for (int i = 0; i < count; ++i) {
        memset(single_str, 0, SINGLE_LENGTH);
        memcpy(single_str, str + pos, SEPARATE_NUM);
        pos += SEPARATE_NUM;
        printf("%s\n", single_str);
    }
    if (remain == 0) {
        return;
    }
    memset(single_str, 0, SINGLE_LENGTH);
    for (int j = 0; j < SEPARATE_NUM; ++j) {
        if (j < remain) {
            single_str[j] = str[pos + j];
        } else {
            single_str[j] = '0';
        }
    }
    printf("%s\n", single_str);
}

void test_case_HJ4()
{
    char str[100];
    gets(str);
    separate_string(str);
}