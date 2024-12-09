class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<int> cpairs;
        int count=0;
        cpairs.push_back(count);
        for(int i=1;i<nums.size();i++){
            // Equal Parity for Adjacent Indices
            if(nums[i]%2==nums[i-1]%2){
                count++;
            }
            cpairs.push_back(count);
        }
        for(auto it:queries){
            // From and To having equal parity counts, means that there's no adjacent indices with same parity in between
            res.push_back(cpairs[it[0]]==cpairs[it[1]]);
        }
        return res;
    }
};