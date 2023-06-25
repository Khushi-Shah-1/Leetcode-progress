class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans = (min(x,y)*4 + z*2);
        if(x==y){
            return ans;
        }
        else{
            return ans+2;
        }
    }
};