class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n=s.size();
        unordered_map<char,char> mp;
        unordered_map<char,char> mp2;
        for(int i=0;i<n;i++){
            
            char sfirst=s[i];
            char tfirst=t[i];

            if(mp.find(sfirst)!=mp.end()){
                char alreadymap=mp[sfirst];
                if(alreadymap!=tfirst){
                    return false;
                }
            
            }
            if(mp2.find(tfirst)!=mp2.end()){
                char alreadymap=mp2[tfirst];
                if(alreadymap!=sfirst){
                    return false;
                }
            
            }
            else{
                mp[sfirst]=tfirst;
                mp2[tfirst]=sfirst;
            }

        }
        return true;


    }
};