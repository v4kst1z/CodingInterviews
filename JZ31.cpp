/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-24 16:51:49
 * @LastEditors: V4kst1z
 * @Description: JZ31 整数中1出现的次数（从1到n整数中1出现的次数）
 * @FilePath: /CodingInterviews/JZ31.cpp
 */

#include <iostream>

class Solution {
public:
  int NumberOf1Between1AndN_Solution(int n) {
    if (n < 1)
      return 0;
    int base = 1;
    int round = n;
    int count = 0;
    while (round) {
      int weight = round % 10;
      round /= 10;
      count += round * base;
      if (weight == 1)
        count += (n % base) + 1;
      else if (weight > 1)
        count += base;
      base *= 10;
    }
    return count;
  }
};

int main() { return 0; }