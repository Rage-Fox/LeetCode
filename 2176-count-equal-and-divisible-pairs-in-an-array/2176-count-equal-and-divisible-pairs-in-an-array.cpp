class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int count=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j] and (i*j)%k==0){
                    count++;
                }
            }
        }
        return count;
    }
};