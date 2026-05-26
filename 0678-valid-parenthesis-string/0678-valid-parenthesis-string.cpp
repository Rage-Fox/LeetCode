class Solution {
public:
    bool checkValidString(string s) {
        stack<int> brac,star;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                brac.push(i);
            }
            else if(s[i]==')'){
                if(!brac.empty()){
                    brac.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{
                    return false;
                }
            }
            else{
                star.push(i);
            }
        }
        while(!brac.empty() and !star.empty()){
            if(brac.top()>star.top()){
                return false;
            }
            brac.pop();
            star.pop();
        }
        return brac.empty();
    }
};