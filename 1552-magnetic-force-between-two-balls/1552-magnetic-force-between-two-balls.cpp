class Solution {
public:
    bool possibleToPut(vector<int> &position,int mid,int n,int m){
        int ballsPut=1,lastPutPos=position[0];
        for(int i=1;i<n;i++){
            if((position[i]-lastPutPos)>=mid){
                ballsPut++;
                lastPutPos=position[i];
                if(ballsPut>=m)
                    return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int> &position,int m){
        sort(position.begin(),position.end());
        int n=position.size();
        int l=1,h=(position[n-1]-position[0]);
        while(l<=h){
            int mid=l+(h-l)/2;
            if(possibleToPut(position,mid,n,m)){
                l=mid+1;
            }
            else
                h=mid-1;
        }
        return h;
    }
};