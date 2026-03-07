class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        string s2=s+s;
        int diff1=0,diff2=0;
        int res=n;
        for(int i=0;i<s2.size();i++){
            char expected1=(i%2)?'1':'0';
            char expected2=(i%2)?'0':'1';
            if(s2[i]!=expected1){
                diff1++;
            }
            if(s2[i]!=expected2){
                diff2++;
            }
            if(i>=n){
                char prev1=((i-n)%2)?'1':'0';
                char prev2=((i-n)%2)?'0':'1';
                if(s2[i-n]!=prev1){
                    diff1--;
                }
                if(s2[i-n]!=prev2){
                    diff2--;
                }
            }
            if(i>=n-1){
                res=min(res,min(diff1,diff2));
            }
        }
        return res;
    }
};