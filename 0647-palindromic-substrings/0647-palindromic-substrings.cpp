class Solution {
public:
    int palin(string &s,int l,int r){
        int res=0;
        while(l>=0 and r<s.length() and s[l]==s[r]){
            res++;
            l--;
            r++;
        }
        return res;
    }
    int countSubstrings(string s) {
        int res=0;
        for(int i=0;i<s.length();i++){
            res+=(palin(s,i,i));
            res+=(palin(s,i,i+1));
        }
        return res;
    }
};