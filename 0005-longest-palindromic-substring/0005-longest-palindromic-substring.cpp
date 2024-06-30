class Solution {
public:
    int expandAroundCenter(string &s,int left,int right){
        // Left and right are the pointers initially denoting the centre of the palindrome string
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s){
        int n=s.size(),start=0,maxLen=0;
        for(int i=0;i<n;i++){
            // Check for odd length palindromes centered at i
            int len1=expandAroundCenter(s,i,i);
            // Check for even length palindromes centered between i and i+1
            int len2=expandAroundCenter(s,i,i+1);
            int len=max(len1,len2);
            if(len>maxLen){
                maxLen=len;
                // Calculate starting index based on palindrome length
                start=i-(len-1)/2;
            }
        }
        return s.substr(start,maxLen);
    }
};