class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> result;
        int start= newInterval[0];
        int end= newInterval[1];
        int n=intervals.size();
 
        int i=0;

        while( i<n && intervals[i][1]<start){
            result.push_back(intervals[i]);
            i++;
        }

        //overlapping
        while(i<n && intervals[i][0]<=end){
            start= min(intervals[i][0], start);
            end= max(intervals[i][1],end);
            i++;
        }
        result.push_back({start,end});
       
        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};