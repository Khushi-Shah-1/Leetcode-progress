//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution {
  public:
    int solve(vector<int>& bt) {
        
        int n= bt.size();
        int ans=0;
        vector<int> wait_time(n);
        
        sort(bt.begin(), bt.end());
        wait_time[0]=0;
        
        for(int i=1;i<n;i++){
            wait_time[i]=wait_time[i-1]+bt[i-1];
            ans+=wait_time[i];
        }
        
        // for(int i=0;i<n;i++){
            
        // }
        
        return ans/n;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        int ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends