/**
 * 经典题目之一: 删除链表的倒数第n个节点
 * 方法也是经典的方法: 前后指针
 * 这个问题需要特别注意的是, 当删除的是链表的第一个节点时, 程序能否正确处理:
 * LeetCode Discuss中有不同的做法, 我比较习惯使用一个dummy变量作为新的链表头, 使得不同的情况可以使用同一套处理。
 */

#include <iostream>
#include <string>
#include <vector>

#include "listnode.h"

using namespace std;

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    head = dummy;
    ListNode *back = dummy;
    for (int i = 0; i < n; ++i) {
      head = head->next;
    }
    while (head->next != NULL) {
      head = head->next;
      back = back->next;
    }
    // now, head point to the last node of the list
    ListNode *tmp = back->next;
    back->next = tmp->next;
    head = NULL;
    back = NULL;
    delete tmp;
    delete head;
    delete back;
    return dummy->next;
  }
};


int main() {
  Solution sol = Solution();
  ListNode *head = create_list({1, 2, 3, 4, 5});
  head = sol.removeNthFromEnd(head, 3);
  print_list(head);
  return 0;
}
