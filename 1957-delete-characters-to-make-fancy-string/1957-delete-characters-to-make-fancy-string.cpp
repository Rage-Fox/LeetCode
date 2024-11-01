class Solution {
public:
    string makeFancyString(string s) {
        int count=1;
        int n=s.size();
        string res="";
        res+=s[0];
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else count=1;
            if(count>=3){
                continue;
            }
            res+=s[i];
        }
        return res;
    }
};