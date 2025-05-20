class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> transformArray(nums.size()+1,0);
        for(auto query:queries){
            int left=query[0];
            int right=query[1];
            transformArray[left]+=1;
            transformArray[right+1]-=1;
        }
        vector<int> operationCounts;
        int currentOperations=0;
        for(int delta:transformArray){
            currentOperations+=delta;
            operationCounts.push_back(currentOperations);
        }
        for(int i=0;i<nums.size();i++){
            if(operationCounts[i]<nums[i]){
                return false;
            }
        }
        return true;
    }
};