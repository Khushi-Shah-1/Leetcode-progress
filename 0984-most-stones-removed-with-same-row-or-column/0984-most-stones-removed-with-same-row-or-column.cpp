class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &visited){
        visited[node]=1;
        for(auto nei: adj[node]){
            if(!visited[nei]){
                dfs(nei,adj,visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {

        int n=stones.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && (stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                ans++;
            }
        }
        return n-ans;
    }
};