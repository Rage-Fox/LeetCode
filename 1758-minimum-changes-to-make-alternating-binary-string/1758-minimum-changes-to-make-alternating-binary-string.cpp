class Solution {
public:
    int minOperations(string s) {
        int c=0;
        for(int i=0;i<s.size();i++){ //01010
            if(i%2==0 && s[i]!=0+'0')  c++;
            else if(i%2!=0 && s[i]!=1+'0')c++;
        }
        int p=0;
        for(int i=0;i<s.size();i++){ //101010
            if(i%2==0 && s[i]!=1+'0') p++;
            else if(i%2!=0 && s[i]!=0+'0') p++;
        }
        return min(c,p);
    }
};