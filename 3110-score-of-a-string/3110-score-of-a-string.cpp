class Solution {
public:
    int scoreOfString(string s) {
        int hscore=0;
        for(int i=0;i<s.size()-1;i++){
            hscore+=(abs(s[i]-s[i+1]));
        }
        return hscore;
    }
};