class Solution {
public:
    // int f(int i,int j, int n, vector<vector<int>>& triangle,  vector<vector<int>> &dp){
    //     if(i>=n || j>=n || i<0 || j<0) return 1e9;
    //     if(i==(n-1)) {
    //         return triangle[i][j];
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int first= triangle[i][j]+ f(i+1,j,n,triangle,dp);
    //     int second= triangle[i][j]+f(i+1,j+1,n,triangle,dp);
    //     int third= triangle[i][j] + f(i+1,j-1,n,triangle,dp);

    //     return dp[i][j]=min(min(first,second),third);
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++){
           dp[0][i]=matrix[0][i];
           ans= min(ans,dp[n-1][i]);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int first= matrix[i][j]+ dp[i-1][j];
                int second = (j < n-1) ? (matrix[i][j] + dp[i-1][j+1]) : 1e9;
                int third= (j>=1) ? (matrix[i][j] + dp[i-1][j-1]): 1e9;
                dp[i][j]=min(min(first,second),third);
                ans= min(ans,dp[n-1][j]);
            }    
        }

        return ans;
        
    }
};