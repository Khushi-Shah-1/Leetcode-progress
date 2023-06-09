class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid= (start+end)/2;
            if(nums[mid]==target) return true;
            cout<<mid<<endl;
            //right half sorted
            if(nums[start]>nums[mid]){
                if(nums[mid]<target && nums[end]>=target){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            else if(nums[start]==nums[mid] && nums[mid]==nums[end]){
                start=start+1;
                end=end-1;
            }
            else{
                if(nums[mid]>target && nums[start]<=target){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
        }
        return false;
    }
};