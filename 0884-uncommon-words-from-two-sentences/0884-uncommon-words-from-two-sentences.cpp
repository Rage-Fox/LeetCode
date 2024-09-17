class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        string str="";
        unordered_map<string,int> mp;
        for(int i=0;i<s1.length();i++){
            if(s1[i]==' '){
                mp[str]++;
                str.clear();
            }
            else{
                str+=s1[i];
            }
        }
        mp[str]++;
        str.clear();
        for(int i=0;i<s2.length();i++){
            if(s2[i]==' '){
                mp[str]++;
                str.clear();
            }
            else{
                str+=s2[i];
            }
        }
        mp[str]++;
        str.clear();
        for(auto it:mp){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};