class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>v;
        vector<int>ans;
        for(int j=0;j<matrix[0].size();j++){
            int maxx=INT_MIN;
            for(int i=0;i<matrix.size();i++){
                maxx=max(maxx,matrix[i][j]);
            }
            v.push_back(maxx);
        }
        for(int i=0;i<matrix.size();i++){
            int t=*min_element(matrix[i].begin(),matrix[i].end());
            if(find(v.begin(),v.end(),t)!=v.end()){
                ans.push_back(t);
            }
        }
        return ans;
    }
};