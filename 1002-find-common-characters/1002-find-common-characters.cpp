class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        for(char ch='a';ch<='z';ch++){
            int minCount=INT_MAX;
            for(string word:words){
                int count=0;
                for(char c:word){
                    if(c==ch){
                        count++;
                    }
                }
                minCount=min(minCount,count);
            }
            for(int i=0;i<minCount;i++){
                string str="";
                str+=ch;
                result.push_back(str);
            }
        }
        return result;
    }
};