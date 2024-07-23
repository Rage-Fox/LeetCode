class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        sort(nums.begin(),nums.end(),[&](int n1,int n2){
            if(mpp[n1]!=mpp[n2]){
                return mpp[n1]<mpp[n2];
            }
            return n1>n2;
        });
        return nums;
    }
};