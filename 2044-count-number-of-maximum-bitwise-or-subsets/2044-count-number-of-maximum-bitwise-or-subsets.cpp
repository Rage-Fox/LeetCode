class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size(),m=0,c=0;
        for(int x:nums){
            m|=x;
        }
        for(int mask=1;mask<(1<<n);mask++){
            int o=0;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    o|=nums[i];
                }
            }
            if(o==m){
                c++;
            }
        }
        return c;
    }
};