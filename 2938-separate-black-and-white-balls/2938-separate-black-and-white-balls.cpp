class Solution {
public:
    long long minimumSteps(string s) {
        long long res=0;
        int i=0,j=1;
        while(i<s.size() and j<s.size()){
            if(s[i]=='0'){
                i++;
                if(j<i){
                    j++;
                }
                continue;
            }
            while(j<s.size() and s[j]=='1'){
                j++;
            }
            if(j>i and j!=s.size()){
                swap(s[i],s[j]);
                res+=(j-i);
            }
            i++;
            j++;
        }
        return res;
    }
};