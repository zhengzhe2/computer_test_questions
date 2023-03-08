#include "test_case_HJ6.h"
#include <math.h>

// HJ6 质数因子

// 描述
// 功能:输入一个正整数，按照从小到大的顺序输出它的所有质因子（重复的也要列举）（如180的质因子为2 2 3 3 5 ）
 
// 1≤n≤2×10 
// 9
//  +14 
// 输入描述：
// 输入一个整数

// 输出描述：
// 按照从小到大的顺序输出它的所有质数的因子，以空格隔开。

// 示例1
// 输入：
// 180
// 输出：
// 2 2 3 3 5

void test_case_HJ6()
{
    long int num;
    scanf("%ld", &num);
    for (int i = 2; i * i <= num; ++i)
        while (num % i == 0) {
            printf("%d ",i);
            num = num / i;
        }
    if(num != 1) {
        printf("%ld ", num);
    }
}