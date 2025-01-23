class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> colCounts(grid[0].size(),0),rowCounts(grid.size(),0);
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col]){
                    colCounts[col]++;
                    rowCounts[row]++;
                }
            }
        }
        int count=0;
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<size(grid[0]);col++){
                if(grid[row][col]){
                    count+=(colCounts[col]>1 or rowCounts[row]>1);
                }
            }
        }
        return count;
    }
};