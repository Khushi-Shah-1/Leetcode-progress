class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long int n=nums.size();

        long long int start=1;
        long long int end=-1;
        long long int ans=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>end){
                end=nums[i];
            }
        }

        while(start<=end){
            long long int mid= start+(end-start)/2;
            long long int count=0;

            for(int i=0;i<n;i++){
               count+=(nums[i]+mid-1)/mid;
            }
            if(count<=threshold){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
        
    }
};