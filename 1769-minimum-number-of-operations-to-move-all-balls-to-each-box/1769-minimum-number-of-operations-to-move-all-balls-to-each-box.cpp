class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> res(n, 0);
        int leftball=0,leftmove=0,rightball=0,rightmove=0;
        for(int i=0;i<n;i++){
            // Left side
            res[i]+=leftmove;
            leftball+=boxes[i]-'0';
            leftmove+=leftball;
            // Right side
            int j=n-1-i;
            res[j]+=rightball;
            rightmove+=boxes[j]-'0';
            rightball+=rightmove;
        }
        return res;
    }
};