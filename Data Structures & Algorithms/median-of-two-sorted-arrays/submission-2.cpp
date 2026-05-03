class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        int p1 = 0, p2 = 0, i = 0;
        double res = 0;
        while(i < n){
            int a = p1 < nums1.size() ? nums1[p1] : INT_MAX;
            int b = p2 < nums2.size() ? nums2[p2] : INT_MAX;
            if(n%2 && i == n/2){
                return (double)min(a,b);
            }
            if(n%2 == 0 && i == ((n/2)-1)){
                res = (double)min(a,b);
            }
            if(n%2 == 0 && i == ((n/2))){
                res += (double)min(a,b);
                return res/2.0;
            }
            if(a < b){
                p1++;
            }else{
                p2++;
            }
            i++;
        }
        return res;
    }
};
