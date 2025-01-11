class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k){
            return false;
        }
        if(s.length()==k){
            return true;
        }
        vector<int> freq(26,0);
        int oddCount=0;
        for(auto c:s){
            freq[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]%2==1){
                oddCount++;
            }
        }
        // If the number of characters that have odd counts is > k then the minimum number of palindrome strings we can construct is > k and answer is false.
        // Otherwise you can construct exactly k palindrome strings and answer is true
        return (oddCount<=k);
    }
};