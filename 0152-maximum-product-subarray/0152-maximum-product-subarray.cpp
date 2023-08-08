class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int res=-1e9;
        for(int i=0;i<n;i++){
            res=max(res,nums[i]);
        }
        
        int currmax=1;
        int currmin=1;

        for(int i=0;i<n;i++){
            int ele=nums[i];
            // if(ele==0){
            //     currmax=1;
            //     currmin=1;
            //     continue;
            // }
            int temp=ele*currmax;
            currmax= max(max(ele*currmax, ele*currmin),ele);
            currmin= min(min(temp, ele*currmin),ele);

            res=max(max(res,currmax),currmin);
        }
        return res;


    }
};