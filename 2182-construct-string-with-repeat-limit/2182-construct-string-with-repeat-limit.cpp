class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mpp;
        for(char c:s){
            mpp[c]++;
        }
        priority_queue<char> pq;
        for(auto it:mpp){
            pq.push(it.first);
        }
        string result="";
        while(!pq.empty()){
            char ch=pq.top();
            pq.pop();
            int count=mpp[ch];
            int minn=min(count,repeatLimit);
            result.append(minn,ch);
            mpp[ch]-=minn;
            if(mpp[ch]>0 and !pq.empty()){
                char next=pq.top();
                pq.pop();
                result.push_back(next);
                mpp[next]--;
                if(mpp[next]>0){
                    pq.push(next);
                }
                pq.push(ch);
            }
        }
        return result;
    }
};