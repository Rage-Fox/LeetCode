class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int prev=nums[n-1];
        int res=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==prev){
                continue;
            }
            else{
                prev=nums[i];
                res+=(n-i-1);
            }
        }
        return res;
    }
};