class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),ans=0;
        for(int i=1; i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }
        for(int i=0;i<n;i++){
            vector<int> arr=matrix[i];
            sort(arr.begin(),arr.end());
            for(int j=0;j<m;j++){
                int height=arr[j],width=m-j;
                ans=max(ans,height*width);
            }
        }
        return ans;
    }
};