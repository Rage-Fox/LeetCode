class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left_count=count(moves.begin(),moves.end(),'L');
        int right_count=count(moves.begin(),moves.end(),'R');
        int rem_count=count(moves.begin(),moves.end(),'_');
        return abs(left_count-right_count)+rem_count;
    }
};