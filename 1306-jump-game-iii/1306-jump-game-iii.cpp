class Solution {
public:
    bool canReach(vector<int> &arr,int start){
        vector<bool> vis(arr.size(),false);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int top=q.front();
            q.pop();
            vis[top]=true;
            if(arr[top]==0){
                return true;
            }
            if(top-arr[top]>=0 and vis[top-arr[top]]==false){
                q.push(top-arr[top]);
                vis[top-arr[top]]=true;
            }
            if(top+arr[top]<arr.size() and vis[top+arr[top]]==false){
                q.push(top+arr[top]);
                vis[top+arr[top]]=true;
            }
        }
        return false;
    }
};