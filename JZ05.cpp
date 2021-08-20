/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-20 19:43:11
 * @LastEditors: V4kst1z
 * @Description: JZ5 用两个栈实现队列
 * @FilePath: /CodingInterviews/JZ05.cpp
 */

// 用两个栈来实现一个队列，分别完成在队列尾部插入整数(push)和
// 在队列头部删除整数(pop)的功能。 队列中的元素为int类型。保证
// 操作合法，即保证pop操作时队列内已有元素。

// 示例:
// 输入:
// ["PSH1","PSH2","POP","POP"]
// 返回:
// 1,2
// 解析:
// "PSH1":代表将1插入队列尾部
// "PSH2":代表将2插入队列尾部
// "POP“:代表删除一个元素，先进先出=>返回1
// "POP“:代表删除一个元素，先进先出=>返回2

// 输入：
// ["PSH1","PSH2","POP","POP"]
// 返回值：
// 1,2

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
  void push(int node) { stack1.push(node); }

  int pop() {
    int res;
    if (stack2.empty()) {
      while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }
    res = stack2.top();
    stack2.pop();
    return res;
  }

private:
  stack<int> stack1; // push
  stack<int> stack2; // pop
};

int main() {
  Solution sou;
  sou.push(1);
  sou.push(2);
  sou.push(3);
  sou.push(4);
  cout << sou.pop() << endl;
  return 0;
}
