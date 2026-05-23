class CountSquares {
public:
    unordered_map<string,int> umap;
    vector<vector<int>> pts;
    int max_x, max_y;
    CountSquares() {
    }

    string getKey(int x, int y){
        return to_string(x) + to_string(y);
    }
    
    void add(vector<int> point) {
        string key = to_string(point[0]) + to_string(point[1]);
        umap[key]++;
        pts.push_back(point);
    }
    
    int count(vector<int> point) {
        int res = 0;
        for(vector<int> v : pts){
            if(v[0] == point[0] && v[1] == point[1]) continue;
            if(abs(v[0] - point[0]) == abs(v[1]-point[1])){
                res += (umap[getKey(v[0], point[1])] * umap[getKey(point[0], v[1])]);
            }
        }
        return res;
    }
};
