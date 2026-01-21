class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        // Explanation => https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/solutions/7511159/tired-of-scrolling-solutions-read-this-o-iel7
        int n=nums.size();
        vector<int> result(n);
        for(int i=0;i<n;i++){
            int cur=nums[i];
            if(cur==2){
                result[i]=-1;
                continue;
            }
            int temp=cur;
            int cnt=0;
            while((temp&1)==1){
                cnt++;
                temp>>=1;
            }
            result[i]=cur-(1<<(cnt-1));
        }
        return result;
    }
};