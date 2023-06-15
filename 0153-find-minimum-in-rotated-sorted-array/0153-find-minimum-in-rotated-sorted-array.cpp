class Solution {
public:
    int findMin(vector<int>& nums) {
        int compare=INT_MAX;
        int start=0;
        int end=nums.size()-1;

        while(start<=end){
            int mid= (start+end)/2;
            if(nums[mid]<compare){
                compare=nums[mid];
            }
            
            //right half sorted
            if(nums[mid]<nums[start]){
               if(compare<nums[end]){
                   end=mid-1;
               }
               else{
                   start=mid+1;
               }
            }

            else{
                if(nums[start]<nums[end]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
        }
        return compare;
    }
};