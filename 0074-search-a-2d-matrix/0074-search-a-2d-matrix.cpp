class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n= arr.size();
        int m= arr[0].size();
        for(int i=0;i<n;i++){
            int start=0;
            int end=m-1;
            while(start<=end){
                int mid=(start+end)/2;
                if(target==arr[i][mid]) return true;
                // if(target>arr[i][end]){
                //     continue;
                // }
                else if(target<arr[i][mid]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }

            }
        }
        return false;
    }
};