class Solution {
public:
    int res=0;
    void merge(vector<int> &arr,int l,int m,int r){
        int i=l,j=m+1;
        for(int k=l;k<=m;k++){
            while(j<=r and arr[k]>2LL*arr[j]){
                j++;
            }
            res+=(j-m-1);
        }
        int temp[r+1];
        int k=l;
        i=l;
        j=m+1;
        while(i<=m and j<=r){
            if(arr[i]<arr[j]){
                temp[k++]=arr[i++];
            }
            else{
                temp[k++]=arr[j++];
            }
        }
        while(i<=m){
            temp[k++]=arr[i++];
        }
        while(j<=r){
            temp[k++]=arr[j++];
        }
        for(i=l;i<=r;i++){
            arr[i]=temp[i];
        }
        return;
    }
    void mergesort(vector<int> &arr,int l,int r){
        if(l>=r){
            return;
        }
        int m=(l+(r-l)/2);
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return res;
    }
};