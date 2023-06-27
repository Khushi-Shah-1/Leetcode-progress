class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       int n=nums.size();
       vector<vector<int>> output;
       for(int num=0;num<= ((1<<n)-1);num++){
           vector<int> res;
           for(int bit=0;bit<=n-1;bit++){
               if(num & (1<<bit)){
                   res.push_back(nums[bit]);
               }
           }
           output.push_back(res);
       }

       return output;
    }
};