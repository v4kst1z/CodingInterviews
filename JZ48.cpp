/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-27 11:41:20
 * @LastEditors: V4kst1z
 * @Description: JZ48 不用加减乘除做加法
 * @FilePath: /CodingInterviews/JZ48.cpp
 */

#include <iostream>

using namespace std;

class Solution {
public:
  int Add(int num1, int num2) {
    while (num2 != 0) {
      int c = ((unsigned int)(num1 & num2)) << 1;
      num1 ^= num2;
      num2 = c;
    }
    return num1;
  }
};

int main() {
  Solution sou;
  cout << sou.Add(1, 2) << endl;
}