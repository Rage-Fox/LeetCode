class Solution {
public:
    int dfs(vector<vector<int>> &books,int shelfWidth,int i,int remaining_width,int current_height,vector<vector<int>> &dp){
        if(i==books.size()){
            return current_height;
        }
        if(dp[i][remaining_width]!=-1){
            return dp[i][remaining_width];
        }
        // Place on a new level
        int new_level=current_height+dfs(books,shelfWidth,i+1,shelfWidth-books[i][0],books[i][1],dp);
        // Place on the same level if possible
        int same_level=INT_MAX;
        if(remaining_width>=books[i][0]){
            same_level=dfs(books,shelfWidth,i+1,remaining_width-books[i][0],max(current_height,books[i][1]),dp);
        }
        return dp[i][remaining_width]=min(same_level,new_level);
    }
    int minHeightShelves(vector<vector<int>> &books,int shelfWidth){
        vector<vector<int>> dp(books.size(),vector<int>(shelfWidth+1,-1));
        return dfs(books,shelfWidth,0,shelfWidth,0,dp);
    }
};