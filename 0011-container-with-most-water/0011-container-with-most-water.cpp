class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,maxx=INT_MIN;
        while(i<j){
            maxx=max(maxx,min(height[i],height[j])*(j-i));
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxx;
    }
};