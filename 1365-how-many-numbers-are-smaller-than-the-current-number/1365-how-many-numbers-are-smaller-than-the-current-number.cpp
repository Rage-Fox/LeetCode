class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(101,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(int i=1;i<freq.size();i++){
            freq[i]+=freq[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                nums[i]=0;
            }
            else{
                nums[i]=freq[nums[i]-1];
            }
        }
        return nums;
    }
};