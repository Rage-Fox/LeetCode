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
    map<int,int> l,r,h;
    int height(TreeNode *root){
        if(!root){
            return 0;
        }
        int lh=height(root->left),rh=height(root->right);
        l[root->val]=lh;
        r[root->val]=rh;
        return max(lh,rh)+1;
    }
    void solve(TreeNode *root,int maxa,int depth){
        if(!root){
            return;
        }
        h[root->val]=maxa;
        solve(root->left,max(maxa,depth+r[root->val]),depth+1);
        solve(root->right,max(maxa,depth+l[root->val]),depth+1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height(root);
        // Removing the current node and adding the depth & it's opposite traversal height for queries
        solve(root->left,r[root->val],1);
        solve(root->right,l[root->val],1);
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(h[queries[i]]);
        }
        return ans;
    }
};