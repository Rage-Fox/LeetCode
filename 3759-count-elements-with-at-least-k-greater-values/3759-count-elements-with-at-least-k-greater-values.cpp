class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0){
            return n;
        }
        sort(nums.begin(),nums.end());
        int c=0;
        for(int i=0;i<n;i++){
            auto up=upper_bound(nums.begin(),nums.end(),nums[i]);
            int greater=n-(int)(up-nums.begin());
            if(greater>=k){
                c++;
            }
        }
        return c;
    }
};