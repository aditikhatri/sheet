class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        
        int n = words[0].length(), ln = s.length();
        vector<int>m1(26, 0), m2(26, 0), ans;
        map<string, int>mapp;
        
        for(int i=0; i<words.size(); i++){
            string str = words[i];
            for(int j=0; j<n; j++){
                m1[str[j] - 'a']++;   // just mapping all the character from words vector
            }
            mapp[str]++; // and also store just word into map
        } 
        int k = n*words.size(); // length of the substring
        
        for(int i=0, j=0; i<ln; i++){
            m2[s[i] - 'a']++;   //putting through the every character from s into m2 map
            
            if(i+1 >= k){
                if(m1 == m2){ // if the character map same  
                    string str = "";
                    map<string, int> mapp2;
                    for(int x = i-k+1; x<i+1; x++){ 
                        str += s[x];
                        if(str.length() == n){ // then insert the word corresponding the m2 mapp with n(each word length) length
                            mapp2[str]++;
                            str.clear();
                        }
                    }
                    if(mapp == mapp2) ans.push_back(i-k+1); // then check if they are same or not
                }
                m2[s[j++] - 'a']--; // every iteration removing the first character just slide the window
            }
        }
        return ans;
    }
};