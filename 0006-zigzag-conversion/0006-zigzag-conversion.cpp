class Solution {
public:
    string convert(string s, int n) {
        if(n==1){
            return s;
        }
        string ans="";
        for(int row=0;row<n;row++){
            // For each row the next chracter is at index 2*(n-1) 
            int increment=2*(n-1);
            // For first and last rows
            for(int i=row;i<s.length();i+=increment){
                ans+=s[i];
                // For middle rows there will be extra characters
                if(row>0 && row<n-1 && i+increment-2*row<s.length()){
                    ans+=s[i+increment-2*row];
                }
            }
        }
        return ans;
    }
};