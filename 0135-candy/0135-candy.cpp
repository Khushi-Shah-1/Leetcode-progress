class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n=ratings.size();
        int candy=0;
        vector<int> assigned_left(n,1);
        vector<int> assigned_right(n,1);

        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                assigned_left[i]=assigned_left[i-1]+1;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(ratings[i+1]<ratings[i]){
                 assigned_right[i] = assigned_right[i+1] +1;
            }
        }
        for(int i=0;i<n;i++){
            candy+=max(assigned_left[i], assigned_right[i]);
        }
        return candy;

    }
};