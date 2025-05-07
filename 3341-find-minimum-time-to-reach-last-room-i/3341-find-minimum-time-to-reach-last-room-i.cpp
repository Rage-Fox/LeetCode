class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>cost(n,vector<int>(m,INT_MAX));
        cost[0][0]=moveTime[0][0];
        while(!pq.empty()){
            int co=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int r=row+dir[i][0];
                int c=col+dir[i][1];
                if(r>=0 and c>=0 and r<n and c<m){
                    if(co<=moveTime[r][c] and cost[r][c]>1+moveTime[r][c]){
                        cost[r][c]=1+moveTime[r][c];
                        pq.push({cost[r][c],{r,c}});
                    }
                    else if(co>moveTime[r][c] and cost[r][c]>1+co){
                        cost[r][c]=co+1;
                        pq.push({cost[r][c],{r,c}});
                    }
                }
            }
        }
        return cost[n-1][m-1];
    }
};