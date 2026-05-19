class MedianFinder {
public:
    // A max-heap (small) that stores the smaller half of the numbers
    // The largest number of this half is on top
    priority_queue<int,vector<int>,less<int>> smallHeap;
    // A min-heap (large) that stores the larger half of the numbers
    // The smallest number of this half is on top
    priority_queue<int,vector<int>,greater<int>> largeHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);
        if(!largeHeap.empty() && smallHeap.top()>largeHeap.top()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        // Ensure both heaps are balanced in size (difference at most 1)
        if(smallHeap.size()>largeHeap.size()+1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(largeHeap.size()>smallHeap.size()+1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if(smallHeap.size()==largeHeap.size()){
            return (largeHeap.top()+smallHeap.top())/2.0;
        }
        else if(smallHeap.size()>largeHeap.size()){
            return smallHeap.top();
        }
        else{
            return largeHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */