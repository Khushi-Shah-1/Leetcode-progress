class Solution {
public:
    int atmostK(vector<int>& nums, int goal){
        int left=0;
        int sum=0;
        int count=0;
        int right=0;

        while(right<nums.size()){ 
            
            sum+=nums[right++];
            while(left<right && sum>goal){
                sum-=nums[left];
                left++;
            }
            count+=right-left;

        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal==0){
             return atmostK(nums, goal);
        }
        return atmostK(nums, goal)- atmostK(nums,goal-1);
        
    }
};