class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int usedBits=0,start=0,maxx=0;
        for(int end=0;end<nums.size();end++){
            // If current number shares bits with window, shrink window from
            // left until there's no bit conflict
            while((usedBits&nums[end])!=0){
                // Remove leftmost element's bits
                usedBits^=nums[start];
                start++;
            }
            // Add current number to the window
            usedBits|=nums[end];
            maxx=max(maxx,end-start+1);
        }
        return maxx;
    }
};