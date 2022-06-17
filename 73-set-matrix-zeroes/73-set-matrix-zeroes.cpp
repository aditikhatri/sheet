class Solution {
public:
    void force_zero(vector<vector<int>> &A,int r, int c){
        for(int i=0;i<A.size();i++){
            A[i][c]=0;
        }
        for(int i=0;i<A[0].size();i++){
            A[r][i]=0;
        }
    }
     void setZeroes(vector<vector<int>>& matrix) {
         vector<vector<int>>res=matrix;
         set<pair<int,int>>index;
         int r=matrix.size();
         int c=matrix[0].size();
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 if(matrix[i][j]==0){
                     index.insert({i,j});
                 }
             }
         }
         for(auto &it:index){
             pair<int,int>p=it;
             force_zero(res,p.first,p.second);
         }
         matrix=res;
     }
//     void setZeroes(vector<vector<int>>& matrix) {
//         int col0=1 ,row=matrix.size(),col=matrix[0].size();
        
//         for(int i=0;i<row;i++){
//             if(matrix[i][0]==0) col0=0;
//             for(int j=1;j<col;j++){
//                 if(matrix[i][j]==0)
//                     matrix[i][0]=matrix[0][j]=0;
//             }
//         }
//         for(int i=row-1;i>=0;i--){
//             for(int j=col-1;j>=1;j--){
//                 if(matrix[i][0]==0 || matrix[0][j]==0)
//                     matrix[i][j]=0;
//             }
//             if(col0==0) matrix[i][0]=0;
//         }
//    }
};