class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        result.push_back({intervals[0][0], intervals[0][1]});
            
        int i=1;
        while(i<n){        
            int start1= result.back()[0];
            int end1= result.back()[1];

            int start2= intervals[i][0];
            int end2= intervals[i][1];
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