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
    int count_swaps(vector<int>&nums){
	    vector<pair<int,int>> v;
	    int n=nums.size();
	    for(int i=0;i<n;i++){
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end());
	    int cnt=0;
	    for(int i=0;i<n;i++){
	        if(v[i].second==i){
                continue;
            }
	        else{
	            cnt++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	    return cnt;
	}
    int minimumOperations(TreeNode* root) {
        int ans=0;
        queue<TreeNode*> q;
        q.push(root);
        if(root==NULL){
            return 0;
        }
        while(!q.empty()){
            int size=q.size();
            if(size==0){
                break;
            }
            vector<int> res;
            while(size>0){
                TreeNode* temp=q.front();
                q.pop();
                res.push_back(temp->val);
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
                size--;
            }
            ans+=count_swaps(res);
        }
     return ans;   
    }
};