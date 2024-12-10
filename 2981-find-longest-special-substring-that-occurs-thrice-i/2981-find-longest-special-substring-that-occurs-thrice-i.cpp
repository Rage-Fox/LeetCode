class Solution {
public:
    bool isSpecial(string s){
        unordered_map<char,int> mpp;
        for(char c:s){
            mpp[c]++;
        }
        return mpp.size() == 1;
    }
    int maximumLength(string s) {
        unordered_map<string,int> mpp;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int len=1;i+len<=n;len++){
                string temp=s.substr(i,len);
                if(isSpecial(temp)){
                    mpp[temp]++;
                }
            }
        }
        int reslen=-1;
        for(auto it:mpp){
            if(it.second>=3){
                reslen=max(reslen,(int)it.first.size());
            }
        }
        return reslen;
    }
};