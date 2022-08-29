class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        // extend the size of nums1 to m+n to fill at last
        while(i>=0 &&j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else{
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
        while(i>=0){
            nums1[k]=nums1[i];
            k--;i--;
        }
        while(j>=0){
            nums1[k]=nums2[j];
            k--;j--;
        }
    }
};


      // int j=0,i=0;
      // for(int i=m;i<m+n;i++,j++)
      //     nums1[i]=nums2[j];
      // int gap=ceil((m+n)/2);
      // while(gap>=1)
      // {
      //    i=0,j=i+gap;
      //   while(j<(m+n)) 
      //   {
      //     if(nums1[i]>nums1[j]) 
      //         swap(nums1[i],nums1[j]);
      //       i++;
      //       j++;
      //   }
      //   if(gap==1)
      //        break;
      //   gap=gap%2?gap/2+1:gap/2;
      // }