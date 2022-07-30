class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>&B) {
      vector<string>ans;
        vector<int>target(26);
        for(auto i:B){
            vector<int>temp(26);
            for(auto c: i)
                temp[c-'a']++;
            for(int k=0;k<26;k++){
                target[k]=max(target[k],temp[k]);
            }
        }
            for(auto i:A){
            if(subset(i,target)){
                ans.push_back(i);
            }
        }
        return ans;
    }
    bool subset(string word ,vector<int> freq){
        for (auto i:word){
            if(freq[i-'a']!=0)freq[i-'a']--;
        }
        for(int i=0;i<26;i++){
            if(freq[i]>0) return false;
        }
        return true;
    }
};