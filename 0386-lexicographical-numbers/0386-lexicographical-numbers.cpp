class Solution {
public:
    vector<int> lexicalOrder(int n) {
        set<string> sett;
        vector<int> ans;
        for(int i=1;i<=n;i++){
            sett.insert(to_string(i));
        }
        for(auto it=sett.begin();it!=sett.end();it++){
            ans.push_back(stoi(*it));
        }
        return ans;
    }
};