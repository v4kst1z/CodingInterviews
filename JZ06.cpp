/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-20 19:49:15
 * @LastEditors: V4kst1z
 * @Description: JZ6 旋转数组的最小数字
 * @FilePath: /CodingInterviews/JZ06.cpp
 */

// 描述
// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
// NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

// 示例1
// 输入：
// [3,4,5,1,2]
// 返回值： 1

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minNumberInRotateArray(vector<int> &rotateArray) {
    if (rotateArray.empty())
      return 0;
    int left = 0, right = rotateArray.size() - 1;
    if (rotateArray[0] < rotateArray[right])
      return rotateArray[0];

    while (left < right) {
      int mid = (left + right) / 2;
      if (rotateArray[mid] > rotateArray[right])
        left = mid + 1;
      else if (rotateArray[mid] < rotateArray[right]) {
        if (rotateArray[mid] < rotateArray[mid - 1])
          return rotateArray[mid];
        else
          right = mid - 1;
      } else {
        vector<int> subvector1 = {rotateArray.begin() + left,
                                  rotateArray.begin() + mid};
        vector<int> subvector2 = {rotateArray.begin() + mid,
                                  rotateArray.begin() + right};

        int res = INT32_MAX;
        if (!subvector1.empty())
          res = min(minNumberInRotateArray(subvector1), res);
        if (!subvector2.empty())
          res = min(minNumberInRotateArray(subvector2), res);
        return res;
      }
    }
    return rotateArray[left];
  }
};

int main() {
  Solution sou;
  vector<int> tmp = {1, 0, 1, 1, 1};
  cout << sou.minNumberInRotateArray(tmp) << endl;
}