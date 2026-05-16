class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(vector<int>& v : matrix){
            int start = 0, end = n-1;
            while(end > start){
                int temp = v[end];
                v[end] = v[start];
                v[start] = temp;
                start++;
                end--;
            }
        }
    }
};
