/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-21 11:24:58
 * @LastEditors: V4kst1z
 * @Description: JZ11 二进制中1的个数
 * @FilePath: /CodingInterviews/JZ11.cpp
 */

// 描述
// 输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。

// 示例1
// 输入： 10
// 返回值： 2

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int NumberOf1(int n) {
    int res = 0, idx = 1;
    while (n != 0 && idx++ <= 32) {
      if (n & 1)
        ++res;
      n >>= 1;
    }
    return res;
  }
};

int main() {
  Solution sou;
  cout << sou.NumberOf1(10) << endl;
  return 0;
}