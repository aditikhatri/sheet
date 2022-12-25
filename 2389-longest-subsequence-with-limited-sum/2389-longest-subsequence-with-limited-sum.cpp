class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        sort(nums.begin(),nums.end());
        
        vector<int>prefix(n);
        int res=0;
        for(int i=0;i<n;i++){
            res+=nums[i];
            prefix[i]=res;
        }
        vector<int>ans;
        for(int i=0;i<m;i++){
            int query=queries[i];
            ans.push_back(upper_bound(prefix.begin(),prefix.end(),query)-prefix.begin());
        }
        return ans;
    }
};