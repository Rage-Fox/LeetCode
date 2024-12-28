class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>> pref(n),suff(n);
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        pref[k-1]={0,sum};
        int maxsum=sum,j1=0,j2=n-1;
        for(int i=k;i<n;i++){
            sum-=nums[j1++];
            sum+=nums[i];
            if(sum>maxsum){
                pref[i]={i-k+1,sum};
                maxsum=sum;
            }
            else{
                pref[i]=pref[i-1];
            }
        }
        sum=0;
        for(int i=n-1;i>=n-k;i--){
            sum+=nums[i];
        }
        suff[n-k]={n-k,sum};
        maxsum=sum;
        for(int i=n-k-1;i>=0;i--){
            sum-=nums[j2--];
            sum+=nums[i];
            if(sum>=maxsum){
                suff[i]={i,sum};
                maxsum=sum;
            }
            else{
                suff[i]=suff[i+1];
            }
        }
        // Building a normal prefix sum
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        vector<int> ans;
        int maxx=0;
        for(int i=k;i<n-k;i++){
            int a=pref[i-1].second;// Subarray -1
            int b=nums[i+k-1]-nums[i-1];// Subarray -2
            int c=suff[i+k].second;// Subarray -3
            if(a+b+c>maxx){
                ans.clear();
                ans={pref[i-1].first,i,suff[i+k].first};
                maxx=a+b+c;
            }
        }
        return ans;
    }
};