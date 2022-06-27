class Solution {
public:
    int minPartitions(string n) {
        //return *max_element(n.begin(),n.end())-'0';
        int maxi=0;
        for(auto i:n){
            maxi=max(maxi,i-'0');
        }
        return maxi;
    }
};
//by observation 32 -11= 22-11= 11 -11 =0 
//so we need atleast 3 d-b no i.e max digit in string 