class Solution {
public:
    int possibleBouquets(vector<int>& bloomDay, int n, int k, int mid){
        long long int bouquets=0;
        long long int adjcount=0;

        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                adjcount++;
            }
            else{
                bouquets+=(adjcount/k);
                adjcount=0;
            }
        }
        bouquets+=(adjcount/k);
        return bouquets;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int n=bloomDay.size();
        // long long int news= m*k;
        // if(news >n) return -1;
        if(n < (long long)m * k)
            return -1;
        long long int start=0;
        long long int end=-1;
        long long int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(bloomDay[i]>end){
                end=bloomDay[i];
            }
        }

        while(start<=end){
            long long int mid= start+ (end-start)/2;

            long long int bouquets= possibleBouquets(bloomDay,n,k,mid);

            if(bouquets>=m){
                ans=min(ans,mid);
                end=mid-1;
            }
            else{
                start=mid+1;
            }

        }
        return ans;

    }
};