/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-27 14:01:05
 * @LastEditors: V4kst1z
 * @Description: JZ52 正则表达式匹配
 * @FilePath: /CodingInterviews/JZ52.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

// class Solution {
//   bool helper(string &str, string &pattern, size_t idx, size_t jdx) {
//     if (idx == str.size() && jdx == pattern.size())
//       return true;
//     if (idx != str.size() && jdx == pattern.size())
//       return false;
//     if (idx == str.size() && jdx != pattern.size())
//       if (jdx + 1 < pattern.size() && pattern[jdx + 1] == '*')
//         return helper(str, pattern, idx, jdx + 2);
//       else
//         return false;
//     if (jdx + 1 < pattern.size() && pattern[jdx + 1] == '*') {
//       if (str[idx] == pattern[jdx] || pattern[jdx] == '.') {
//         return helper(str, pattern, idx, jdx + 2) ||
//                helper(str, pattern, idx + 1, jdx);
//       } else {
//         return helper(str, pattern, idx, jdx + 2);
//       }
//     } else if (str[idx] == pattern[jdx] || pattern[jdx] == '.') {
//       return helper(str, pattern, idx + 1, jdx + 1);
//     } else {
//       return false;
//     }
//   }

// public:
//   bool match(string str, string pattern) { return helper(str, pattern, 0, 0);
//   }
// };

class Solution {
public:
  bool match(string str, string pattern) {
    vector<vector<bool>> dp(str.size() + 1,
                            vector<bool>(pattern.size() + 1, false));
    dp[0][0] = true;
    for (int idx = 1; idx < pattern.size() + 1; idx++) {
      if (pattern[idx - 1] == '*')
        dp[0][idx] = dp[0][idx - 2];
    }

    for (int idx = 1; idx < str.size() + 1; idx++) {
      for (int jdx = 1; jdx < pattern.size() + 1; jdx++) {
        if (pattern[jdx - 1] != '*') {
          if (str[idx - 1] == pattern[jdx - 1] || pattern[jdx - 1] == '.') {
            dp[idx][jdx] = dp[idx][jdx] || dp[idx - 1][jdx - 1];
          }
        } else {
          if (jdx >= 2) {
            dp[idx][jdx] = dp[idx][jdx] || dp[idx][jdx - 2];
            if (str[idx - 1] == pattern[jdx - 2] || pattern[jdx - 2] == '.')
              dp[idx][jdx] = dp[idx][jdx] || dp[idx - 1][jdx];
          }
        }
      }
    }
    return dp.back().back();
  }
};

int main() {
  Solution sou;
  cout << sou.match("bbbba", ".*a*a") << endl;
  return 0;
}