class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        for(auto &row:mat){
            int n=row.size();
            for(int i=0;i<n;i++){
                if(row[i]!=row[(i+k)%n]){
                    return false;
                }
            }
        }
        return true;
    }
};