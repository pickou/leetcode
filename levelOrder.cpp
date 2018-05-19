// tranverse a tree using BFS with a queue
// use a number cnt to count the number of node in a level

/*

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root==NULL) return res;
        queue<TreeNode *> treeQue;
        TreeNode *node = root;
        treeQue.push(node);
        while(!treeQue.empty()) {
            // queue pop
            vector<int> tmp;
            int cnt = treeQue.size();
            for(int i=0; i<cnt; i++) {
                TreeNode *tp = treeQue.front();
                tmp.push_back(tp->val);
                treeQue.pop();
                if(tp->left!=NULL) treeQue.push(tp->left);
                if(tp->right!=NULL) treeQue.push(tp->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
