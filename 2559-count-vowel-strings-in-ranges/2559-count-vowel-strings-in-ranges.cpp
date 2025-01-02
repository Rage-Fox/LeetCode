class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        unordered_set<char> vowels{'a','e','i','o','u'};
        vector<int> presum(words.size());
        int sum=0;
        for(int i=0;i<words.size();i++){
            string word=words[i];
            if(vowels.count(word[0]) and vowels.count(word[word.size()-1])){
                sum++;
            }
            presum[i]=sum;
        }
        for(int i=0;i<queries.size();i++){
            vector<int> curr=queries[i];
            ans[i]=presum[curr[1]]-(curr[0]==0?0:presum[curr[0]-1]);
        }
        return ans;
    }
};