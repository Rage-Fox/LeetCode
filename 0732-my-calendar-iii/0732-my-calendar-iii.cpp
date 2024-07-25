class MyCalendarThree {
public:
    map<int,int> mpp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mpp[startTime]++;
        mpp[endTime]--;
        int maxx=0,book=0;
        for(auto it:mpp){
            book+=it.second;
            maxx=max(maxx,book);
        }
        return maxx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */