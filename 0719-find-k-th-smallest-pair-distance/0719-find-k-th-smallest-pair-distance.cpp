class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        // Minimum and maximum possible absolute difference
        int l=0,h=nums.back()-nums[0];
        while(l<h){
            int m=(h+l)/2;
            int count=0,left=0;
            for(int right=1;right<nums.size();right++){
                while(nums[right]-nums[left]>m){
                    left++;
                }
                count+=(right-left);
            }
            if(k>count){
                l=m+1;
            }
            else{
                h=m;
            }
        }
        return l;
    }
};