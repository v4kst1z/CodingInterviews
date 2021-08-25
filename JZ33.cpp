/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-25 14:34:51
 * @LastEditors: V4kst1z
 * @Description: JZ33 丑数
 * @FilePath: /CodingInterviews/JZ33.cpp
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int GetUglyNumber_Solution(int index) {
    if (index < 6)
      return index;
    vector<int> ret(index, 0);
    ret[0] = 1;
    size_t idx2 = 0, idx3 = 0, idx5 = 0;
    for (size_t idx = 1; idx < index; idx++) {
      ret[idx] = min(ret[idx2] * 2, min(ret[idx3] * 3, ret[idx5] * 5));
      if (ret[idx] == ret[idx2] * 2)
        idx2++;
      if (ret[idx] == ret[idx3] * 3)
        idx3++;
      if (ret[idx] == ret[idx5] * 5)
        idx5++;
    }
    return ret[index - 1];
  }
};

int main() {
  Solution sou;
  cout << sou.GetUglyNumber_Solution(7) << endl;
  return 0;
}