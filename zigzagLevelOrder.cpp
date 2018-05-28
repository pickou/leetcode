// leetcode 103.
// two solutions
// queue and deque
/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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

/*
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode*> nodeQ;
        TreeNode* node = root;
        char lflag = 0x01;
        nodeQ.push(root);
        while(!nodeQ.empty()) {
            int numNodes = nodeQ.size();
            vector<int> tmp;
            for(int i=0; i<numNodes; i++) {
                node = nodeQ.front();
                nodeQ.pop();
                tmp.push_back(node->val);
                if(node->left) nodeQ.push(node->left);
                if(node->right) nodeQ.push(node->right);
            }
            if(lflag==0x01) {
                res.push_back(tmp);
            }
            else {
                vector<int> tmpr;
                for(int i=tmp.size()-1; i>=0; i--) {
                    tmpr.push_back(tmp[i]);
                }
                res.push_back(tmpr);
            }
            lflag ^= 0x01;
        }
        return res;
    }
};
*/
// deque
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        deque<TreeNode*> nodeQ;
        TreeNode* node = root;
        char lflag = 0x01;
        nodeQ.push_back(root);
        while(!nodeQ.empty()) {
            int numNodes = nodeQ.size();
            vector<int> tmp;
            if(lflag==0x01) { // front pop, back push (right<->back, left<->front)
                for(int i=0; i<numNodes; i++) {
                    node = nodeQ.front();
                    nodeQ.pop_front();
                    tmp.push_back(node->val);
                    if(node->left) nodeQ.push_back(node->left);
                    if(node->right) nodeQ.push_back(node->right);
                }
            }
            else {
                 for(int i=0; i<numNodes; i++) { //back pop, front push
                    node = nodeQ.back();
                    nodeQ.pop_back();
                    tmp.push_back(node->val);
                    if(node->right) nodeQ.push_front(node->right);
                    if(node->left) nodeQ.push_front(node->left);
                }
            }
            res.push_back(tmp);
            lflag ^= 0x01;
        }
        return res;
    }
};
