class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int> mpp;
        for(auto &it:dictionary)
            mpp[it]++;
        int n=s.size();
        vector<int> dp(n+1,1e7);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(mpp.find(to_string(s[i-1]))!=mpp.end())
                dp[i]=dp[i-1];
            else dp[i]= 1+dp[i-1];
            string res="";
            for(int j=i;j>=1;j--){
                res=s[j-1]+res;
                if(mpp.find(res)!=mpp.end())
                    dp[i]=min(dp[i],dp[j-1]);
            }
        }
        return dp[n];
    }
};