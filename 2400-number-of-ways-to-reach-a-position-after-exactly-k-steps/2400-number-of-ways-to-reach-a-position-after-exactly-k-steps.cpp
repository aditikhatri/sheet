class Solution {
public:
    int dp[3020][1005];
    int mod= 1e9+7;
    int numberOfWays(int s, int e, int k) {
        memset(dp,-1,sizeof dp);
        return f(s,e,s,k);
    }
      int f(int s,int e,int curr,int k){
        if(k==0){
            if(curr==e) return 1;
            else return 0;
        }
        if(dp[curr+1000][k]!=-1) return dp[curr+1000][k];
        int r=f(s,e,curr+1,k-1)%mod;
        int l=f(s,e,curr-1,k-1)%mod;
        return dp[curr+1000][k]=(r+l)%mod;
    }
};