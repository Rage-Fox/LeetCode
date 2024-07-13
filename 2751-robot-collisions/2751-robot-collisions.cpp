class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> ans;
        vector<int> sol;
        vector<pair<pair<int,int>,char>> v;
        unordered_map<int,int> m;
        for(int i=0;i<positions.size();i++){
            m[positions[i]]=i;
            v.push_back({{positions[i],healths[i]},directions[i]});
        }
        sort(v.begin(),v.end());
        stack<pair<int,int>> st;
        for(int i=0;i<v.size();i++){
            if(v[i].second=='R'){
                st.push({v[i].first.first,v[i].first.second});
            }
            else{
                int l=v[i].first.second;
                while(!st.empty()){
                    auto temp=st.top();
                    st.pop();
                    if(l>temp.second){
                        l-=1;
                    }
                    else{
                        temp.second-=1;
                        // Both having same health, then both should be removed
                        if(temp.second+1!=l){
                            st.push(temp);
                        }
                        l=0;
                        break;
                    }
                }
                if(l!=0){
                    ans.push({m[v[i].first.first],l});
                }
            }
        }
        while(!st.empty()){
            ans.push({m[st.top().first],st.top().second});
            st.pop();
        }
        while(!ans.empty()){
            auto t=ans.top();
            ans.pop();
            sol.push_back(t.second);
        }
        return sol;
    }
};