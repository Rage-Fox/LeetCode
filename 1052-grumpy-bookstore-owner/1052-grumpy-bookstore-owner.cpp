class Solution {
public:
    int maxSatisfied(vector<int> &customers,vector<int> &grumpy,int minutes){
        int count=0; 
        for(int i=0;i<customers.size();i++){
            // Not Grumpy so we can consider the satisfaction
            if(grumpy[i]==0){
                count+=customers[i];
            }
        }
        for(int i=0;i<customers.size();i++){
            // 0*satisfaction becomes 0 which leaves us with unsatisfied customers
            customers[i]*=grumpy[i];
        }
        int maxx=0,temp=0; 
        // Calculating for the first given minutes
        for(int i=0;i<minutes;i++){
            temp+=customers[i];
            maxx=max(maxx,temp);
        }
        // Using sliding window!
        for(int i=minutes;i<customers.size();i++){
            temp-=customers[i-minutes];
            temp+=customers[i];
            maxx=max(maxx,temp);
        }
        // Returning satisfied + owner tries not to be grumpy for few minutes
        return count+maxx; 
    }
};