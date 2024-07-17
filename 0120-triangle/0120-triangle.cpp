class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle){
        int numRows=triangle.size();
        for(int row=numRows-2;row>=0;row--){
            for(int col=0;col<triangle[row].size();col++){
                int below=triangle[row+1][col];
                int belowRight=triangle[row+1][col+1];
                triangle[row][col]=min(below,belowRight)+triangle[row][col];
            }
        }
        return triangle[0][0];
    }
};