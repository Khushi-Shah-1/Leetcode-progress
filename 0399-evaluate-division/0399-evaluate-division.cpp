class Solution {
public:
    bool path(int first, int second, vector<pair<int,double>>adj[],double &c,vector<bool>&vis){

        if(first==second) return true;
        vis[first]=1;
        bool ans=false;
        for(auto i:adj[first]){
            if(vis[i.first]==1) continue;
            ans=ans || path(i.first,second, adj,c,vis);
            
            if(ans){
                c=c*i.second;
                return ans;
            }
        }
        return ans;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;

        map<string,int> m;
        int assign=1;
        vector<pair<int,double>> adj[50];

        for(int i=0;i<equations.size();i++){
            string first=equations[i][0];
            string second=equations[i][1];

            if(m.find(first)==m.end()){
                m[first]=assign++;
            }
            if(m.find(second)==m.end()){
                m[second]=assign++;
            }
            
            double x=values[i];
            double y=1/values[i];
            adj[m[first]].push_back({m[second],x});
            adj[m[second]].push_back({m[first],y});
        }

        for(int i=0;i<queries.size();i++){
            string first=queries[i][0];
            string second=queries[i][1];
            
            if(m[first]==0 || m[second]==0){
               ans.push_back(-1);
               continue;
            } 

            if(first==second) {
               ans.push_back(1.0);
               continue;
            }

            double c=1.0;
            vector<bool> visited(c+1,0);
            bool x=path(m[first],m[second],adj,c,visited);
            if(x)
                ans.push_back(c);
            else
                ans.push_back(-1);

        }
        return ans;

    }
};