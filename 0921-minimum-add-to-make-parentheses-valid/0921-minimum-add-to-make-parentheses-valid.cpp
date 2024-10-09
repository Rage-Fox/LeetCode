class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        if(n==0){
            return 0;
        }
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]==')' and !st.empty() and st.top()=='('){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};