class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
            int matrix_size=matrix.size();
    int low=matrix[0][0];
    int high=matrix[matrix_size-1][matrix_size-1];
    while(low<high)
    {
        int mid=low+(high-low)/2;
        int count=0;
        for(int i=0;i<matrix_size;i++)
        {
            count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
        
        }
        
        if(count<k)
            low=mid+1;
        else
            high=mid;
    }
    return low;

    }
};