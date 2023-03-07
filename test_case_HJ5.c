#include "test_case_HJ5.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

// HJ5 进制转换

// 描述
// 写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。

// 输入描述：
// 输入一个十六进制的数值字符串。

// 输出描述：
// 输出该数值的十进制字符串。不同组的测试用例用\n隔开。

// 示例1
// 输入：
// 0xAA
// 复制
// 输出：
// 170

int convert_hex_to_dec_by_ch(char ch)
{
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    } else if (ch == 'A' || ch == 'a') {
        return 10;
    } else if (ch == 'B' || ch == 'b') {
        return 11;
    } else if (ch == 'C' || ch == 'c') {
        return 12;
    } else if (ch == 'D' || ch == 'd') {
        return 13;
    } else if (ch == 'E' || ch == 'e') {
        return 14;
    } else if (ch == 'F' || ch == 'f') {
        return 15;
    } else {
        return 0;
    }
}

double convert_hex_to_dec(char* hex_str)
{   
    if (hex_str == NULL) {
        return 0;
    }
    int len = strlen(hex_str);
    int sep = 0;
    double dec = 0; 
    for (int i = len - 1; i >= 2; --i) {
        char hex_ch = hex_str[i];
        double dec_ch = convert_hex_to_dec_by_ch(hex_ch);
        dec += dec_ch * pow(16, sep);
        sep++;
    }
    return dec;    
}

void test_case_HJ5()
{
    char hex_str[1000];
    gets(hex_str);
    double dec = convert_hex_to_dec(hex_str);
    printf("%d\n", (int)dec);
}
