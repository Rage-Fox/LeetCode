class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int,int>> directions={{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
        int rows=board.size(),cols=board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int live=0;
                for(auto dir:directions){
                    int x=i+dir.first,y=j+dir.second;
                    if(x>=0 and x<rows and y>=0 and y<cols and abs(board[x][y])==1){
                        live++;
                    }
                }
                if(board[i][j]==1 and (live<2 or live>3)){
                    // Mark as -1 to indicate the cell was live but now dead
                    board[i][j]=-1;
                }
                if(board[i][j]==0 and live==3){
                    // Mark as 2 to indicate the cell was dead but now live
                    board[i][j]=2;
                }
            }
        }
        // Marking -1 as dead (0) and 2 as live(1)
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]>0){
                    board[i][j]=1;
                }
                else{
                    board[i][j]=0;
                }
            }
        }
    }
};