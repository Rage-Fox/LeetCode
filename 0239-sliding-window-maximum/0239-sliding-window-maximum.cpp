class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> v;
        int n=arr.size();
        for(int i=0;i<k;i++){
            pq.push({arr[i],i});
        }
        v.push_back(pq.top().first);
        for(int i=k;i<n;i++){
            pq.push({arr[i],i});
            // Removing the top element of PQ if the current maximum is from previous windows
            while(pq.top().second<=i-k){
                pq.pop();
            }
            v.push_back(pq.top().first);
        }
        return v;
    }
};