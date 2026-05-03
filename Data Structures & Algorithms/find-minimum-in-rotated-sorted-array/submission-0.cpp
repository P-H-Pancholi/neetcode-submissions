class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = INT_MAX, start = 0, end = nums.size()-1;
        while(end >= start){
            int mid = start + ((end-start)/2);
            res = min(res, nums[mid]);
            if(nums[mid] >= nums[start]){
                if(nums[end] >= nums[mid]){
                    end = mid-1;
                }else{
                    start = mid+1;
                }
            }else{
                end = mid-1;
            }
        }
        return res;
    }
};
