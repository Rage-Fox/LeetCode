class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,ans=0;
        unordered_map<char,int> mpp;
        while(r<s.size()){
            mpp[s[r]]++;
            while(mpp['a']>0 and mpp['b']>0 and mpp['c']>0){
                // if abc is valid in abcabc, then the substrings can be abc,abca,abcab,abcabc which is 4
                ans+=(s.size()-r);
                mpp[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};