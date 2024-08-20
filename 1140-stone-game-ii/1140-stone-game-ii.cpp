class Solution {
public:
    int n;
    int dp[2][101][101];
    int dfs(bool isAlice,int i,int M,vector<int> &piles){
        if(i==n){
            return 0;
        }
        if(dp[isAlice][i][M]!=-1){
            return dp[isAlice][i][M];
        }
        int res;
        // We always want maximum for Alice. So alice's result starts with 0.
        if(isAlice){
            res=0;
        }
        // To maximize alice, we need to minimize bob. So bob's result is always INT_MAX.
        else{
            res=INT_MAX;
        }
        int total=0;
        for(int x=1;x<=2*M;x++){
            if(i+x>n){
                break;
            }
            // We always choose a set of continuous window. So, performing prefix may make it easy without using extra loop.
            total+=piles[i+x-1];
            // We only want alice's max result. So total is going to add in this case. As for bob, we don't need his total as a result.
            if(isAlice){
                // We always want maximum for Alice.
                res=max(res,total+dfs(!isAlice,i+x,max(M,x),piles));
            }
            else{
                // To maximize alice, we need to minimize bob.
                res=min(res,dfs(!isAlice,i+x,max(M,x),piles));
            }
        }
        return dp[isAlice][i][M]=res;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        // As alice always picks first, send true.
        return dfs(true,0,1,piles);
    }
};