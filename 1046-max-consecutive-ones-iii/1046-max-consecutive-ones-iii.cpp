class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxans=0;
        int count=0;
        int left=0;
        // set<int> setnew;

        for(int right=0;right<nums.size();right++){
             
             if(nums[right]!=1){
                if(k<=0){
                  while(k<1 && left<=right){
                      if(nums[left]==0){
                          k++;
                      }
                    //   setnew.erase(nums[left]);
                      left++;
                  }
                }
                
                k--;
                         
             }
            //  setnew.insert(nums[right]);
             maxans= max(maxans, right-left+1);
            // cout<<left<<"--"<<right<<endl;
        }
        return maxans;
        
    }
};