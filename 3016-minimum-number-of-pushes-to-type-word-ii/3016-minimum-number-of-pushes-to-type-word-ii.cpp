class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mpp(26);
        for(char c:word){
            mpp[c-'a']++;
        }
        sort(mpp.rbegin(),mpp.rend());
        int resans=0;
        for(int i=0;i<26;i++){
            resans+=mpp[i]*(i/8+1);
        }
        return resans;
    }
};