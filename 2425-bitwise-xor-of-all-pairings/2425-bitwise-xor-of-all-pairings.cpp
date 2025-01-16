class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1=0,xor2=0;
        int len1=nums1.size(),len2=nums2.size();
        // If nums2 length is odd, each element in nums1 appears odd times (only once)
        if(len2%2!=0){
            for(int num:nums1){
                xor1^=num;
            }
        }
        // If nums1 length is odd, each element in nums2 appears odd times (only once)
        if(len1%2!=0){
            for(int num:nums2){
                xor2^=num;
            }
        }
        return xor1^xor2;
    }
};