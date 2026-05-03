class Solution {
public:
    bool noOfHours(vector<int>& piles, int k, int h){
        int hours = 0;
        for(int i : piles){
            hours += (i/k);
            if(i%k){
                hours++;
            }
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 0, end = *max_element(piles.begin(), piles.end()), ans = 0;
        while(end >= start){
            int mid = start + ((end-start)/2);
            if(mid && noOfHours(piles, mid, h)){
                end = mid-1;
                ans = mid;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};
