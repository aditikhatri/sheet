class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int N = nums.size();
        for(int i = 0; i < N; ++i) {
            int num = nums[i];
            if(mp.count(num) == 0) {
                mp.insert({num, i});
                continue;
            }
            if(i - mp[num] <= k)
                return true;
            mp[num] = i;
        }
        return false;
    }
};