class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int left=0;
        int right=0;
        int count=0;
        unordered_map<char,int> mp;

        while(right<s.length()){
            
            mp[s[right]]++;

            // if(mp['a']>0 && mp['b']>0 && mp['c']>0){
                while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                    count+=s.length()-right;
                    if(s[left]=='a') mp['a']--;
                    else if(s[left]=='b') mp['b']--;
                    else mp['c']--;
                    left++;
                }
            // }
            right++;     
        }
        return count;

}
};