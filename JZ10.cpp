/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-21 10:54:20
 * @LastEditors: V4kst1z
 * @Description: JZ10 矩形覆盖
 * @FilePath: /CodingInterviews/JZ10.cpp
 */

// 描述
// 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩
// 形无重叠地覆盖一个2*n的大矩形，从同一个方向看总共有多少种不同的方法？

// 比如n=3时，2*3的矩形块有3种不同的覆盖方法(从同一个方向看)：

// 输入描述：
// 2*1的小矩形的总个数n
// 返回值描述：
// 覆盖一个2*n的大矩形总共有多少种不同的方法(从同一个方向看)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int rectCover(int number) {
    if (number >= 0 && number <= 3)
      return number;
    int pre1 = 2;
    int pre2 = 3;
    int res = 0;
    for (int id = 4; id <= number; id++) {
      res = pre1 + pre2;
      pre1 = pre2;
      pre2 = res;
    }
    return res;
  }
};

int main() {
  Solution sou;
  cout << sou.rectCover(4) << endl;
  return 0;
}