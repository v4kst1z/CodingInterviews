/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-21 11:48:12
 * @LastEditors: V4kst1z
 * @Description: JZ13 调整数组顺序使奇数位于偶数前面
 * @FilePath: /CodingInterviews/JZ13.cpp
 */

#include <iostream>
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
  vector<int> reOrderArray(vector<int> &array) {
    size_t len = array.size();
    if (len == 0)
      return {};
    size_t oddIdx = 0;
    size_t idx = 0;
    while (idx < len) {
      if (array[idx] % 2) {
        int tmp = array[idx];
        int jdx = idx;
        while (jdx > oddIdx) {
          array[jdx] = array[jdx - 1];
          jdx--;
        }
        array[oddIdx++] = tmp;
      }
      idx++;
    }
    return array;
  }
};

int main() {
  Solution sou;
  vector<int> tmp{1, 2, 3, 4};
  auto res = sou.reOrderArray(tmp);
  for (auto elem : res)
    cout << elem << " ";
  return 0;
}