#ifndef LEETCODE_LISTNODE_H_
#define LEETCODE_LISTNODE_H_

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

/**
 * definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/**
 * create a list from a vector
 * since an array will be converted to vector implicitly,
 * nums can be replaced by a array.
 * sample code:
 *
 * ListNode *node = create_list({1, 2, 3, 4});
 */
ListNode* create_list(vector<int> nums) {
  ListNode *dummy = new ListNode(0);
  ListNode *cur = dummy;
  for (auto it : nums) {
    cur->next = new ListNode(it);
    cur = cur->next;
  }
  return dummy->next;
}

/**
 * given the head pointer, print the whole list
 */
void print_list(ListNode *head) {
  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "None" << endl;
}

#endif  // LEETCODE_LISTNODE_H_
