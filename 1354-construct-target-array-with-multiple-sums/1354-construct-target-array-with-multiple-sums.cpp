class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq(target.begin(),target.end());
        long long total=0;
        int n=target.size();
        for(int i=0;i<n;i++){
            total+=target[i];
        }
        while(pq.top()!=1){
            int a=pq.top();
            pq.pop();
            total-=a;
            if(a==1 || total==1){
                return true;
            }
            if(total==0 || a<total || a%total==0){
                return false;
            }
            // TLE correction
            a%=total;
            pq.push(a);
            total+=a;
        }
        return true;
    }
};