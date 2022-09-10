class Solution {
public:
    int dp[1001][101];
    int solve(int j, vector<int>&a, int k, bool sold){
        int n= a.size();
        if(k==0){
            return 0;
        }
        
        if(dp[j][k]!=-1) return dp[j][k];
        
        int profit= 0, maxprofit= 0;
        
        if(!sold){
            //sold
            for(int i=j ; i<n; i++){
                if((a[i]- a[j])>0){
                    profit= (a[i]- a[j])+ solve(i+1, a, k-1, true);
                }
                maxprofit= max(maxprofit, profit);
            }
        }
        else if(sold && j<n){
            //buy
            profit= solve(j, a, k, false);
            maxprofit= max(maxprofit, profit);
            profit= solve(j+1, a, k, true);
            maxprofit= max(maxprofit, profit);
        }
        return dp[j][k]= maxprofit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, prices, k, true);
    }
};