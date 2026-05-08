class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int l=0,r;
        unordered_map<char,int> sc,tc;
        for(char i:t){
            tc[i]++;
        }
        int minn=INT_MAX,cnt=0,minLeft=0;
        for(r=0;r<n;r++){
            char c=s[r];
            if(tc.count(c)==0){
                continue;
            }
            sc[c]++;
            if(sc[c]<=tc[c]){
                cnt++;
            }
            if(cnt==m){
                while(tc.count(s[l])==0 or sc[s[l]]>tc[s[l]]){
                    if(sc.count(s[l])!=0){
                        sc[s[l]]--;
                    }
                    l++;
                }
                if(r-l+1<minn){
                    minn=r-l+1;
                    minLeft=l;
                }
            }
        }
        if(minn==INT_MAX){
            return "";
        }
        return s.substr(minLeft,minn);
    }
};