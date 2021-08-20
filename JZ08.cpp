/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-20 20:38:29
 * @LastEditors: V4kst1z
 * @Description: JZ8 跳台阶
 * @FilePath: /CodingInterviews/JZ08.cpp
 */

#include <iostream>

using namespace std;

class Solution {
public:
  int jumpFloor(int number) {
    if (number == 1)
      return 1;
    if (number == 2)
      return 2;
    return jumpFloor(number - 1) + jumpFloor(number - 2);
  }
};

int main() {
  Solution sou;
  cout << sou.jumpFloor(7) << endl;
}