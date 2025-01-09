class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(auto word:words){
            if(word.size()>=pref.size() and word.substr(0,pref.size())==pref){
                count++;
            }
        }
        return count;
    }
};