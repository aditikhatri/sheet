class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                calldfs(grid,i,j);
                count++;
                }
            }
        }
        return count;
    }
    void calldfs(vector<vector<char>>& grid,int i,int j ){
        if(i<0||i>=grid.size()||j<0||j>=grid[i].size()|| grid[i][j]=='0'){
            return ; 
        }
     grid[i][j]= '0';
       calldfs (grid,i+1,j);
       calldfs (grid,i-1,j);
       calldfs (grid,i,j+1);
       calldfs (grid,i,j-1);

    }
};