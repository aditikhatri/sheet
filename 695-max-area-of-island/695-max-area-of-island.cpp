class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        int cnt = 0, ans = 0;
        queue<pair<int,int>> queue;
        int dir[4][4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        for (int i=0; i<r; ++i) {
            for (int j=0; j<c; ++j) {
                if (mat[i][j]) {
                    cnt = 0;
                    queue.push ({i,j});
                    while (! queue.empty()) {
                        int x = queue.front().first;
                        int y = queue.front().second;
                        if (x >= 0 and x < r and y >= 0 and y < c and mat[x][y]) {
                            mat[x][y] = 0;
                            ++ cnt;
                            for(auto a : dir) {
                                queue.push ({x + a[0], y + a[1]});
                            }
                        }
                        queue.pop();
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};