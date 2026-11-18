class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        // Before Transformation = source[i]+source[j]
        // After Transformation = (source[i]+source[j]-delta)+delta
        return accumulate(source.begin(), source.end(), 0LL) ==
               accumulate(target.begin(), target.end(), 0LL);
    }
};