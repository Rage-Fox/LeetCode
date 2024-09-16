class Solution {
public:
    int timeToMinutes(string time){
        int hour=stoi(time.substr(0,2));
        int minute=stoi(time.substr(3,5));
        return hour*60+minute;
    }
    int findMinDifference(vector<string>& timePoints) {
        int ans=INT_MAX;
        vector<int> minutes;
        for(string time:timePoints) {
            minutes.push_back(timeToMinutes(time));
        }
        sort(minutes.begin(),minutes.end());
        for(int i=1;i<minutes.size();i++){
            ans=min(ans,minutes[i]-minutes[i-1]);
        }
        // Between first and last time points (1440 Mins=24 Hrs)
        ans=min(ans,1440+minutes[0]-minutes.back());
        return ans;
    }
};