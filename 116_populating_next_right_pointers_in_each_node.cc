#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Definition for binary tree with next pointer. */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
 public:
  void connect(TreeLinkNode *root) {
    if (root == nullptr) return;
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = nullptr;
    while (pre->left) {
      cur = pre;
      while (cur) {
        cur->left->next = cur->right;
        if (cur->next) cur->right->next = cur->next->left;
        //else cur->right->next = nullptr;  // no need, default value for next is nullptr
        cur = cur->next;
      }
      pre = pre->left;
    }
  }
};


int main() {
  Solution sol = Solution();

  return 0;
}
