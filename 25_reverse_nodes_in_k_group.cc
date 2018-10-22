#include <iostream>
#include <string>
#include <vector>

#include "listnode.h"

using namespace std;

#ifdef SOLUTION_MINE

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *dummy = new ListNode(-1),  // dummy head
             *cur = head,                // 每次待插入到开头的Node
             *tail = head;               // 临时保存k-group的第一个Node (反转后会成为最后一个Node)
    // 若链表长度不足k, 直接返回
    for (int i = 0; i < k; ++i) {
      if (cur == nullptr) return head;
      cur = cur->next;
    }
    // 倒排k-group就是不断地把后面的Node插入到最前面
    for (int i = 0; i < k; ++i) {
      cur = head;
      head = head->next;
      cur->next = dummy->next;
      dummy->next = cur;
    }
    tail->next = reverseKGroup(head, k);
    return dummy->next;
  }
};

#else

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *dummy = new ListNode(-1),
             *pre = dummy,
             *cur = head;
    dummy->next = head;
    int p = 0;
    while (cur) {
      ++p;
      if (p % k == 0) {
        pre = reverse(pre, cur->next);
        cur = pre->next;
      } else {
        cur = cur->next;
      }
    }
    return dummy->next;
  }
 
 private:
  // pre -> 1 -> 2 -> 3 -> next -> more  ==>  pre -> 3 -> 2 -> 1 -> next -> more
  ListNode* reverse(ListNode* pre, ListNode* next) {
    ListNode *tail = pre->next,  // tail指向待反转链表的第一个Node, 亦即反转后链表的最后一个Node
             *cur = tail->next;  // 我们轮流把tail后面的Node插入到pre后面, cur就是这个待插入Node的指针
    while (cur != next) {
      tail->next = cur->next;
      cur->next = pre->next;
      pre->next = cur;
      cur = tail->next;
    }
    return tail;
  }
};

#endif  // SOLUTION_MINE


int main() {
  Solution sol = Solution();
  ListNode *head = create_list({1,2,3,4,5});
  print_list(head);
  print_list(sol.reverseKGroup(head, 2));
  return 0;
}
