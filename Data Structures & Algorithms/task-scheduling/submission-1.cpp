class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq_map;
        for(char c : tasks){
            freq_map[c]++;
        }
        priority_queue<int> pq;
        for(auto it : freq_map){
            pq.push(it.second);
        }
        queue<pair<int,int>> q;
        int time = 0;
        while(!pq.empty() || !q.empty()){
            if(!pq.empty()){
                int curr = pq.top(); pq.pop();
                curr--;
                if(curr != 0){
                    q.push({curr, time+n});   
                }
            }
            if(!q.empty() && (time == q.front().second)){
                pq.push(q.front().first);
                q.pop();
            }
            time++;
        }
        return time;
    }
};
