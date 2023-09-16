class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() ==0)return 0;
        int n=nums.size();
        int dp[n+1];
         dp[0]=0;
         dp[1]=nums[0];
        for(int i=1;i<n;i++){
            dp[i+1]=max(dp[i],dp[i-1]+nums[i]);
        }
        return dp[n];
    }
};