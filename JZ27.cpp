/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-22 13:25:58
 * @LastEditors: V4kst1z
 * @Description: JZ27 字符串的排列
 * @FilePath: /CodingInterviews/JZ27.cpp
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
private:
  set<string> result;
  vector<bool> used;
  void helper(string &str, string &can) {
    if (can.size() == str.size()) {
      result.insert(can);
    }
    for (size_t id = 0; id < str.size(); id++) {
      if (used[id])
        continue;

      used[id] = true;
      can.push_back(str[id]);
      helper(str, can);
      used[id] = false;
      can.pop_back();
    }
  }

public:
  vector<string> Permutation(string str) {
    vector<string> res;
    int len = str.size();
    if (len == 0 || len == 1)
      return {str};
    string candidates;
    used.resize(str.size(), false);
    sort(str.begin(), str.end());
    helper(str, candidates);
    return vector<string>(result.begin(), result.end());
  }
};

int main() {
  string tmp = "abc";
  Solution sou;
  auto res = sou.Permutation(tmp);
  for (auto &s : res) {
    cout << s << endl;
  }
  return 0;
}