class Solution {
public:
    bool checkValidString(string s) {
        int open=0;
        int stars=0;
        int used_stars=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                open++;
            }
            else if(s[i]=='*'){
                if(open>0){
                    open--;
                    used_stars++;
                }
                else{
                    stars++;
                }
            }
            else{
                if(open>0){
                    open--;
                }
                else if(stars>0){
                    stars--;
                }
                else if(used_stars>0){
                    used_stars--;
                    stars++;
                }
                else{
                    return false;
                }
            }
        }

        if(open==0) return true;
        return false;
        
    }
};