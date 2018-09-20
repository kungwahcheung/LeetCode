#include <vector>
#include <iostream>
#include "listnode.h"

using std::vector;
using std::cout;
using std::endl;

class Solution {
 public:
/*
  // 迭代解法简单明了, 就是不断地把原来链表的node插入到dummy的后面
  ListNode* reverseList(ListNode* head) {
    if (!head) return head;
    ListNode *dummy = new ListNode(0), *ptr = NULL;
    while (head) {
      ptr = head;
      head = head->next;
      ptr->next = dummy->next;
      dummy->next = ptr;
    }
    return dummy->next;
  }
*/
  // 递归解法
  ListNode* reverseList(ListNode* head) {
    if (!head || head->next == NULL) return head;
    ListNode *reversed_list = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return reversed_list;
  }
};

int main() {
  Solution sol = Solution();
  ListNode *head = create_list({1, 2, 3, 4, 5});
  print_list(head);
  ListNode *rev = sol.reverseList(head);
  print_list(rev);
  return 0;
}
