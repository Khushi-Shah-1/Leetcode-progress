//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool canplace(int A[], int &mid, int &N, int &M){
        int count=1;
        int pages=0;
        
        for(int i=0;i<N;i++){
            if(A[i]>mid) return false;
            if(A[i]+pages> mid){
                count+=1;
                pages=A[i];
               
            }
            else{
                pages+=A[i];
            }
        }
        
        if(count>M) return false;
        
        return true;
    }
      
        
        
    
    
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
        
        int start=A[0];
        int end=0;
        int res=0;
        for(int i=0;i<N;i++){
            end+=A[i];
        }
        
        while(start<=end){
            int mid= start+(end-start)/2;
            
            int answer=canplace(A,mid,N,M);
            
            if(!answer){
                start=mid+1;
            }
            else{
                res=mid;
                end=mid-1;
            }


        }
        return res;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends