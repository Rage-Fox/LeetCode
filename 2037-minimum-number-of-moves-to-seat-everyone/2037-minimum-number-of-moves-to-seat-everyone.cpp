class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int move_count=0;
        for(int i=0;i<seats.size();i++){
            move_count+=(abs(students[i]-seats[i]));
        }
        return move_count;
    }
};