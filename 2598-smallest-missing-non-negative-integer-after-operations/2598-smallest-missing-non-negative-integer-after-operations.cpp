class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> remainder(value);
        for(auto &x:nums){
            int v=(x%value+value)%value;
            remainder[v]++;
        }
        int mex=0;
        while(remainder[mex%value]>0){
            remainder[mex%value]--;
            mex++;
        }
        return mex;
    }
};