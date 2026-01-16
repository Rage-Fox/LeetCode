class Solution {
public:
    string maskPII(string s) {
        if(s.find('@')!=string::npos){
            string res;
            for(char &c:s){
                c=tolower(c);
            }
            int at=s.find('@');
            res+=s[0];
            res+="*****";
            res+=s[at-1];
            res+=s.substr(at);
            return res;
        } 
        else{
            string digits;
            for(char c:s){
                if(isdigit(c)){
                    digits+=c;
                }
            }
            int n=digits.size();
            string last4=digits.substr(n-4);
            int country=n-10;
            if(country==0){
                return "***-***-"+last4;
            }
            string res="+";
            for(int i=0;i<country;i++){
                res+="*";
            }
            res+="-***-***-"+last4;
            return res;
        }
    }
};