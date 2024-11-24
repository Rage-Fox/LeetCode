class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res=0;
        int n=matrix.size(),m=matrix[0].size(),count=0,minval=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                minval=min(minval,abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    res+=(long long)(abs(matrix[i][j]));
                    count++;
                }
                else{
                    res+=(long long)(matrix[i][j]);
                }
            }
        }
        if(count%2!=0){
            res-=(long long)(2*minval);
        }
        return res;
    }
};