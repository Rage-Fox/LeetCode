class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> result;        
        for(int i=0;i<nums.size();i++){
            int remaining=target-nums[i];
            if(m.find(remaining)!=m.end()) {
                result.push_back(m[remaining]);
                result.push_back(i);
                break;
            }
            else {
                m.insert({nums[i],i});
            }
        }        
        return result;
    }
};