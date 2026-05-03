class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int cap;
    KthLargest(int k, vector<int>& nums) {
        for(int i : nums){
            pq.push(i);
        }
        this->cap = k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > cap){
            pq.pop();
        }
        return pq.top();
    }
};
