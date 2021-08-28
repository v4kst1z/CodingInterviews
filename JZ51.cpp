/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-27 12:13:33
 * @LastEditors: V4kst1z
 * @Description: JZ51 构建乘积数组
 * @FilePath: /CodingInterviews/JZ51.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> multiply(const vector<int> &A) {
    vector<int> res(A.size(), 1);
    for (int idx = 1; idx < A.size(); idx++) {
      res[idx] = res[idx - 1] * A[idx - 1];
    }
    int tmp = 1;
    for (int idx = A.size() - 2; idx >= 0; idx--) {
      tmp = tmp * A[idx + 1];
      res[idx] = res[idx] * tmp;
    }
    return res;
  }
};

int main() {
  Solution sou;
  vector<int> arr = {1, 2, 3, 4, 5};
  auto res = sou.multiply(arr);
  for (auto num : res)
    cout << num << " ";
  return 0;
}