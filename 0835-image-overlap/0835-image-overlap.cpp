class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> V1;
        vector<pair<int,int>> V2;
        int len1 = img1.size();
        int len2 = img2.size();
        
        for(int i=0; i<len1; i++) {
            for(int j=0; j<len2; j++) {
                if(img1[i][j] == 1)
                    V1.push_back({i, j});
                if(img2[i][j] == 1)
                    V2.push_back({i, j});
            }
        }
        
        map<pair<int, int>, int> mp;
        int ans=0;
        
        // mp<U/D, L/R>  where R & D are +ve and L & U are -ve
        for(int i=0; i<V2.size(); i++) {
            for(int j=0; j<V1.size(); j++) {
                mp[{V2[i].first-V1[j].first, V2[i].second-V1[j].second}]++;
                ans = max(ans, mp[{V2[i].first-V1[j].first, V2[i].second-V1[j].second}]);
            }
        }
        
        return ans;
    }
};