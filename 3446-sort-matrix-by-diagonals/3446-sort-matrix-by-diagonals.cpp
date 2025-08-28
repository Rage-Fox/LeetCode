class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int,vector<int>> diagonalMap;
        int rows=grid.size(),cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                diagonalMap[i-j].push_back(grid[i][j]);
            }
        }
        // Sort each diagonal; diagonals with negative keys are sorted in ascending order,
        // while diagonals with positive keys are sorted in descending order
        for(auto &entry:diagonalMap){
            if(entry.first<0){
                sort(entry.second.begin(),entry.second.end());
            }
            else{
                sort(entry.second.rbegin(),entry.second.rend());
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                grid[i][j]=diagonalMap[i-j].front();
                diagonalMap[i-j].erase(diagonalMap[i-j].begin());
            }
        }
        return grid;
    }
};