class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        // Two Pointers
        int n1=str1.size(),n2=str2.size(),i=0,j=0;
        while(i<n1 and j<n2){
            // Initially equal without any increment
            if(str1[i]==str2[j]){
                i++;
                j++;
            }
            else{
                char nextChar;
                // 'z' to 'a' case
                if(str1[i]=='z'){
                    nextChar='a';
                }
                // Else, normal increment from 'a' to 'b' and so on..
                else{
                    nextChar=str1[i]+1;
                }
                if(nextChar==str2[j]){
                    i++;
                    j++;
                }
                else{
                    i++;
                }
            }
        }
        return j==n2;//Reaching end of subsequence
    }
};