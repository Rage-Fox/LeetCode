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
    map<TreeNode*,TreeNode*> nodeToPar;
    vector<TreeNode*> leaves;
    void dfs(TreeNode* root){
        if(root->left==NULL and root->right==NULL){
            leaves.push_back(root);
        }
        if(root->left){
            nodeToPar[root->left]=root;
            dfs(root->left);
        }
        if(root->right){
            nodeToPar[root->right]=root;
            dfs(root->right);
        }
        return;
    }
    void dfs2(TreeNode* node,TreeNode* par,int distance,int &ans){
        if(distance>=0 and !node->left and !node->right and node!=par){
            ans++;
        }
        if(node->left and node->left!=par){
            dfs2(node->left,node,distance-1,ans);
        }
        if(node->right and node->right!=par){
            dfs2(node->right,node,distance-1,ans);
        }
        if(nodeToPar[node] and nodeToPar[node]!=par){
            dfs2(nodeToPar[node],node,distance-1,ans);
        }
    }
    int countPairs(TreeNode* root, int distance) {
        nodeToPar[root]=NULL;
        dfs(root);
        int ans=0;
        for(auto it:leaves){
            dfs2(it,it,distance,ans); 
        }
        return ans/2;
    }
};