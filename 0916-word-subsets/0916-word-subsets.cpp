class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int maxCount[26]={0};
        for(auto word:words2){
            int count[26]={0};
            for(char ch:word){
                count[ch-'a']++;
            }
            for(int i=0;i<26;i++){
                maxCount[i]=max(maxCount[i],count[i]);
            }
        }
        vector<string> result;
        for(auto word:words1){
            int count[26]={0};
            for(char ch:word){
                count[ch-'a']++;
            }
            bool isUniversal=true;
            for(int i=0;i<26;i++){
                if(count[i]<maxCount[i]){
                    isUniversal=false;
                    break;
                }
            }
            if(isUniversal){
                result.push_back(word);
            }
        }
        return result;
    }
};