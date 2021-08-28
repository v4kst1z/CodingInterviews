/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-26 16:05:24
 * @LastEditors: V4kst1z
 * @Description: JZ41 和为S的连续正数序列
 * @FilePath: /CodingInterviews/JZ41.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//   vector<vector<int>> FindContinuousSequence(int sum) {
//     vector<vector<int>> res;
//     for (int idx = 1; idx <= sum / 2; idx++) {
//       for (int jdx = idx + 1; jdx < sum; jdx++) {
//         int tmp = 0;
//         for (int kdx = idx; kdx <= jdx; kdx++) {
//           tmp += kdx;
//         }
//         if (sum == tmp) {
//           vector<int> arr;
//           for (int kdx = idx; kdx <= jdx; kdx++) {
//             arr.push_back(kdx);
//           }
//           res.push_back(arr);
//         }

//         if (tmp > sum)
//           break;
//       }
//     }
//     return res;
//   }
// };

class Solution {
public:
  vector<vector<int>> FindContinuousSequence(int sum) {
    vector<vector<int>> res;
    int s = 1, l = 1, r = 1;
    while (l <= sum / 2) {
      if (s < sum) {
        r++;
        s += r;
        continue;
      }

      if (s > sum) {
        s -= l;
        l++;
        continue;
      }

      if (s == sum) {
        vector<int> tmp;
        for (int id = l; id <= r; id++)
          tmp.push_back(id);
        res.push_back(tmp);
        s -= l;
        l++;
      }
    }
    return res;
  }
};

int main() {
  Solution sou;
  auto res = sou.FindContinuousSequence(9);
  for (auto &arr : res) {
    for (auto num : arr)
      cout << num << " ";
    cout << endl;
  }
  return 0;
}