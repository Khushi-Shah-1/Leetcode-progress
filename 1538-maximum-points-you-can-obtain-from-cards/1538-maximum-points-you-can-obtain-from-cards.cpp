class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size()-1;
        int left=0;
        
        int sum=0;
        int maxans=0;
        int right=n-k;
        for(int i=0;i<left;i++){
           sum+=cardPoints[i];
        }
        for(int i=right+1;i<=n;i++){
           sum+=cardPoints[i];
        }
        maxans= max(maxans,sum);
        while(right<n){     
            //  cout<<sum<<endl;           
             
             right++;
             sum=sum-cardPoints[right]+cardPoints[left];
             left++;
             maxans= max(maxans,sum);

        }
        return maxans;
    }
};