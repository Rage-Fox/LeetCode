class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        stack<int> st;
        int prev=0;
        for(auto &log:logs){
            int p1=log.find(':'),p2=log.find(':',p1+1);
            int id=stoi(log.substr(0,p1));
            string type=log.substr(p1+1,p2-p1-1);
            int time=stoi(log.substr(p2+1));
            if(type=="start"){
                if(!st.empty()){
                    ans[st.top()]+=time-prev;
                    // cout<<ans[st.top()]<<endl;
                }
                st.push(id);
                prev=time;
            }
            else{
                ans[st.top()]+=time-prev+1;
                // cout<<ans[st.top()]<<endl;
                st.pop();
                prev=time+1;
            }
        }
        return ans;
    }
};