class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        if(this->mp.find(key) == this->mp.end()){
            this->mp[key] = {{value, timestamp}};
        }else{
            this->mp[key].push_back({value, timestamp});
        }
    }
    
    string get(string key, int timestamp) {
        if(this->mp.find(key) == this->mp.end()){
            return "";
        }
        vector<pair<string,int>> curr = this->mp[key];
        int start = 0, end = curr.size()-1;
        string res = "";
        while(end >= start){
            int mid = start + ((end - start)/2);
            int curr_timestamp = curr[mid].second;
            if(curr_timestamp <= timestamp){
                res = curr[mid].first;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return res;
    }
};
