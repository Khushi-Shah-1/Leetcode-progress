class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=0;
        for(int i=0;i<g.size();i++){
            int flag=0;     
            while(j!=s.size() && flag!=1){      
                if(s[j]>=g[i] ){
                    count++;
                    flag=1;
                }
                j++;
            }
        }
        return count;
    }
};