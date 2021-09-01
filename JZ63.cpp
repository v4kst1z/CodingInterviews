/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-29 19:27:22
 * @LastEditors: V4kst1z
 * @Description:
 * @FilePath: /CodingInterviews/JZ63.cpp
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// class Solution {
// private:
//   vector<int> val;

// public:
//   void Insert(int num) {
//     if (val.empty())
//       val.push_back(num);
//     else {
//       auto it = lower_bound(val.begin(), val.end(), num);
//       val.insert(it, num);
//     }
//   }

//   double GetMedian() {
//     int len = val.size();
//     if (len & 1) {
//       return static_cast<double>(val[len >> 1]);
//     } else {
//       return static_cast<double>((val[len >> 1] + val[(len - 1) >> 1])
//       / 2.0);
//     }
//   }
// };

class Solution {
private:
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

public:
  void Insert(int num) {
    maxHeap.push(num);
    minHeap.push(maxHeap.top());
    maxHeap.pop();
    if (maxHeap.size() < minHeap.size()) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  double GetMedian() {
    if (maxHeap.size() == minHeap.size()) {
      return static_cast<double>((maxHeap.top() + minHeap.top()) / 2.0);
    } else {
      return static_cast<double>(maxHeap.top());
    }
  }
};

int main() { return 0; }