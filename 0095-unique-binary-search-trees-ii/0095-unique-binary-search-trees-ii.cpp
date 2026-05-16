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
    vector<vector<vector<TreeNode*>>> dp;
    vector<TreeNode*> generate(int left,int right){
        if(left>right){
            return {NULL};
        }
        if(!dp[left][right].empty()){
            return dp[left][right];
        }
        vector<TreeNode*> res;
        for(int val=left;val<=right;val++){
            vector<TreeNode*> leftTrees=generate(left,val-1);
            vector<TreeNode*> rightTrees=generate(val+1,right);
            for(auto &leftTree:leftTrees){
                for(auto &rightTree:rightTrees){
                    res.push_back(new TreeNode(val,leftTree,rightTree));
                }
            }
        }
        return dp[left][right]=res;
    }
    vector<TreeNode*> generateTrees(int n) {
        // https://neetcode.io/solutions/unique-binary-search-trees-ii
        dp.resize(n+1, vector<vector<TreeNode*>>(n+1));
        return generate(1,n);
    }
};