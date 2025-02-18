class Solution {
public:
    string smallestNumber(string pattern) {
        // Dry run explanation for pattern "IIIDIDDD":
        // i=0, 'I': stack = [1], -> result = "1"
        // i=1, 'I': stack = [2], -> result = "12"
        // i=2, 'I': stack = [3],  -> result = "123".. till here we poped the elements 
        // i=3, 'D': stack = [4, 5], continue
        // i=4, 'I': stack = [4, 5, 6], pop all -> result = "123654"
        // i=5, 'D': stack = [7, 8], continue
        // i=6, 'D': stack = [7, 8, 9], continue
        // i=7, 'D': stack = [7, 8, 9], continue
        // End:  -> result = "123654987"
        string result;
        stack<int> numStack;
        // Iterate through the pattern
        for(int index=0;index<=pattern.size();index++){
            // Push the next number onto the stack
            numStack.push(index+1);
            // If 'I' is encountered or we reach the end, pop all stack elements
            if(index==pattern.size() or pattern[index]=='I'){
                while(!numStack.empty()){
                    result+=to_string(numStack.top());
                    numStack.pop();
                }
            }
        }
        return result;
    }
};