class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int count=0,n=A.size();
        vector<int> res,freq(n+1);
        for(int i=0;i<n;i++){
            count+=(++freq[A[i]]==2)+(++freq[B[i]]==2);
            res.push_back(count);
        }
        return res;
    }
};