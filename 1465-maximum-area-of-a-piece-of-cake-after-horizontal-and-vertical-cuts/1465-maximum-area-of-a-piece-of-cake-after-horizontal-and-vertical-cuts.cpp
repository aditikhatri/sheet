class Solution {
public:
    long long mod=1e9+7;
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        hc.push_back(h);
        vc.push_back(w);
        int  a,b;
        a=hc[0];
        b=vc[0];
        for(int i=1;i<hc.size();++i){
           a=max(a,hc[i]-hc[i-1]);
        }
        for(int i=1;i<vc.size();++i){
           b=max(b,vc[i]-vc[i-1]);
        }
        
        return (1LL*a*b)%mod;
        
        
    }
};