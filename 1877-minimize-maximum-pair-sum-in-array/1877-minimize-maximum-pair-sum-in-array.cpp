class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1,maxx=INT_MIN;
        while(i<j){
            maxx=max(maxx,nums[i]+nums[j]);
            i++;
            j--;
        }
        return maxx;
    }
};