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
    int idx=0;
    unordered_map<int,int>mp;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int lb, int ub){
        if(lb>ub) return NULL;
        TreeNode* root = new TreeNode(preorder[idx++]);
        int mid = mp[root->val];
        root->left = helper(preorder,inorder,lb,mid-1);
        root->right= helper(preorder,inorder,mid+1,ub);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        TreeNode* root = helper(preorder,inorder,0,n-1);
        return root;
    }
};