class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream ss(sentence);
        string word;
        int ans=1;
        while(ss>>word) {
            if(word.substr(0,searchWord.size())==searchWord){
                return ans;
            }
            ans++;
        }
        return -1;
    }
};