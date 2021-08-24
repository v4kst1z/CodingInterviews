/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-21 11:41:27
 * @LastEditors: V4kst1z
 * @Description: JZ12 数值的整数次方
 * @FilePath: /CodingInterviews/JZ12.cpp
 */

// 描述
// 给定一个double类型的浮点数base和int类型的整数exponent。
// 求base的exponent次方。

// 保证base和exponent不同时为0。不得使用库函数，同时不需要
// 考虑大数问题，也不用考虑小数点后面0的位数

// 示例1
// 输入： 2.00000,3
// 返回值： 8.00000

#include <iostream>
using namespace std;

class Solution {
public:
  double Power(double base, int exponent) {
    if (exponent == 0)
      return 1;

    double res = 1;
    int flag = exponent > 0 ? 1 : -1;
    exponent = flag == 1 ? exponent : -exponent;
    for (int idx = 1; idx <= exponent; idx++) {
      res *= base;
    }
    res = flag == 1 ? res : 1.0 / res;
    return res;
  }
};

int main() {
  Solution sou;
  cout << sou.Power(2.0000, -3) << endl;
  return 0;
}
