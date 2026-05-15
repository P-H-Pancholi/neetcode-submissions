class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0) {
            return false;
        }
        unordered_map<int,int> umap;
        for(int i = 0; i < hand.size(); i++){
            umap[hand[i]]++;
        }
        sort(hand.begin(), hand.end());
        for(int i = 0; i < hand.size(); i++){
            if(umap[hand[i]] > 0) {
                for(int j = 0; j < groupSize; j++){
                    umap[hand[i]+j]--;
                    if(umap[hand[i]+j] < 0){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
