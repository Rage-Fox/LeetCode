class MyCalendarTwo {
public:
    map<int,int> mpp;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mpp[start]++;
        mpp[end]--;
        int book=0,res=0;
        for(auto it:mpp){
            book+=it.second;
            res=max(res,book);
        }
        if(res<3){
            return true;
        }
        mpp[start]--;
        mpp[end]++;
        return false;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */