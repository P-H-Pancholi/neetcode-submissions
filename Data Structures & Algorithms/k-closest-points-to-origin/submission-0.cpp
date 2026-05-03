class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](
            const std::pair<int,int>& a,
            const std::pair<int,int>& b) {
                double distance_a = sqrt((a.first*a.first) + (a.second*a.second));
                double distance_b = sqrt((b.first*b.first) + (b.second*b.second));
                return distance_a > distance_b; 
            };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        for(vector<int> p : points){
            pair<int,int> curr;
            cout << p[0] << " " << p[1] << endl;
            curr.first = p[0];
            curr.second = p[1];
            pq.push(curr);
        }
        vector<vector<int>> res;
        int i = 0;
        while(i < k){
            pair<int,int> curr = pq.top();
            vector<int> curr_vec(2);
            curr_vec[0] = curr.first;
            curr_vec[1] = curr.second;
            res.push_back(curr_vec);
            pq.pop();
            i++;
        }
        return res;
    }
};
