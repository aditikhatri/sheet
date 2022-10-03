class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        map<string, vector<string>>mp;
        for(int i=0;i<str.size();i++){
            string s=str[i];
            sort(s.begin(),s.end());// sort individual word
            mp[s].push_back(str[i]); // key of mp is sorted ,push str in vec
        }
        vector< vector<string> > ans(mp.size());
        int idx=0;
        for( auto it :mp){
            auto v=it.second;
            for( int i=0;i<v.size();i++){
                ans[idx].push_back(v[i]);
            }
              idx++;// for second  index of vec push 2nd group
        }
        return ans;
    }
};
 // act->act,cat,tac
 // dog->god ,dog