/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-28 23:41:13
 * @LastEditors: V4kst1z
 * @Description: JZ61 序列化二叉树
 * @FilePath: /CodingInterviews/JZ61.cpp
 */

#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  string data;

  int getCurrEnd(char *str, int begin, int len) {
    while (begin < len) {
      if (str[begin] == ',')
        return begin;
      begin++;
    }
    return -1;
  }

public:
  char *Serialize(TreeNode *root) {
    if (!root)
      return nullptr;
    data = "";
    queue<TreeNode *> qNode;
    bool hasNode;
    qNode.push(root);
    while (qNode.size()) {
      int num = qNode.size();
      hasNode = false;
      while (num--) {
        TreeNode *tmp = qNode.front();
        qNode.pop();
        // 当前节点是 nullptr
        if (!tmp) {
          data += "#,";
          continue;
        }
        hasNode = true;
        data += to_string(tmp->val) + ",";
        qNode.push(tmp->left);
        qNode.push(tmp->right);
      }
      if (!hasNode)
        break;
    }
    return const_cast<char *>(data.data());
  }

  TreeNode *Deserialize(char *str) {
    if (!str)
      return nullptr;
    int len = strlen(str);
    if (!len)
      return nullptr;

    int currBegin = 0, currEnd = getCurrEnd(str, 0, len);
    int rootVal = atoi(str);
    TreeNode *root = new TreeNode(rootVal);
    queue<TreeNode *> prevNode;
    bool hasNode = true;
    int num = 2;

    currBegin = currEnd + 1;
    currEnd = getCurrEnd(str, currBegin, len);
    prevNode.push(root);
    while (hasNode) {
      hasNode = false;
      int num = prevNode.size();
      while (num--) {
        TreeNode *tmp = prevNode.front();
        prevNode.pop();
        if (!tmp) {
          continue;
        }
        if (str[currBegin] != '#') {
          int val = atoi(str + currBegin);
          tmp->left = new TreeNode(val);
          prevNode.push(tmp->left);
          hasNode = true;
        } else {
          prevNode.push(nullptr);
        }
        currBegin = currEnd + 1;
        currEnd = getCurrEnd(str, currBegin, len);
        if (str[currBegin] != '#') {
          int val = atoi(str + currBegin);
          tmp->right = new TreeNode(val);
          prevNode.push(tmp->right);
          hasNode = true;
        } else {
          prevNode.push(nullptr);
        }
        currBegin = currEnd + 1;
        currEnd = getCurrEnd(str, currBegin, len);
      }
      if (!hasNode)
        break;
    }
    return root;
  }
};

int main() {
  Solution sou;

  // 5
  // 4,#,
  // 3,#,#,#,
  // 2,#,#,#,#,#,#,#,

  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(2);

  char *ptr = sou.Serialize(root);
  auto *ret = sou.Deserialize(ptr);
  queue<TreeNode *> qNode;
  qNode.push(ret);
  while (qNode.size()) {
    int num = qNode.size();
    while (num--) {
      auto *node = qNode.front();
      qNode.pop();
      cout << node->val << " ";
      if (node->left)
        qNode.push(node->left);
      if (node->right)
        qNode.push(node->right);
    }
  }

  return 0;
}