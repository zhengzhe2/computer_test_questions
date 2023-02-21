#include "test_case_HJ1.h"
#include <string.h>
#include <stdio.h>

// HJ2 计算某字符出现次数
// 描述
// 写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字符，然后输出输入字符串中该字符的出现次数。（不区分大小写字母）

// 数据范围： 
// 1
// ≤
// �
// ≤
// 1000
 
// 1≤n≤1000 
// 输入描述：
// 第一行输入一个由字母、数字和空格组成的字符串，第二行输入一个字符（保证该字符不为空格）。

// 输出描述：
// 输出输入字符串中含有该字符的个数。（不区分大小写字母）

// 示例1
// 输入：
// ABCabc
// A
// 复制
// 输出：
// 2

int func(char* str, char ch)
{   
    if (ch == ' ') {
        return 0;
    }
    int result = 0;
    for (int i = 0; i < strlen(str); ++i) {
        if (*(str + i) == ch) {
            ++result;
            continue;    
        }
        if ((*(str + i) >= 'a' && *(str + i) <= 'z')) {
            if ((ch + ('a' - 'A')) == *(str + i)) {
                ++result;
                continue;  
            }
        }
        if ((*(str + i) >= 'A' && *(str + i) <= 'Z')) {
            if ((ch - ('a' - 'A')) == *(str + i)) {
                ++result;
                continue;  
            }
        }
    }

    return result;
}

void test_case_HJ2()
{
    char str[1000];
    gets(str);
    char ch = getchar();
    int result = func(str, ch);
    printf("%d", result);
}
