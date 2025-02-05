class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diffIndices;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                diffIndices.push_back(i);
            }
        }
        return diffIndices.empty() or (diffIndices.size()==2 and s1[diffIndices[0]]==s2[diffIndices[1]] and s1[diffIndices[1]]==s2[diffIndices[0]]);
    }
};