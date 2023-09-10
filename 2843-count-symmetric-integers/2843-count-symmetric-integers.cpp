class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
       int count =0;
        for(int i=low;i<=high;i++){
            string s= to_string(i);
            if(s.size()%2==0){
                int n= s.size(),sum=0;
                for(int j=0;j<n/2;j++)
                    sum+= s[j]-'0';
                for(int j=n/2;j<n;j++)
                    sum-=s[j]-'0';
                if(sum==0) count++;
            }
        }
        
        return count;
    }
};