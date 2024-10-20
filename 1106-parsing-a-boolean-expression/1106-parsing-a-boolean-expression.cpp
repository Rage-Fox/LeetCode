class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(char ch:expression){
            if(ch==',' or ch=='(')
                continue;  
            if(ch=='t' or ch=='f' or ch=='!' or ch=='&' or ch=='|'){
                st.push(ch);
            }
            else if(ch==')'){
                bool hasTrue=false,hasFalse=false;
                while(st.top()!='!' and st.top()!='&' and st.top()!='|'){
                    char top=st.top();
                    st.pop();
                    if(top=='t'){
                        hasTrue=true;
                    }
                    if(top=='f'){
                        hasFalse=true;
                    }
                }
                char op=st.top();
                st.pop();
                if(op=='!'){
                    st.push(hasTrue?'f':'t');
                }
                else if(op=='&'){
                    st.push(hasFalse?'f':'t');
                }
                else{
                    st.push(hasTrue?'t':'f');
                }
            }
        }
        return st.top()=='t';
    }
};