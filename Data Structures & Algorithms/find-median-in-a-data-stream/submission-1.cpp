class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        maxHeap.push(INT_MIN);
        minHeap.push(INT_MAX);
    }
    
    void addNum(int num) {
        if(num < maxHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }
        if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(maxHeap.size()+1 < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()){
            return ((double)(minHeap.top()+maxHeap.top()))/2.0;
        }
        if(minHeap.size() > maxHeap.size()){
            return (double)(minHeap.top());
        }
        return (double)(maxHeap.top());
    }
};
