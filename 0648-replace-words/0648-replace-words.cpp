class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans="";
        for(int i=0;i<sentence.size();i++){
            string temp="";
            while(i<sentence.size() && sentence[i]!=' '){
                temp+=sentence[i];
                i++;
            }
            for(auto it:dictionary){
                if(it.size()<=temp.size() && it==temp.substr(0,it.size())){
                    temp=it;
                }
            }
            ans+=temp;
            if(i<sentence.size()-1){
                ans+=' ';
            }
        }
        return ans;
    }
};