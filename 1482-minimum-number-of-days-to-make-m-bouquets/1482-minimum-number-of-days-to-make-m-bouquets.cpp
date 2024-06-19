class Solution {
private:
    bool ispossible(vector<int> &bloomDay,int n,int m,int k,int mid){
        int bouquets=0,count=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                count++;
                if(count==k){
                    count=0;
                    bouquets++;
                    if(bouquets==m){
                        return true;
                    }
                }
            }
            else{
                count=0;
            }
        }
        return false;
    }
public:
    int minDays(vector<int> &bloomDay,int m,int k){
        if(bloomDay.size()<1LL*m*k){
            return -1;
        }
        // As they need in the same order, we cannot sort it but we can binary search it like Koko Eating Bananas Question
        int n=bloomDay.size(),start=0,end=*max_element(bloomDay.begin(),bloomDay.end()),ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(ispossible(bloomDay,n,m,k,mid)){
                end=mid-1;
                ans=mid;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};