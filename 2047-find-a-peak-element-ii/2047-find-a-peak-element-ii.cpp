class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m= mat.size();
        int n=mat[0].size();
        vector<int> ans;

        int start=0;
        int end=n-1;

        while(start>=0 && start<m && end>=0 && end<n){
            int up= start-1<0 ?-1: mat[start-1][end];
            int down=start+1>=m?-1:mat[start+1][end];
            int left=end-1<0?-1:mat[start][end-1];
            int right=end+1>=n?-1:mat[start][end+1];

            int element=mat[start][end];
            if(element>up && element>down && element>left && element>right){
                ans.push_back(start);
                ans.push_back(end);
                return ans;
            }

            int maximum=max({up,down,left,right});
            if(up==maximum) start--;
            else if(down==maximum) start++;
            else if(left==maximum) end--;
            else if(right==maximum) end++;
            
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;

    }
};