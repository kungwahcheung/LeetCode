/**
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */

#include "listnode.h"

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *cur = dummy;
    int a, b, carry = 0;
    while (l1 || l2) {
      a = l1 ? l1->val : 0;
      b = l2 ? l2->val : 0;
      cur->next = new ListNode((a + b + carry) % 10);
      carry = (a + b + carry) / 10;
      cur = cur->next;
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }
    if (carry) cur->next = new ListNode(carry);
    return dummy->next;
  }
};


int main() {
  Solution sol = Solution();
  ListNode *l1 = create_list({2, 4, 3});
  ListNode *l2 = create_list({5, 6, 4});
  print_list(l1);
  print_list(l2);
  ListNode *res = sol.addTwoNumbers(l1, l2);
  print_list(res);
  return 0;
}
