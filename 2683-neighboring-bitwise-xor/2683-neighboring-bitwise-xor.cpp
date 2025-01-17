class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // The xor-sum of the derived array should be 0 since there is always a duplicate occurrence of each element.
        /*
        derived[0] = original[0] XOR original[1]
        derived[1] = original[1] XOR original[2]
        derived[2] = original[2] XOR original[3]
        derived[3] = original[3] XOR original[4]
        ...
        derived[n-1] = original[n-1] XOR original[0]
        */
        int XOR=0;
        for(auto ele:derived){
            XOR=XOR^ele;
        }
        return (XOR==0);
    }
};