class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;

        while(end > start){
            int curr = numbers[start] + numbers[end];

            if(curr > target){
                end--;
            }else if (curr < target){
                start++;
            }else{
                return {start+1, end+1};
            }
        } 
    }
};
