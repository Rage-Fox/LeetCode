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
    pair<int, int> solve(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        auto [lp1, lp2] = solve(root->left);
        auto [rp1, rp2] = solve(root->right);
        int take = root->val + lp2 + rp2;
        int skip = lp1 + rp1;
        return {max(take, skip), skip};
    }
    int rob(TreeNode* root) {
        // This is parent-child based, so don't attempt skipping entire level
        auto [ans, _] = solve(root);
        return ans;
    }
};