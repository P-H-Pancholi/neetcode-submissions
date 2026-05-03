class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        pair<int,int> ps[n];
        for(int i = 0; i < n; i++){
            ps[i].first = position[i];
            ps[i].second = speed[i];
        }
        sort(ps, ps+n);
        stack<float> time;

        for(int i = 0; i < n; i++){
            float duration = (float)(target-ps[i].first)/(float)ps[i].second;
            while(!time.empty() && duration >= time.top()){
                time.pop();
            }
            time.push(duration);
        }
        return time.size();
    }
};