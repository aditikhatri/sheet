class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        //mtd 1 ->o(mn) taking 1st string and comparing rest
        int res=INT_MAX;
        if(v.size()==0)return "";
        string c=v[0];

        for(int i=1;i<v.size();i++){
          int j=0,k=0,ans=0;
            while(j<c.size() && k< v[i].size()){
                if(c[j]==v[i][k])ans++;
                else break;
                j++;k++;
            }
            res=min(ans,res);
        }
        return c.substr(0,res);
        
        // mtd2->o(nlog n*m) compare 1st and last as they have max variation
       
//         if(v.size()==0)return "";
//         string res="";
//         sort(begin(v),end(v));
//         string a=v[0]; string b=v[v.size()-1];
//         for(int i=0;i<a.size();i++){
//             if(a[i]==b[i]) res=res+a[i];
//             else break;
//         }
//           return res;  
    }
};