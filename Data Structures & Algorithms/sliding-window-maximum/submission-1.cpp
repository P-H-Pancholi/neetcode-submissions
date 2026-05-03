class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            while(!q.empty() && q.back() < nums[i]){
                q.pop_back();
            }
            q.push_back(nums[i]);
            if(i >= k-1){
                res.push_back(q.front());
                if(!q.empty() && q.front() == nums[i-(k-1)]){
                    q.pop_front();
                }
            }
        }
        return res;
    }
};
