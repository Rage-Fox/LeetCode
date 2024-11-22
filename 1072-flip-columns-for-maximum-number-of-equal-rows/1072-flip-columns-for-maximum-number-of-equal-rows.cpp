class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mpp;
        for(auto mat:matrix){
            string s="";
            int first_ele=mat[0];
            for(int i=0;i<mat.size();i++){
                if(mat[i]==first_ele){
                    s+="1";
                }
                else{
                    s+="0";
                }
            }
            mpp[s]++;
        }
        int res=0;
        for(auto i:mpp){
            res=max(res,i.second);
        }
        return res;
    }
};