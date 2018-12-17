#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*

     1
   /  \
  2    3
 / \    \
4   5    7

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL

 */

/* Definition for binary tree with next pointer. */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
 public:
	void connect(TreeLinkNode *root) {
    // dummy->next will points to the first node of next level
    TreeLinkNode *dummy = new TreeLinkNode(0);
    TreeLinkNode *cur = dummy;
    while (root) {
      if (root->left) {
        cur->next = root->left;
        cur = cur->next;
      }
      if (root->right) {
        cur->next = root->right;
        cur = cur->next;
      }
      root = root->next;
      // reach the end of current level
      if (root == nullptr) {
        root = dummy->next;
        cur = dummy;
        cur->next = nullptr;
      }
    }
  }
};


int main() {
  Solution sol = Solution();

  return 0;
}
