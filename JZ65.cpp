/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-09-01 11:45:17
 * @LastEditors: V4kst1z
 * @Description: JZ65 矩阵中的路径
 * @FilePath: /CodingInterviews/JZ65.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  bool dfs(vector<vector<char>> &matrix, string &word, int row, int col,
           int idx, vector<vector<bool>> &visited) {
    if (idx == word.size())
      return true;
    bool ret = false;
    if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size() ||
        matrix[row][col] != word[idx] || idx > word.size() || visited[row][col])
      return false;
    visited[row][col] = true;
    ret |= dfs(matrix, word, row + 1, col, idx + 1, visited);
    ret |= dfs(matrix, word, row - 1, col, idx + 1, visited);
    ret |= dfs(matrix, word, row, col - 1, idx + 1, visited);
    ret |= dfs(matrix, word, row, col + 1, idx + 1, visited);
    visited[row][col] = false;
    return ret;
  }

public:
  bool hasPath(vector<vector<char>> &matrix, string word) {
    if (matrix.empty() || matrix[0].empty() || word.empty())
      return false;
    int rowLen = matrix.size(), colLen = matrix[0].size();
    vector<vector<bool>> visited(rowLen, vector<bool>(colLen, false));

    for (int idx = 0; idx < rowLen; idx++) {
      for (int jdx = 0; jdx < colLen; jdx++) {
        if (word[0] != matrix[idx][jdx])
          continue;
        if (dfs(matrix, word, idx, jdx, 0, visited))
          return true;
      }
    }
    return false;
  }
};
int main() {
  Solution sou;
  vector<vector<char>> matrix = {
      {'a', 'b', 'c', 'e'}, {'s', 'f', 'c', 's'}, {'a', 'd', 'e', 'e'}};
  cout << sou.hasPath(matrix, "see") << endl;
  return 0;
}