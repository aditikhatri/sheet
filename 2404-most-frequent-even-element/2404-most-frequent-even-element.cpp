class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
     int n=nums.size();
        int maxi=0,res=-1;
        unordered_map<int,int>hash;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                hash[nums[i]]++;
            }
        }
        //for(auto i :hash) cout<<i.first<<"->"<<i.second<<endl;
        for(auto i :hash){
            if(maxi<i.second){
                res=i.first;
                maxi=i.second;
            }
            else if(maxi==i.second && i.first<res){
                res=i.first;
            }
        }
        return res;
    }
};