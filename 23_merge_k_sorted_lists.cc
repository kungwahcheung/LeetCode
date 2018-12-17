#include "listnode.h"
#include <iostream>
#include <string>
#include <vector>

#ifndef SOLUTION
#define SOLUTION 1
#endif  // SOLUTION

using namespace std;

class Solution {
 public:
#if SOLUTION == 1
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode dummy = ListNode(-1);
    ListNode *ptr = &dummy;
    int size = lists.size();
    int k = 0, min_val = 0;
    int min_index = 0;  // 用于保存每一轮最小值的所在链表的下标
    while (true) {
      k = 0;
      while (k < size && lists[k] == NULL) ++k;
      if (k == size) return dummy.next;
      min_index = k;
      min_val = lists[k]->val;  // 新一轮的初始值
      while (k < size) {
        if (lists[k] && (lists[k]->val < lists[min_index]->val)) min_index = k;
        ++k;
      }
      ptr->next = lists[min_index];
      lists[min_index] = lists[min_index]->next;
      ptr = ptr->next;
    }
  }
#elif SOLUTION == 2
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    if (lists.size() <= 1) return lists.front();
    while (lists.size() > 1) {
      
    }

  }
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode* pre  = new ListNode(-1), cur = pre;
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }
    if (l1) cur->next = l1;
    else cur->next = l2;

    return pre->next;
  }
#elif SOLUTION == 3
#endif  // SOLUTION
};


int main() {
  Solution sol = Solution();
  vector<ListNode*> lists{create_list({1,4,7}), create_list({2,5,8}), create_list({3,6,9})};
  ListNode *res = sol.mergeKLists(lists);
  print_list(res);
  return 0;
}
