class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int i=0;
        int j=0;
        int n=nums.size();
        int maxi=0;

        while(i<n && j<n){
            if(nums[j]!=1){
                j++;
                i=j;
            }
            else{      
                maxi=max(maxi,j-i+1);      
                j++;
            }
        }
        return maxi;

    }
};