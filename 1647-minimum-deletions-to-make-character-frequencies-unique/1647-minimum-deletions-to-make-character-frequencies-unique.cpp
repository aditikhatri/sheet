class Solution {
public:
    int minDeletions(string str) {
        int freq[26]={0};
        for(auto i:str){
            freq[i-'a']++;
        }
        unordered_set<int> s;
        int ans=0;
        for(auto i:freq){
            if(i!=0){
            if(s.find(i)==s.end())
              s.insert(i);
            else{
                int cnt=i;
                while(s.find(i)!=s.end() and i>0){
                    i--;
                }
                if(i!=0){s.insert(i);}
                ans+=cnt-i;
            }
            }
        }
        return ans;
    }
};