class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string ans;
        int maxl=0;
        vector<vector<int>>dp(n,vector<int>(n,0));
        //aabaa
        for(int diff=0;diff<n;diff++){
            for(int i=0,j=i+diff;j<n;j++,i++){
                if(i==j) dp[i][j]=1;
                else if(diff==1) //just check last 2 char
                    dp[i][j]=(s[i]==s[j])?2:0;
                else{
                    if(s[i]==s[j] &&dp[i+1][j-1])// use prev state
                        dp[i][j]=dp[i+1][j-1]+2;
                }
                //calc
                if(dp[i][j]){
                    if(j-i+1>maxl){
                        maxl=j-i+1;
                        ans=s.substr(i,maxl);
                    }
                }
            }
        }
        return ans;
    }
};