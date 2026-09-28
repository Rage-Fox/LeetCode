class Solution {
public:
    int maxDepth(string s) {
        int max=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                c++;
                if(c>max){
                    max=c;
                }
            }
            else if(s[i]==')'){
                c--;
            }
        }
        return max;
    }
};