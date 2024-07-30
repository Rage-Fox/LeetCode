class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> stack;
        int deletions=0;
        for(auto c:s){
            if(c=='b'){
                stack.push(c);
            }
            else if(c=='a'){
                if(!stack.empty()){
                    // Remove one 'b' from the stack to balance the string
                    stack.pop();
                    deletions++;
                }
            }
        }
        return deletions;
    }
};