class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target){
                int store=mid;
                // ans.push_back(mid);
                while(mid>=0 && nums[mid]==target){
                    ans.push_back(mid);
                    mid--;             
                }
                mid=store+1;
                while(mid<nums.size() && nums[mid]==target){
                    ans.push_back(mid);
                    mid++;       
                }
                break;
            }
            //right half sorted
            if(nums[start]>nums[mid]){
                if(target>nums[mid] && target<=nums[end]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            //left half sorted
            else{
                if(target<nums[mid] && target>=nums[start]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else if(ans.size()==1){
            ans.push_back(ans[0]);
        }
        else if(ans.size()>2){
            vector<int> final;
            final.push_back(ans[0]);
            final.push_back(ans[ans.size()-1]);
            return final;
        }
        return ans;
    }
};