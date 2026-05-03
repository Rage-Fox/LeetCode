class Solution {
public:
    string getKey(string str){
        vector<int> count(26);
        for(int j=0;j<str.size();j++){
            count[str[j]-'a']++;
        }
        //strings with same character frequency will generate same unique key
        string key="";
        for(int i=0;i<26;i++){
            key+=","+to_string(count[i]+'a');
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(int i=0;i<strs.size();i++){
            string key=getKey(strs[i]);
            mpp[key].push_back(strs[i]);
        }
        //all the same keys will be appended into same vector showing that they're grouped anagrams        
        vector<vector<string>> result;
        for(auto &it:mpp){
            result.push_back(it.second);
        }
        return result;
    }
};