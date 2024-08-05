class Solution {
public:
    string kthDistinct(vector<string> &arr,int k){
        unordered_map<string,int> mpp;
        for(string str:arr){
            mpp[str]++;
        }
        for(string str:arr){
            if(mpp[str]==1 && --k==0){
                return str;
            }
        }
        return "";
    }
};