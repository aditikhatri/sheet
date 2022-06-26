class Solution {
public:
    int maxScore(vector<int>& card, int k) {
         int res = 0;
        for(int i=0;i<k;i++) res+=card[i];
        
        int curr=res;
        for(int i=k-1;i>=0;i--) {
            curr-=card[i];
            curr+=card[card.size()-k+i];
			res = max(res, curr);
        }
        
        return res;
    }
};