class Solution {
public:
    int maxResult(vector<int> &nums,int k){
        priority_queue<pair<int,int>> pq;
        int n=nums.size();
        pq.push({nums[0],0});
        for(int i=1;i<n;i++){
            while(!pq.empty()){
                int top=pq.top().second;
                if(top<i-k){
                     pq.pop();
                }
                else{
                    break;
                }
            }
            int max_so_far=pq.top().first;
            pq.push({max_so_far+nums[i],i});
            if(i==n-1){
                return max_so_far+nums[i];
            }
        }
        return nums[0];
    }
};