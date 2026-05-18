class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int>mpp(26,0);
        for(char i:tasks){
            mpp[i-'A']++;
        }   
        for(int i=0;i<26;++i){
            if(mpp[i]) 
                pq.push(mpp[i]);
        }
        int time=0;
        while(!pq.empty()){
            vector<int>remain;
            int cycle=n+1;// n+1 is the maximum CPU cycle length, if n is the cooldown period then after a task A there will be n more tasks. Hence n+1.
            while(cycle and !pq.empty()){
                int max_freq=pq.top();
                pq.pop();
                if(max_freq>1){
                    remain.push_back(max_freq-1);//if selected, choose it for the next interval only
                }
                ++time;
                --cycle;
            }
            for(int count:remain){
                pq.push(count); 
            }
            if(pq.empty())
                break;
            time+=cycle;//size of each interval
        }
        return time;
    }
};