class Solution {
public:
    int countPrimes(int n) {
        vector<long long int> prime(n+1,0);
        for(long long int i=4;i<n;i=i+2){
            prime[i]=1;
        }

        for(long long int i=3;i<n;i=i+2){
            for(long long int j=i*i;j<n;j+=i){
                prime[j]=1;
            }
        }
        int count=0;
        for(long long int i=2;i<n;i++){
            if(prime[i]==0){
            //   cout<<i<<endl;
              count+=1;
            }
        }
        return count;
    }
};