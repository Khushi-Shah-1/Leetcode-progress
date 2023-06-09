class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int start=0;
        int end=n-1;
        while(start<m && end>=0){
            if(matrix[start][end]==target){
                return true;
            }
            else if(matrix[start][end]>target){
                end--;
            }
            else{
                start++;
            }
        }
        return false;
    }
};