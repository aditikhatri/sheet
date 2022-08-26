class Solution {
public:
    bool reorderedPowerOf2(int n) {
       if (n==1 || n==2) return true;
        string nums =to_string(n);
        sort(nums.begin(), nums.end());
        
        for (int64_t i = 2; i < 1e+10; i *= 2) {
            string num = to_string(i);
            sort(num.begin(), num.end());
            if (nums == num) return true;
        }
        return false;
    }
};