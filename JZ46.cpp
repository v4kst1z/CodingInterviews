/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-27 10:54:23
 * @LastEditors: V4kst1z
 * @Description: JZ46 孩子们的游戏(圆圈中最后剩下的数)
 * @FilePath: /CodingInterviews/JZ46.cpp
 */

#include <iostream>
#include <list>

using namespace std;

// 1 2 3 4 5
// 0 1 2 0 1
// 2 0   1 2
//   0   1
//   2   0
class Solution {
public:
  int LastRemaining_Solution(int n, int m) {
    if (n <= 0)
      return -1;
    list<int> l;
    for (int idx = 0; idx < n; idx++)
      l.push_back(idx);

    int index = 0;
    while (n > 1) {
      index = (index + m - 1) % n;
      auto it = l.begin();
      std::advance(it, index);
      l.erase(it);
      n--;
    }
    return l.back();
  }
};

int main() {
  Solution sou;
  cout << sou.LastRemaining_Solution(5, 3) << endl;
  return 0;
}