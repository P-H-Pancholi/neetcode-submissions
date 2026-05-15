class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> res(3, false);
        for(vector<int> v : triplets){
            if(target[0] == v[0] && target[1] >= v[1] && target[2] >= v[2]) res[0] = true;
            if(target[1] == v[1] && target[0] >= v[0] && target[2] >= v[2] ) res[1] = true;
            if(target[2] == v[2] && target[0] >= v[0] && target[1] >= v[1]) res[2] = true;
        }
        return res[0] && res[1] && res[2];
    }
};
