class Solution {
public:
    int longestSubarray(vector<int> &nums){
        int nums_max_ele=*max_element(nums.begin(),nums.end());
        int count=0,max_count=0;
        for(auto ele:nums){
            if(ele==nums_max_ele){
                count++;
            }
            else{
                max_count=max(max_count,count);
                count=0;
            }
        }
        max_count=max(max_count,count);
        return max_count;
    }
};