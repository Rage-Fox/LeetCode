class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for(auto x:nums){
            if(x%2==0){
                res.push_back(-1);
            }
            else{
                int t=0;
                while(x&(1<<t)){
                    t++;
                }
                res.push_back(x^(1<<(t-1)));
            }
        }
        return res;
    }
};