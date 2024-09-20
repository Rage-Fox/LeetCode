class Solution {
public:
    string shortestPalindrome(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        // String View is a non-owning, read-only pointer to a char array, one that also tracks the length of the pointed array and behaves as a string.
        string_view ht(t),hs(s);
        for(int i=0;i<s.length();i++){
            if(ht.substr(i,ht.length())==hs.substr(0,hs.length()-i)){
                return t.substr(0,i)+s;
            }
        }
        return t+s;
    }
};