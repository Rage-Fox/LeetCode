class Solution {
public:
    double angleClock(int hour, int minutes) {
        // https://leetcode.com/problems/angle-between-hands-of-a-clock/solutions/8340833/0ms-beats-10000-easy-approach-and-step-b-bied
        // angle in 1 minute = 360/60 = 6 degree
        // angle in 1 hour = 360/12 = 30 degree
        // The hour hand also moves 0.5° every minute
        hour %= 12;
        double minuteAngle = minutes * 6.0;
        double hourAngle = hour * 30.0 + minutes * 0.5;
        double diff = abs(hourAngle - minuteAngle);
        return min(diff, 360.0 - diff);
    }
};