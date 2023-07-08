class Solution {
public:
    string intToRoman(int num) {
        
        string ans;
        unordered_map<int,string> m;
        vector<int> nums={1, 4, 5, 9, 10, 40, 50, 90, 100,400,500,900,1000};
        vector<string> vals = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD","D", "CM", "M"};

        for(int i=0;i<12;i++){
             m[nums[i]]=vals[i];
        }

        int i=12;
        while(i>=0 && num>0){       
            while(num>=nums[i]){
                ans+=vals[i];
                num-=nums[i];
            }
            i--;               
        }
        // while(i==0 && num>0){
        //     ans+=vals[0];
        //     num--;
        // }
        return ans;


    }
};