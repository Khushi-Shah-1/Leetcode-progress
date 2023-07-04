class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        int prev2=0;
        int prev1=nums[0];
        int curr1=nums[0];
        
        for(int i=1;i<n-1;i++){
            int left=nums[i]+prev2;
            int right= prev1;
            curr1=max(left,right);
            prev2=prev1;
            prev1=curr1;      
        }

        int curr2=nums[n-1];
        prev2=0;
        prev1=nums[n-1];
        for(int i=n-2;i>0;i--){
            int left=nums[i]+prev2;
            int right= prev1;
            curr2=max(left,right);
            prev2=prev1;
            prev1=curr2;      
        }

        return max(curr1,curr2);
    }
};