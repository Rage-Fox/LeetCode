class Solution {
public:
    int ans=0;
    int possible(string &s,unordered_map<char,int> &mpp,vector<int> &score){
        int sc=0;
        for(char c:s){
            if(mpp.count(c)){
                if(mpp[c]>0){
                    sc+=score[c-'a'];
                    mpp[c]--;
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
        return sc;
    }
    void helper(int i,vector<string> &words,vector<int> &score,unordered_map<char,int> mpp,int val){
        if(i==words.size()){
            ans=max(ans,val);
            return;
        }
        helper(i+1,words,score,mpp,val);
        int s=possible(words[i],mpp,score);
        if(s>0){
            helper(i+1,words,score,mpp,val+s);
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int> mpp;
        for(char c:letters){
            mpp[c]++;
        }
        helper(0,words,score,mpp,0);
        return ans;
    }
};