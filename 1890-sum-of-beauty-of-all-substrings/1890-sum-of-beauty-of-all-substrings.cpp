class Solution {
public:
    int res(unordered_map<char,int>&mp){
    int mf=-1;
    int lf=INT_MAX;
    for(auto &it:mp){
        mf=max(mf,it.second);      
        lf=min(lf,it.second);        
    }
     return mf-lf;
}

    int beautySum(string s) {
        
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            mp[s[i]]++;
            for(int j=i+1;j<n;j++){
                mp[s[j]]++;
                ans+=res(mp);
            }
        }
        return ans;

    }
};