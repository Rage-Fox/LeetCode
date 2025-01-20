class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int r=mat.size(),c=mat[0].size();
        vector<int> rowCount(r),colCount(c);
        unordered_map<int,pair<int,int>> numToPos;
        // Create a map to store the position of each number in the matrix
        for(int row=0;row<r;row++){
            for(int col=0;col<c;col++){
                int value=mat[row][col];
                numToPos[value]={row,col};
            }
        }
        // Painting array values indexing from 0 for the num converted matrix
        for(int i=0;i<arr.size();i++){
            int num=arr[i];
            auto [row,col]=numToPos[num];
            rowCount[row]++;
            colCount[col]++;
            // Check if the row or column is completely painted
            if(rowCount[row]==c or colCount[col]==r){
                return i;
            }
        }

        return -1;
    }
};