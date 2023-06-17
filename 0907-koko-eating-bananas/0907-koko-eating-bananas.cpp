class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
    
        long long int start=1;
        long long int end=-1;
        
        for(int i=0;i<n;i++){
            if(piles[i]>end){
                end=piles[i];
            }
        }
        
        while(start<=end){
            // vector<int> newpiles;
            long long int hours=0;
            long long int mid=start+ (end-start)/2;
            for (int i = 0; i < n; i++) {
                hours += (piles[i]+mid-1) / mid;  
            }
            if (hours <= h) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
            

        }
        return start;

    }
};



// for(int i=0;i<n;i++){
//                 if(piles[i]<=mid){
//                     newh--;
//                 }
//                 else{
//                     newpiles.push_back(piles[i]);
//                 }
//             }
            
//             for(int i=0;i<newpiles.size();i++){
//               while(newpiles[i]>0){
//                 newpiles[i]=newpiles[i]-mid;
//                 newh--;
//               }
//             }
//             if(newh==0){
//                 return mid;
//             }
//             else if(newh<0){
//                 start=mid+1;
//             }
//             else{
//                 ans=mid;
//                 end=mid-1;
//             }