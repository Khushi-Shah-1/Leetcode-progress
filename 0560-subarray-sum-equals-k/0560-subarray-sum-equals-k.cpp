class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
      int n=nums.size();
      //mapping prefix sum and count
      unordered_map<int,int> mp;
      mp[0]=1;
      int presum=0;
      int count=0;

      for(int i=0;i<n;i++){
        presum+=nums[i];

        if(mp.find(presum-k)!=mp.end()){
            count+=mp[presum-k];
        }
        mp[presum]++;
      }
      return count;
         

    }
};