typedef long long ll;
class Solution {
public:
    long long findScore(vector<int>& nums) {
        ll n=nums.size();
        vector<bool> marked(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(ll i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        ll score=0;
        while(!pq.empty()){
            int val=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            if(marked[ind]){
                continue;
            }
            score+=val;
            for(ll j=ind-1;j<=ind+1;j++){
                if(j>=0 and j<n){
                    marked[j]=true;
                }
            }
        }
        return score;
    }
};