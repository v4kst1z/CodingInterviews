/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-27 11:38:30
 * @LastEditors: V4kst1z
 * @Description: JZ47 求1+2+3+...+n
 * @FilePath: /CodingInterviews/JZ47.cpp
 */

#include <iostream>
using namespace std;

class Solution {
public:
  int Sum_Solution(int n) { return (n * (n + 1)) / 2; }
};

int main() {
  Solution sou;
  cout << sou.Sum_Solution(5) << endl;
  return 0;
}