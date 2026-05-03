class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i : stones){
            pq.push(i);
        }
        while(pq.size() > 1){
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if(x != y){
                pq.push(max(x,y) - min(x,y));
            }
        }
        return pq.size() ? pq.top() : 0;
    }
};
