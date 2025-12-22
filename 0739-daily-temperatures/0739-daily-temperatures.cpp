class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(temperatures.size(),0);
        stack<int> st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() and temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            if(!st.empty() and temperatures[i]<temperatures[st.top()]){
                ans[i]=st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};