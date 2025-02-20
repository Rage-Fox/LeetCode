class Solution {
public:
    bool solve(string &output,int size,vector<string> &nums){
        if(size==0){
            auto it = find(nums.begin(),nums.end(),output);
            if(it==nums.end()){
                return true;
            }
            return false;
        }
        output.push_back('1');
        if(solve(output,size-1,nums)==true) return true;
        output.pop_back();
        output.push_back('0');
        if(solve(output,size-1,nums)==true) return true;
        output.pop_back();
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string output;
        int size = nums[0].length();
        solve(output,size,nums);
        return output;
    }
};