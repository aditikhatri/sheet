class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>v(256,-1);
        int l=0,r=0,len=0;
        int n=s.size();
        while(r<n){
           if(v[s[r]]!=-1) l=max(l,v[s[r]]+1);
            v[s[r]]=r;
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};