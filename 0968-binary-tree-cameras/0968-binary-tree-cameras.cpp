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
    int ans=0;
    pair<bool,bool> dfs(TreeNode *root) {
        if(!root){
            return {false,true};
        }
        pair<bool,bool> left_c_m = dfs(root->left);
        pair<bool,bool> right_c_m = dfs(root->right);
        int camera=false,monitor=false;
        // children camera can monitor parent
        if(left_c_m.first || right_c_m.first){
            monitor=true;
        }
        // parent's camera can monitor it's unmonitored children
        if(!left_c_m.second || !right_c_m.second){
            camera=true;
            ans++;
            monitor=true;
        }
        return {camera,monitor};
    }
    int minCameraCover(TreeNode* root) {
        pair<bool,bool> camera_monitor = dfs(root);
        if(!camera_monitor.second){
            ans++;
        }
        return ans;
    }
};