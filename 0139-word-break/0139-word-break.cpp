class Solution {
public:
    int dp[301];
    bool solve(int i , string &s , unordered_set<string> &st){
        if(i>=s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        string temp="";
        for(int k=i;k<=s.size();k++){
            temp+=s[k];
            if(st.find(temp)!=st.end()){
                if(solve(k+1,s,st)){
                    return dp[i]=1;
                }
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,s,wordSet);
    }
};