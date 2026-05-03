class Solution {
public:
    int findMax(vector<int>& nums, int start, int end){
        int maxNum = INT_MIN;
        for(int i = start; i <= end; i++){
            maxNum = max(maxNum, nums[i]);
        }
        return maxNum;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int currMax = findMax(nums, 0, k-1);
        int start = 0, end = k;
        vector<int> res;
        res.push_back(currMax);
        while(end < nums.size()){
            if(nums[end] >= currMax){
                currMax = nums[end];
            }else{
                if(nums[start] == currMax){
                    currMax = findMax(nums, start+1, end);
                }
            }
            res.push_back(currMax);
            start++;end++;
        }
        return res;
    }
};
