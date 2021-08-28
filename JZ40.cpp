/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-26 14:10:50
 * @LastEditors: V4kst1z
 * @Description: JZ40 数组中只出现一次的两个数字
 * @FilePath: /CodingInterviews/JZ40.cpp
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param array int整型vector
   * @return int整型vector
   */
  //   vector<int> FindNumsAppearOnce(vector<int> &array) {
  //     map<int, int> numMp;
  //     for (auto num : array) {
  //       if (numMp[num] != 0)
  //         numMp.erase(num);
  //       else
  //         numMp[num]++;
  //     }
  //     vector<int> res;
  //     for (auto &elem : numMp)
  //       res.push_back(elem.first);
  //     return res;
  //   }
  vector<int> FindNumsAppearOnce(vector<int> array) {
    int tmp = 0;
    for (auto num : array)
      tmp ^= num;
    int mask = 1;
    while ((tmp & mask) == 0) {
      mask <<= 1;
    }
    int a = 0, b = 0;
    for (auto num : array) {
      if ((num & mask) == 0)
        a ^= num;
      else
        b ^= num;
    }
    if (a > b)
      swap(a, b);
    return {a, b};
  }
};

int main() {
  Solution sou;
  auto arr = sou.FindNumsAppearOnce({2, 4, 3, 6, 3, 2, 5, 5});
  for (auto num : arr)
    cout << num << " ";
  return 0;
}