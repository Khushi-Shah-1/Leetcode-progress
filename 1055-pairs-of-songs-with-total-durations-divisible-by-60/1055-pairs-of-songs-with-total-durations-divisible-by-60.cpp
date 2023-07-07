class Solution {
public:

    int numPairsDivisibleBy60(vector<int>& time) {
        vector<long long int> count(60,0);
        long long int result=0;
        for(int i=0;i<time.size();i++){
            count[(time[i]%60)]++;
        }

        if(count[30]>0) result+= (count[30] * (count[30] - 1)) / 2;
        if(count[0]>0) result+=(count[0] * (count[0] - 1)) / 2;
        count[30]=0;
        
        for(int i=1;i<=59;i++){
            if(count[i]>0){
                int required=60-i;
                result+=count[i]*count[required];
                
                count[i]=0;
                count[required]=0;
            }
        }
        return result;
    }
};