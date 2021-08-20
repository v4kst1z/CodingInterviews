/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-19 20:46:03
 * @LastEditors: V4kst1z
 * @Description: JZ1 二维数组中的查找
 * @FilePath: /CodingInterviews/JZ01.cpp
 */

// 描述
// 在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排
// 序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一
// 个整数，判断数组中是否含有该整数。
// [
//   [1,2,8,9],
//   [2,4,9,12],
//   [4,6,10,13],
//   [6,8,11,15]
// ]
// 给定 target = 7，返回 true。
// 给定 target = 3，返回 false。

// 0 <= array.length <= 500
// 0 <= array[0].length <= 500

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool Find(int target, vector<vector<int>> array) {
    if (array.empty() || array[0].empty())
      return false;
    int idx = array.size() - 1, jdx = 0;
    while (idx >= 0 && jdx < array[0].size()) {
      if (target == array[idx][jdx])
        return true;
      else if (target < array[idx][jdx])
        idx--;
      else
        jdx++;
    }
    return false;
  }
};

// class Solution {
// private:
//   bool binarySearch(vector<int> &arr, int target) {
//     int idx = 0;
//     int end = arr.size() - 1;
//     while (idx <= end) {
//       if (arr[idx] == target)
//         return true;

//       int mid = (idx + end) / 2;
//       if (arr[mid] == target)
//         return true;

//       while (idx <= end && arr[mid] < target) {
//         idx = mid + 1;
//         mid = (idx + end) / 2;
//       }
//       mid = (idx + end) / 2;
//       while (idx <= end && arr[mid] > target) {
//         end = mid - 1;
//         mid = (idx + end) / 2;
//       }
//     }
//     return false;
//   }

// public:
//   bool Find(int target, vector<vector<int>> &array) {
//     if (array.size() == 0 || array[0].size() == 0)
//       return false;

//     for (auto &arr : array) {
//       if (binarySearch(arr, target))
//         return true;
//     }
//     return false;
//   }
// };

// class Solution {
// public:
//   bool Find(int target, vector<vector<int>> array) {
//     if (array.size() == 0 || array[0].size() == 0)
//       return false;

//     for (auto &arr : array) {
//       auto lower = lower_bound(arr.begin(), arr.end(), target);
//       if (*lower == target)
//         return true;
//     }
//     return false;
//   }
// };

int main() {
  Solution sou;
  cout << sou.Find(
              7, {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}})
       << endl;
  cout << sou.Find(
              1, {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}})
       << endl;
  cout << sou.Find(7, {{1, 2, 8, 9}, {4, 7, 10, 13}}) << endl;
  cout << sou.Find(
              5, {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}})
       << endl;
  cout << sou.Find(
              16, {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}})
       << endl;
  return 0;
}
