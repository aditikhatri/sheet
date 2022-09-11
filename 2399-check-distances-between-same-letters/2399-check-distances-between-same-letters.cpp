class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        // vector<int>v(26);
        // for(int i=0;i<s.size();i++){
        //     int n=s[i]-'a';
        //     if(v[n]>0 && distance[n]!=i-v[n]) return false;
        //     v[n]=i+1;
        // }
        // return true;
        for(int i=0;i<s.size();i++){
            int d=distance[s[i]-'a'];
            if(i+d+1>=s.size() or s[i+d+1]!=s[i]) return false;
            distance[s[i]-'a']=-1;
        }
        return true;
    }
};