class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int op1,op2;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                op1=st.top();
                st.pop();
                op2=st.top();
                st.pop();
                st.push(op2+op1);
            }
            else if(tokens[i]=="-"){
                op1=st.top();
                st.pop();
                op2=st.top();
                st.pop();
                st.push(op2-op1);
            }
            else if(tokens[i]=="*"){
                op1=st.top();
                st.pop();
                op2=st.top();
                st.pop();
                st.push(op2*op1);
            }
            else if(tokens[i]=="/"){
                op1=st.top();
                st.pop();
                op2=st.top();
                st.pop();
                st.push(op2/op1);
            }
            else{
                st.push(stoll(tokens[i]));
            }
        }
        return st.top();
    }
};