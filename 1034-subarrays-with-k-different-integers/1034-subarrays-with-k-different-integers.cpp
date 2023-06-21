class Solution {
public:
    long long int atmostK(vector<int>& nums, int k){
        int left=0;
        unordered_map<int, int> mp;
        int right=0;
        int count=0;

        while(right<nums.size()){
            mp[nums[right]]++;

            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }         
                left++;
            }

            count+=right-left+1;
            right++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostK(nums,k) - atmostK(nums,k-1);
    }
};