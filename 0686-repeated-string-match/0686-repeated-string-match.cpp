class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated="";
        int cnt=0;
        while(repeated.length()<a.length()+b.length()){
            repeated+=a;
            cnt++;
            if(repeated.find(b)!=string::npos){
                return cnt;
            }
        }
        return -1;
    }
};