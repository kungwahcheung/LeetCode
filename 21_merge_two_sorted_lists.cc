#include <iostream>
#include <string>
#include <vector>

#include "listnode.h"

using namespace std;

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(-1), *ptr = dummy;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        ptr->next = l1;
        l1 = l1->next;
      } else {
        ptr->next = l2;
        l2 = l2->next;
      }
      ptr = ptr->next;
    }
    if (l1) 
      ptr->next = l1;
    else 
      ptr->next = l2;
    return dummy->next;
  }
};


int main() {
  Solution sol = Solution();
  ListNode *l1 = create_list({1, 3, 5, 7});
  print_list(l1);
  ListNode *l2 = create_list({2, 4, 6, 8});
  print_list(l2);
  ListNode *l3 = sol.mergeTwoLists(l1, l2);
  print_list(l3);
  return 0;
}
