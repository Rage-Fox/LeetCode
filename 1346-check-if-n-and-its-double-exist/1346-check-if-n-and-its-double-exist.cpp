class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(auto i:arr){
            if(mpp[2*i]!=0){
                return true;
            }
            else if(i%2==0 and mpp[i/2]!=0){
                return true;
            }
            mpp[i]++;
        }
        return false;
    }
};