//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
         unordered_map<char,int> mp;
         int left=0;
         int n=s.length();
         int maxans=-1;
         
         for(int right=0;right<n;right++){
             
             mp[s[right]]+=1;
             
             while(mp.size()>k){
                mp[s[left]]--;
                if(mp[s[left]]==0){
                    mp.erase(s[left]);
                }
                left++;
             }
             
             if(mp.size()==k){
                 maxans= max(maxans, right-left+1);
             }
             
         }
         return maxans;
     
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends