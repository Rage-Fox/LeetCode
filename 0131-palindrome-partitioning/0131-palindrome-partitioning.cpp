class Solution {
public:
    bool isPalindrome(string t){
        int i=0,j=t.size()-1;
        while(i<j){
            if(t[i]!=t[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> ans;
    void dfs(vector<string> &cur,string s,int idx){
        if(idx==s.length()){
            ans.push_back(cur);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(isPalindrome(s.substr(idx,i-idx+1))){
                cur.push_back(s.substr(idx,i-idx+1));
                dfs(cur,s,i+1);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        dfs(cur,s,0);
        return ans;
    }
};