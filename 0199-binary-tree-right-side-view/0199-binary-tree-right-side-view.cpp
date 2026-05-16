/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    void dfs(TreeNode* node, int depth) {
        if(!node){
            return;
        }
        // it means we haven't yet visited any node in current depth, thus push the node's val
        if(res.size()==depth){
            res.push_back(node->val);
        }
        // recursively traverse on right nodes and then left
        dfs(node->right,depth+1);
        dfs(node->left,depth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        // USING DFS
        dfs(root,0);
        return res;
    }
};