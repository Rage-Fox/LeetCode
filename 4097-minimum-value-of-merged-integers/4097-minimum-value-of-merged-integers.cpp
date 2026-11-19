class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int minn=INT_MAX;
        for(int i=0;i<nums.size();i+=2){
            string s1=to_string(nums[i]);
            string s2=to_string(nums[i+1]);
            minn=min(minn,stoi(s1+s2));
        }
        return minn;
    }
};