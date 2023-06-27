//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
         vector<long long int> res;
         long long int count=0;
         long long int ans=Arr[0];
         for(int i=1;i<N;i++){
             ans= ans^Arr[i];
         }
         
         //check which bit is set
         while(ans){
             if(ans & 1) break;
             count++;
             ans= ans>>1;
         }
         
         long long int XOR2=0;
         long long int XOR3=0;
         
         for(int i=0;i<N;i++){
             if(Arr[i] & (1<<count)){
                 XOR2=XOR2^Arr[i];
             }
             else{
                 XOR3=XOR3^Arr[i];
             }
         }
         if(XOR3>XOR2){
             res.push_back(XOR3);
             res.push_back(XOR2);
             return res;
         }
         res.push_back(XOR2);
         res.push_back(XOR3);        
         return res;
         
         
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends