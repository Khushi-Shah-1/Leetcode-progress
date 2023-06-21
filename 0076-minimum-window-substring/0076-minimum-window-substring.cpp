class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty() || t.length()>s.length()) return "";

        unordered_map<char,int> T;
        unordered_map<char,int> window;
        for(int i=0;i<t.length();i++){
           T[t[i]]++;
        }
        
        int have=0;
        int need=T.size();

        int left=0;
        pair<int,int> res;
        res.first=-1;
        res.second=-1;
        int length=INT_MAX;
         
        for(int right=0;right<s.length();right++){
            char rightchar=s[right];
            window[rightchar]++;

            if(T.find(rightchar)!=T.end()){          
                 if(window[rightchar]==T[rightchar]){
                    have++;
                 }               
            }

            while(have==need){
                if(right-left+1<length){
                    res.first=left;
                    res.second=right;
                    length=right-left+1;
                }  
                window[s[left]]--;
                if(T.find(s[left])!=T.end() && window[s[left]]<T[s[left]] ){
                    have--;
                }
                left++;
            }
     
        } 
        int start=res.first;
        int end=res.second;
        if(start==-1 && end==-1) return "";
        return s.substr(start, end - start+1);
        
    
    }
};