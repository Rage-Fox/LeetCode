class Solution {
public:
    string flip(string s){
        for(int i=0;i<s.size();i++){
            s[i]=(s[i]=='1')?s[i]='0':'1';
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=1;i<=n;i++){
            string flipped=flip(s);
            reverse(flipped.begin(),flipped.end());
            s=s+'1'+flipped;
        }
        return s[k-1];
    }
};