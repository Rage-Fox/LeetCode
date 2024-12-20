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
    void DFS(TreeNode* leftChild,TreeNode* rightChild,int level){
        if(leftChild==NULL or rightChild==NULL){
            return;
        }
        if(level%2==0){
            int temp=leftChild->val;
            leftChild->val=rightChild->val;
            rightChild->val=temp;
        }
        DFS(leftChild->left,rightChild->right,level+1);
        DFS(leftChild->right,rightChild->left,level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        DFS(root->left,root->right,0);
        return root;
    }
};