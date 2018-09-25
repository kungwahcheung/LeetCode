#ifndef LEETCODE_TREENODE_H_
#define LEETCODE_TREENODE_H_

#define None 999999  // 用于给createTree输入的数组表示TreeNode为空

#include <vector>
#include <queue>
#include <iostream>

using std::vector;
using std::queue;
using std::cout;
using std::endl;

/**
 * definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
  [1,None,3,2],
  [3,2,None,1],
  [3,1,None,None,2],
  [2,1,3],
  [1,None,2,None,3]
  
	实现一个通过数组创建二叉树的功能.
  通过上面的数组, 分别输出下面的二叉树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 */

TreeNode* create_tree(vector<int> nodes) {
  if (nodes.empty() || nodes.front() == None) return NULL;
  TreeNode *root = new TreeNode(nodes.front());
  queue<TreeNode*> mqueue;
  mqueue.push(root);
  TreeNode *cur;
  for (int i = 1; i < nodes.size() && !mqueue.empty(); i += 2) {
    cur = mqueue.front();
    if (nodes[i] == None) {
      cur->left = NULL;
      if (i + 1 == nodes.size()) break;
      if (nodes[i+1] == None) {
        cur->right = NULL;
      } else {
        cur->right = new TreeNode(nodes[i+1]);
        mqueue.push(cur->right);
      }
    } else {
      cur->left = new TreeNode(nodes[i]);
      mqueue.push(cur->left);
      if (i + 1 == nodes.size()) break;
      if (nodes[i+1] == None) {
        cur->right = NULL;
      } else {
        cur->right = new TreeNode(nodes[i+1]);
        mqueue.push(cur->right);
      }
    }
    mqueue.pop();
  }
  return root;
}


void print_tree(TreeNode* root, int indent = 0) {
  if (root == NULL) return;
  print_tree(root->right, indent + 4);
  cout << '\n';
  for (int i = 0; i < indent; ++i) cout << " ";
  cout << "---" << root->val << '\n';
  print_tree(root->left, indent + 4);
}

#endif  // LEETCODE_TREENODE_H_
