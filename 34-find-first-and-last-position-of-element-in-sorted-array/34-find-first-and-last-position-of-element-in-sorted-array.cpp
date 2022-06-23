class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(binary_search(nums.begin(),nums.end(),target))
        {
            int pos1 = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
            int pos2 = upper_bound(nums.begin(),nums.end(),target) - nums.begin()-1;         
            return {pos1,pos2};
        }     
        return {-1,-1};
    }
};