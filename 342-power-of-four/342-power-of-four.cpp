class Solution {
public:
    bool isPowerOfFour(unsigned n) {
    //return ((n>0)&& (n&(n-1))==0 && (n & 0xAAAAAAAA)==0); //n and with //1010...
             int count=0;
        if(n&& !(n&(n-1))){  //check 1 set bit only na
            while(n>1){  // check 0 before set bit
                n=n>>1;
                count=count+1;
            }
            return (count%2==0);
        }
        return 0;
    }
};