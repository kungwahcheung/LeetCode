/**
 * Note  : 1 ≤ m ≤ n ≤ length of list.
 * Input : 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 */
#include "listnode.h"

class Solution {
 public:
  ListNode* reverseBetween_v1(ListNode* head, int m, int n) {
    int steps = n - m + 1;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    head = dummy;
    while (--m) head = head->next;  // 令head指向第m个元素的前一个位置, 准备不断地往head后面插入Node
    // cur: 游标(cursor), 下一个要插入到head后面的Node
    // ptr: 这一轮要插入到head后面的Node
    // tail: 指向原链表的第m个元素, 将成为被反转的链表段的最后一个Node
    ListNode *cur = head->next, *ptr = NULL, *tail = head->next;
    while (steps--) {
      ptr = cur;
      cur = cur->next;
      ptr->next = head->next;
      head->next = ptr;
    }
    tail->next = cur;
    return dummy->next;
  }

  // 看LeetCode Discuss发现思路差不多, 但少用一个指针和一个变量的解法
  // 下面方法优点在于, 充分利用了cur, 这里的cur其实相当于上面的tail, 
  // 充分利用了cur的next用于保存下一个要被插入的Node, 
  // 而上面的解法则只是利用了tail本身(没有利用好它的next属性), 同时使用一个名为cur的指针保存下一个要被插入的Node
  // 下面的方法在循环中也不断更新了cur->next的值, 当循环结束时, 链表已经准备好了.
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    n = n - m;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    head = dummy;
    while (--m) head = head->next;  // 令head指向第m个元素的前一个位置, 准备不断地往head后面插入Node
    ListNode *cur = head->next;     // cur将一直指向第m个Node, 但cur->next一直变化, 指向下一个要被移动的Node
    ListNode *move = NULL;          // move是要移动的Node, move节点将被插入到head后面
    while (n--) {
      move = cur->next;
      cur->next = move->next;
      move->next = head->next;
      head->next = move;
    }
    return dummy->next;
  }
};

int main() {
  Solution sol = Solution();
  ListNode *head = create_list({1, 2, 3, 4, 5});
  print_list(head);
  ListNode *rev = sol.reverseBetween(head, 2, 4);
  print_list(rev);
  return 0;
}
