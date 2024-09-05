class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int currsum=accumulate(rolls.begin(),rolls.end(),0),m=rolls.size();
        // Indicates the missing array/elements sum
        int missingsum=mean*(n+m)-currsum;
        if(missingsum<n or missingsum>6*n)
            return {};
        int part=missingsum/n,rem=missingsum%n;
        // Sharing all the missing sum equally
        vector<int> ans(n,part);
        // Handling remainder to all the elements equally
        for(int i=0;i<rem;i++){
            ans[i]++;
        }
        return ans;
    }
};