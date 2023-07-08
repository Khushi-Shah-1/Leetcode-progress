class Solution {
public:
    string intToRoman(int num) {
        
        string ans;
        vector<int> nums={1, 4, 5, 9, 10, 40, 50, 90, 100,400,500,900,1000};
        vector<string> vals = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD","D", "CM", "M"};

        int i=12;
        while(i>=0 && num>0){       
            while(num>=nums[i]){
                ans+=vals[i];
                num-=nums[i];
            }
            i--;               
        }

        return ans;


    }
};