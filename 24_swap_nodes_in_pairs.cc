#include <vector>
#include <iostream>

#include "listnode.h"

using namespace std;

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode *dummy = new ListNode(-1), *pre = dummy;
    dummy->next = head;
    ListNode *cur = nullptr;
    while (pre->next && pre->next->next) {
      cur = pre->next->next;
      pre->next->next = cur->next;
      cur->next = pre->next;
      pre->next = cur;
      pre = cur->next;
    }
    return dummy->next;
  }
};

int main() {
  Solution sol = Solution();
  ListNode *head = create_list({1, 2, 3, 4, 5});
  print_list(head);
  print_list(sol.swapPairs(head));
  return 0;
}
