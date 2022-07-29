class Solution {
public:
    string conv(string &s)
    {
        string converted = "";
        unordered_map<char, int> m;
        int cnt = 1;
        for(auto i: s)
        {
            if(m[i] == 0){
                m[i] = cnt++;
                converted += to_string(cnt);
            }
            else{
                converted += to_string(m[i]);
            }
        }
        return converted;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        string cmp = conv(pattern);
        for(auto w: words){
            string s = conv(w);
            if(s == cmp)
                ans.push_back(w);
        }
        return ans;
    }
};
