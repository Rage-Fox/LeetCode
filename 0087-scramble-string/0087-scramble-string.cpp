class Solution {
public:
    unordered_map<string,bool> hmpp;
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()){
            return false;
        }
        if(s1==s2){
            return true;
        }
        if(s1.size()==0){
            return true;
        }
        int n=s1.size();
        bool flag=false;
        string key=s1+"_"+s2;
        if(hmpp.find(key)!=hmpp.end()){
            return hmpp[key];
        }
        for(int i=1;i<n;i++){
            bool case1=isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,n-i),s2.substr(i,n-i));
            bool case2=isScramble(s1.substr(0,i),s2.substr(n-i,i)) && isScramble(s1.substr(i,n-i),s2.substr(0,n-i));
            if(case1 or case2){
                flag=true;
                break;
            }
        }
        return hmpp[key]=flag;
    }
};