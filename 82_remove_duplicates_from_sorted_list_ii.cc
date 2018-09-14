#include "listnode.h"


class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode *dummy = new ListNode(0), *cur = dummy;
    while (head) {
      if (head->next) {
        if (head->next->val != head->val) {  // current head node has no duplicates
          cur->next = head;
          cur = cur->next;
          head = head->next;
        }
        else {  // duplicates exist, skip all duplicates
          int duplicate = head->val;
          while (head && head->val == duplicate) head = head->next;
        }
      } else {  // reach the last node
        cur->next = head;
        cur = cur->next;
        head = head->next;
      }
    }
    cur->next = NULL;
    return dummy->next;
  }
};

int main() {
  Solution sol = Solution();
  ListNode *head = create_list({1, 2, 3, 3, 4, 4, 5});
  ListNode *new_head = sol.deleteDuplicates(head);
  print_list(new_head);
  return 0;
}
