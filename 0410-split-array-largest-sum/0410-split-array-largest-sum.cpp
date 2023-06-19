class Solution {
public:
    bool canplace(vector<int>& nums, int mid, int k){
        int count=1;
        int sum=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid) return false;
            if(sum+ nums[i]>mid){
                sum=nums[i];
                count+=1;
            }
            else{
                sum+=nums[i];
            }
        }
        if(count>k) return false;
        return true;
    }

    int splitArray(vector<int>& nums, int k) {

        // sort(nums.begin(), nums.end());
        int res=0;
        int start=nums[0];
        int end= 0;
        for(int i=0;i<nums.size();i++){
            end+=nums[i];
        }

        while(start<=end){
           int mid= start+ (end-start)/2;

           if(canplace(nums,mid,k)){
               res=mid;
               end=mid-1;
           }
           else{
               start=mid+1;
           }
        }
        return res;
    }
};