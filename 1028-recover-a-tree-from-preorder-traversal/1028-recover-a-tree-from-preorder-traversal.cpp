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
    TreeNode* recoverFromPreorder(string s) {
        int n=s.length();
        stack<TreeNode*> st;
        int i=0;
        TreeNode* root=nullptr;
        while(i<n){
            int depth=0;
            int num=0;
            while(i<n and s[i]=='-'){
                depth++;
                i++;
            }
            while(i<n and s[i]!='-'){
                num=num*10+(s[i]-'0');
                i++;
            }
            TreeNode* node=new TreeNode(num);
            if(!st.empty()){
                // In pre-order traversal, you don't need to store the last leaf
                while(st.size()>depth){
                    st.pop();
                }
                if(!st.top()->left){
                    st.top()->left=node;
                }
                else{
                    st.top()->right=node;
                }
            }
            if(depth==0){
                root=node;
            }
            st.push(node);
        }
        return root;
    }
};