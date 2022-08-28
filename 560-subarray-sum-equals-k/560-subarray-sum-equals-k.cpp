class Solution {
public:
    int subarraySum(vector<int>& num, int k) {
       int n=num.size();
        if(n==0) return 0;
        unordered_map<int,int>mp;
        int csum=0,i=0,cnt=0;
        while(i<n){
            csum+=num[i];
            if(csum==k) cnt+=1;
            if(mp.find(csum-k)!=mp.end()){
                cnt+=mp[csum-k];
            }
             mp[csum]+=1;
                i++;
            
        }
        return cnt;
    }
};