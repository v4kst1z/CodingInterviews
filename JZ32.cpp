/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-25 11:51:22
 * @LastEditors: V4kst1z
 * @Description: JZ32 把数组排成最小的数
 * @FilePath: /CodingInterviews/JZ32.cpp
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// private:
//   void helper(size_t pos, vector<int> &num, string &ret) {
//     if (pos + 1 == num.size()) {
//       string tmp = "";
//       for (auto elem : num) {
//         tmp += to_string(elem);
//       }
//       ret = min(ret, tmp);
//     }
//     for (size_t id = pos; id < num.size(); id++) {
//       swap(num[pos], num[id]);
//       helper(pos + 1, num, ret);
//       swap(num[pos], num[id]);
//     }
//   }

// public:
//   string PrintMinNumber(vector<int> numbers) {
//     string ret(numbers.size(), '9');
//     helper(0, numbers, ret);
//     return ret;
//   }
// };

class Solution {
public:
  string PrintMinNumber(vector<int> numbers) {
    vector<string> strs;
    for (auto elem : numbers)
      strs.push_back(to_string(elem));
    sort(strs.begin(), strs.end(),
         [](string &a, string &b) { return a + b < b + a; });
    string ret;
    for (auto &str : strs)
      ret += str;
    return ret;
  }
};

int main() {
  Solution sou;
  vector<int> arr{3, 32, 321};
  cout << sou.PrintMinNumber(arr) << endl;
  return 0;
}