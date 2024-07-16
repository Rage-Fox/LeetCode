class Solution {
public:
    vector<int> ds;
    vector<vector<int>> ans;
    void f(int i,vector<int> &nums,int target){
        if(target<0){
            return;
        }
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int s=i;s<nums.size();s++){
            if(s>i and nums[s]==nums[s-1]){
                continue;
            }
            if(nums[s]>target){
                break;
            }
            ds.push_back(nums[s]);
            f(s+1,nums,target-nums[s]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates,int target){
        sort(candidates.begin(),candidates.end());
        f(0,candidates,target);
        return ans;
    }
};