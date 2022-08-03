class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

    int i = 0, res = 0;
    
    for(int j=0; j<nums.size(); j++)
    {
        if(nums[j] == 0)
        {
            k--;
        }
        
        while(k < 0)
        {
            if(nums[i] == 0)
            {
                k++;
            }
            
            i++;
        }
        
        res = max(res, j-i+1);
    }
    
    return res;
    

    }
};