//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    // bool isvalid(int newx,int newy, int N, vector<vector<int>> &visited){
    //     if(newx>0 && newy>0 && newx<=N && newy<=N && visited[newx][newy]==0){
    //         return true;
    //     }
    //     return false;
    // }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	   vector<vector<int>> visited(N+1, vector<int> (N+1,0));
	   queue<pair<int,int>> q;
	   int kx=KnightPos[0];
	   int ky=KnightPos[1];
	   q.push({kx, ky});
	   visited[kx][ky]=1;
	   int tx= TargetPos[0];
	   int ty= TargetPos[1];
	   
	   if(kx==tx && ky==ty) return 0;
	   vector<int> dx = {-2, -2, 2, 2, -1, -1, 1, 1};
       vector<int> dy = {-1, 1, -1, 1, 2, -2, 2, -2};
	   
	   while(!q.empty()){
	       pair<int,int> initial = q.front();
	       int ix= initial.first;
	       int iy= initial.second;
	       q.pop();
	       for(int dir=0;dir<8;dir++){
	           int newx= ix+ dx[dir];
	           int newy= iy+ dy[dir];
	           
	           if(newx>0 && newy>0 && newx<=N && newy<=N && visited[newx][newy]==0){
	               q.push({newx,newy});
	               visited[newx][newy]= visited[ix][iy]+1;
	               if(newx== tx && newy==ty) {
            	       return visited[newx][newy]-1;
            	   }
	           }
	       }
	       
	   }
	   return -1;
	   
	   
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends