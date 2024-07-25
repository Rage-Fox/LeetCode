class Solution {
public:
    void merge(vector<int> &arr,int start,int mid,int end){
        int i=start,j=mid+1;
        vector<int> v;
        while(i<=mid and j<=end){
            if(arr[i]<arr[j]){
                v.push_back(arr[i++]);
            }
            else{
                v.push_back(arr[j++]);
            }
        }
        while(i<=mid){
            v.push_back(arr[i++]);
        }
        while(j<=end){
            v.push_back(arr[j++]);
        }
        for(int i=start;i<=end;i++){
            arr[i]=v[i-start];
        }
    }
    void mergeSort(vector<int> &arr,int start,int end){
        if(end<=start)
            return;
        int mid=start+(end-start)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
    vector<int> sortArray(vector<int> &nums){
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};