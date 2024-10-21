class Solution {
public:
    int split(int ind,string &s,unordered_set<string> &st,string temp){
        if(ind==s.length()){
            return 0;
        }
        else{
            temp.push_back(s[ind]);
            int op1=-1,op2=-1;
            if(st.find(temp)==st.end()){
                st.insert(temp);
                op1=1+split(ind+1,s,st,"");
                st.erase(temp);
            }
            op2=split(ind+1,s,st,temp);
            return max(op1, op2);
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return split(0,s,st,"");
    }
};