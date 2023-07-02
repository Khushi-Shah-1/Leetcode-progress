class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n=intervals.size();

        if(n<2) return intervals;
        sort(intervals.begin(), intervals.end());
        int start1=intervals[0][0];
        int end1=intervals[0][1];
        int start2=intervals[1][0];
        int end2=intervals[1][1];

        if(start2>end1){
            result.push_back({start1,end1});
            result.push_back({start2,end2});
        }
        else{
            int mini= min(start1,start2);
            int maxi= max(end1,end2);
            result.push_back({mini,maxi});
        }

        int i=2;
        while(i<n){
            
            start1= result.back()[0];
            end1= result.back()[1];

            start2= intervals[i][0];
            end2= intervals[i][1];
            if(start2>end1){
                result.push_back({start2,end2});
            }
            else{
                int mini= min(start1,start2);
                int maxi= max(end1,end2);
                result.back()[0] = mini;
                result.back()[1] = maxi;
                
            }
            i++;
        }
        return result;
    }
};