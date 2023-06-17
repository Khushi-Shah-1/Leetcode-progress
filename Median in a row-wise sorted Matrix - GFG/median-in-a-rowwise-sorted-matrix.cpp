//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countsmallerthanmid(vector<int> &row, int mid){
        int start=0;
        int end=row.size()-1;
        while(start<=end){
            int newmid= start+(end-start)/2;
            if(row[newmid]<=mid){
                start=newmid+1;
            }
            else{
                end=newmid-1;
            }
        }
        return start;
    }

    int median(vector<vector<int>> &matrix, int R, int C){
        int lowest=INT_MAX;
        for(int i=0;i<R;i++){
            if(matrix[i][0]<lowest){
                lowest=matrix[i][0];
            }
        }      
        int highest=INT_MIN;
        for(int i=0;i<R;i++){
            if(matrix[i][C-1]>highest){
                highest=matrix[i][C-1];
            }
        } 
        
        while(lowest<=highest){
            int mid=lowest+ (highest-lowest)/2;
            
            int count=0;
            for(int i=0;i<R;i++){
                count+=countsmallerthanmid(matrix[i], mid);
            }
            
            if(count<= (R*C)/2){
                lowest=mid+1;
            }
            else{
                highest=mid-1;
            }
        }
        return lowest;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends