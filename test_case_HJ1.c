#include "test_case_HJ1.h"
#include <string.h>
#include <stdio.h>

// ### HJ1 字符串最后一个单词的长度  
// 描述
// 计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。（注：字符串末尾不以空格为结尾）
// 输入描述：
// 输入一行，代表要计算的字符串，非空，长度小于5000。

// 输出描述：
// 输出一个整数，表示输入字符串最后一个单词的长度。

// 示例1
// 输入：
// hello nowcoder
// 输出：
// 8
// 说明：
// 最后一个单词为nowcoder，长度为8 

void test_case_HJ1()
{
    printf("test_case_HJ1 start...\n");
    printf("input string:");
    char str[5000];
    gets(str);
    printf("%s %d\n", str, strlen(str));
    int last_index = strlen(str) - 1;
    int length = 0;
    int has_empty = 0;
    printf("last_index:%d\n", last_index);
    for (int i = last_index; last_index >= 0; --last_index) {
        if (*(str + last_index) != ' ') {
            has_empty = 1;
            ++length;
        } else {
            break;
        }
    }
    printf("%d", has_empty != 0 ? length : strlen(str));
} 