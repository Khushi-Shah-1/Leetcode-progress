//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(int x, int y, vector<vector<int>> &m, int n, vector<vector<int>> &vis, string s, vector<string> &ans){
        if(x>n-1 || y>n-1 || x<0 || y<0) return;
        if(m[x][y]==0 || vis[x][y]==1) return;
        if(x==n-1 && y==n-1){
            ans.push_back(s);
            return;
        } 
        
        vis[x][y]=1;
        
        //Up
        dfs(x-1, y, m,n, vis, s+"U", ans);
        //Down
        dfs(x+1, y, m,n, vis, s+"D", ans);
        //Left
        dfs(x, y-1, m,n, vis, s+"L", ans);
        //Right
        dfs(x, y+1, m,n, vis, s+"R", ans);
        
        vis[x][y]=0;
        
        
        
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> vis(n, vector<int>(n,0));
        vector<string> ans;
        if(m[0][0]==0 || m[n-1][n-1]==0) return ans;
        string s="";
        
        dfs(0,0,m,n,vis,s,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends