class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int e=0,o=0;
        for(auto x:nums){
            if(x&1){
                o++;
            }
            else{
                e++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                o--;
                ans[i]=e;
            }
            else{
                e--;
                ans[i]=o;
            }
        }
        return ans;
    }
};