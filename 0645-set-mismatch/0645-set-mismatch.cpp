class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum=0,x=0;
        vector<int> v;
        x=(nums.size()*(nums.size()+1))/2;
        int n=nums.size()+1;
        int *p=new int[n];
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        for(int i=0;i<n;i++)
            p[i]=0;
        for(int i=0;i<nums.size();i++)
            p[nums[i]]++;
        for(int i=0;i<n;i++)
        {
            if(p[i]==2)
            {
                v.push_back(i);
                sum-=i;
                break;
            }
        }
        v.push_back(x-sum);
        return v;
        
    }
};