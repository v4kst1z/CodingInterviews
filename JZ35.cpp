/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-25 15:13:01
 * @LastEditors: V4kst1z
 * @Description: JZ35 数组中的逆序对
 * @FilePath: /CodingInterviews/JZ35.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int InversePairs(vector<int> data) {
    int res = 0;
    for (size_t idx = data.size() - 1; idx > 0; idx--) {
      for (int jdx = idx - 1; jdx >= 0; jdx--) {
        if (data[idx] < data[jdx])
          res++;
      }
      res %= 1000000007;
    }
    return res;
  }
};

int main() {
  Solution sou;
  cout << sou.InversePairs({1, 2, 3, 4, 5, 6, 7, 0}) << endl;
  return 0;
}