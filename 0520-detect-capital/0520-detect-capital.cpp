class Solution {
public:
    bool detectCapitalUse(string word) {
        bool all_upper=true,all_lower=true,title_case=true;
        for(int i=0;i<word.length();i++){
            if(!isupper(word[i])){
                all_upper=false;
            }
            if(!islower(word[i])){
                all_lower=false;
            }
            if(i==0){
                if(!isupper(word[i])){
                    title_case=false;
                }
            }
            else{
                if(!islower(word[i])){
                    title_case=false;
                }
            }
        }
        return all_upper || all_lower || title_case;
    }
};