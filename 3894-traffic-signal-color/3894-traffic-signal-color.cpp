class Solution {
public:
    string trafficSignal(int timer) {
        return (timer==0)?"Green":((timer==30)?"Orange":((timer>30 and timer<=90)?"Red":"Invalid"));
    }
};