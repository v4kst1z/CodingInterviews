/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-20 20:32:52
 * @LastEditors: V4kst1z
 * @Description: JZ7 斐波那契数列
 * @FilePath: /CodingInterviews/JZ07.cpp
 */

#include <iostream>

using namespace std;

class Solution {
public:
  int Fibonacci(int n) {
    if (n == 0)
      return 0;
    if (n == 1 || n == 2)
      return 1;
    int res = 2;
    int num = 1;
    for (int idx = 4; idx <= n; idx++) {
      int tmp = res;
      res = res + num;
      num = tmp;
    }
    return res;
  }
};

int main() {
  Solution sou;
  cout << sou.Fibonacci(4) << endl;
}