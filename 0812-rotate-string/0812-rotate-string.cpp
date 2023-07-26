class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.size()!=goal.size()) return false;
        
        string news= s+s;
        if(news.find(goal)!=string::npos){
            return true;
        }
        return false;


    }
};