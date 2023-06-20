class Solution {
public:
    int characterReplacement(string nums, int k) {
        int maxans=0;
        int left=0;
        int ans=0;
        unordered_map<char,int> mp;
        

        for(int right=0;right<nums.length();right++){   
            mp[nums[right]]+=1;
            //ans is most frequent in map
            ans= max(ans, mp[nums[right]]);
            
            //if size of sliding window minus the most frequenr is greater than allowed changes then move window
            if(right-left+1-ans>k){
                mp[nums[left]]--;
                left++;
            }

            maxans= max(maxans, right-left+1);
            
        }

        return maxans;
    }
};