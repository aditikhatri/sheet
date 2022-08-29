class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& m, int k) {
        int row=m.size();
        int col=m[0].size();
        int maxi=INT_MIN;
        for(int i=0;i<row;i++){
            vector<int>csum(col);
            for(int j=i;j<row;j++){
                for (int c=0;c<col;c++){
                    csum[c]+=m[j][c];
                }
                maxi=max(maxi,find(csum,k));
            }
        }
        return maxi;
    }
    int find(vector<int>sum,int k){
        int res=INT_MIN;
        set<int>st;
        st.insert(0);
        int presum=0;
        for(int i=0;i<sum.size();i++){
            presum+=sum[i];
            auto it = st.lower_bound(presum-k);
            
            if(it != st.end())
                res = max(res , presum - *it);
          
            st.insert(presum);
         }
        return res;
        }
    
};