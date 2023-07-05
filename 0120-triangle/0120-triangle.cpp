class Solution {
public:
    int f(int i,int j, int n, vector<vector<int>>& triangle,  vector<vector<int>> &dp){

        if(i==(n-1)) {
            return triangle[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int m=triangle[j].size();

        int first=triangle[i][j]+f(i+1,j,n,triangle,dp);
        int second=triangle[i][j]+f(i+1,j+1,n,triangle,dp);

        return dp[i][j]=min(first,second);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return f(0,0,n,triangle,dp);
    }
};