class Solution {
public:
    int maxScore(vector<int>& card, int k) {
      int n=card.size();
        int msum,sum,temp;
        for(int i=0;i<n-k;i++){
            msum+=card[i];
        }
        sum=temp=msum;
        for(int i=n-k;i<n;i++){
            sum+=card[i];
            msum=min(msum,(temp-card[i-n+k]+card[i]));
            temp=(temp-card[i-n+k]+card[i]);
        }
        return sum-msum;
//          int res = 0;
//         for(int i=0;i<k;i++) res+=card[i];
//         int curr=res;
//         for(int i=k-1;i>=0;i--) {
//             curr-=card[i];
//             curr+=card[card.size()-k+i];
// 			res = max(res, curr);
//         }
        
//         return res;
    }
};
// mtd 1->can be converted to contig array sum 
//-sliding window->we need to check max window made by of first/last k elements