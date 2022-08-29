class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
          int j=0,i=0;
      for(int i=m;i<m+n;i++,j++)
          nums1[i]=nums2[j];
      int gap=ceil((m+n)/2);
      while(gap>=1)
      {
         i=0,j=i+gap;
        while(j<(m+n)) 
        {
          if(nums1[i]>nums1[j]) 
              swap(nums1[i],nums1[j]);
            i++;
            j++;
        }
        if(gap==1)
             break;
        gap=gap%2?gap/2+1:gap/2;
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