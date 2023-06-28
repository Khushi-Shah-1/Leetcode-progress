//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {

        vector<int> prime(N+1,-1);
        vector<int> ans;
        
        for(int i=2;i<= sqrt(N);i++){
            for(int j=i*i;j<=N;j=j+i){
                if(prime[j]==-1){
                    prime[j]=i;
                }
            }
        }
        
        while(prime[N]!=-1){
            ans.push_back(prime[N]);
            N=N/prime[N];
        }
        
        if(prime[N]==-1 && N!=1){
            ans.push_back(N);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends