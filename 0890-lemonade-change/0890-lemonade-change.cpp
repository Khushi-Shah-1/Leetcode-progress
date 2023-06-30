class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]>5) return false;
        int total_5=0;
        int total_10=0;
        int total_20=0;

        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                total_5+=1;
            }

            else if(bills[i]==10){
                if(total_5>=1){
                    total_5-=1;
                    total_10+=1;
                }
                else{
                    return false;
                }
             }
            else {
                if(total_10>=1 && total_5>=1){
                    total_5-=1;
                    total_10-=1;            
                } 
                else if(total_5>=3){
                    total_5-=3;
                }  
                else{
                    return false;
                }
                total_20+=1;
             }
        }
        return true;
    }
};