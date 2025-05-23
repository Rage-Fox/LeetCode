typedef long long ll;
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int count=0;
        ll minlose=INT_MAX,sum=0;
        for(ll num:nums){
            if((num^k)>num){
                count++;
                sum+=(num^k);
            }
            else{
                sum+=num;
            }
            minlose=min(minlose,abs(num-(num^k)));
        }  
        if(count%2==0){
            return sum;
        }
        return sum-minlose;
    }
};