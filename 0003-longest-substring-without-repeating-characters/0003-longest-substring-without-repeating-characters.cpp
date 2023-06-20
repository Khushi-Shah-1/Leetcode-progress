class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> setnew;
        int left=0;
        int maxans=0;

        for(int r=0;r<s.length();r++){

            if(setnew.find(s[r])!=setnew.end()){
               while(left<r && setnew.find(s[r])!=setnew.end()){
                   setnew.erase(s[left]);
                   left++;
               }
            }
            setnew.insert(s[r]);
            maxans= max(maxans, r-left+1);
        }

        return maxans;
    }
};