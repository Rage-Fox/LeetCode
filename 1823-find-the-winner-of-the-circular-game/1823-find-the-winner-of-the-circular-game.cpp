class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friends(n);
        for(int i=0;i<n;i++){
            friends[i]=i+1;
        }
        int current_position=0;
        while(n>1){
            current_position=(current_position+(k-1))%n;
            friends.erase(friends.begin()+current_position);
            n--;
        }
        return friends[0];
    }
};