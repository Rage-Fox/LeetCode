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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int test=0;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->val==x || temp->val==y){
                    test++;
                }
                if(temp->left && temp->right){
                    // If both node's parents are same, then they would be "siblings" not cousins
                    if((temp->left->val==x && temp->right->val==y) ||
                       (temp->left->val==y && temp->right->val==x)){
                        return false;
                    }
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(test==2){
                return true;
            }
            // Only one node is found at current level, meaning other node is on another level
            if(test==1){
                return false;
            }
        }
        return false;
    }
};