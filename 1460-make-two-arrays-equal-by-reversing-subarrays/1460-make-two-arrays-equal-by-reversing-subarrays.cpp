class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size()!=arr.size()){
            return false;
        }
        vector<int> mpp(1001,0);
        for(int i=0;i<target.size();i++){
            mpp[target[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(mpp[arr[i]]==0){
                return false;
            }
            mpp[arr[i]]--;
        }
        return true;
    }
};