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
    int val=0;
    TreeNode* bstToGst(TreeNode* root){
        // Traverse through right nodes first and then left nodes
        // Add current node->val to the sum and then replace every current node by the current formed sum
        if(root->right){
            bstToGst(root->right);
        }
        val=val+root->val;
        root->val=val;
        if(root->left){
            bstToGst(root->left);
        }
        return root;
    }
};