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

// class Solution {
// public:
//   int InversePairs(vector<int> data) {
//     int res = 0;
//     for (size_t idx = data.size() - 1; idx > 0; idx--) {
//       for (int jdx = idx - 1; jdx >= 0; jdx--) {
//         if (data[idx] < data[jdx])
//           res++;
//       }
//       res %= 1000000007;
//     }
//     return res;
//   }
// };

class Solution {
private:
  const int kmod = 1000000007;

  void mergeSort(vector<int> &arr, vector<int> &tmp, int l, int r, int &ret) {
    if (l >= r)
      return;
    int mid = (l + r) / 2;
    mergeSort(arr, tmp, l, mid, ret);
    mergeSort(arr, tmp, mid + 1, r, ret);
    merge(arr, tmp, l, mid, r, ret);
    ret %= kmod;
  }

  void merge(vector<int> &arr, vector<int> &tmp, int l, int mid, int r,
             int &ret) {
    int id = l, jd = mid + 1;
    int tmpId = l;
    while (id <= mid && jd <= r) {
      if (arr[id] < arr[jd])
        tmp[tmpId++] = arr[id++];
      else {
        tmp[tmpId++] = arr[jd++];
        ret += (mid - id + 1);
      }
    }

    while (id <= mid) {
      tmp[tmpId++] = arr[id++];
    }

    while (jd <= r) {
      tmp[tmpId++] = arr[jd++];
    }
    for (id = l; id <= r; id++)
      arr[id] = tmp[id];
  }

public:
  int InversePairs(vector<int> data) {
    int ret = 0;
    vector<int> tmp(data.size());
    mergeSort(data, tmp, 0, data.size() - 1, ret);
    return ret;
  }
};

int main() {
  Solution sou;
  cout << sou.InversePairs({1, 2, 3, 4, 5, 6, 7, 0}) << endl;
  return 0;
}