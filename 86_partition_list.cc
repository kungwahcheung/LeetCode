#include <iostream>
#include "listnode.h"

using std::cout;
using std::endl;

class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode dummy_left = ListNode(0), dummy_right = ListNode(0);
    ListNode *left = &dummy_left, *right = &dummy_right;
    while (head) {
      if (head->val < x) {
        left->next = head;
        left = left->next;
      } else {
        right->next = head;
        right = right->next;
      }
      head = head->next;
    }
    left->next = dummy_right.next;
    right->next = NULL;
    return dummy_left.next;
  }
};

int main() {
  Solution sol = Solution();
  ListNode *head = create_list({1, 4, 3, 2, 5, 2});
  int x = 3;
  ListNode *partition_list = sol.partition(head, x);
  print_list(partition_list);
  return 0;
}
