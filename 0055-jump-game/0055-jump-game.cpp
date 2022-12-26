class Solution {
public:
    bool canJump(vector<int>& nums) {
        //traverse from last
        int n=nums.size();
        int lastindex=n-1;
        for(int i=n-1;i>=0;i--){
            if(i+nums[i]>=lastindex){
                lastindex=i;
            }
        }
        return lastindex==0;
    }
};