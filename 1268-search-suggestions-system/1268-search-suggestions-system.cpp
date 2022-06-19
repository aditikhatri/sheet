class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string s) {
      
        sort(products.begin(),products.end());
        vector<vector<string>>v;
        for(int i = 0;i<s.size();i++)
        {
             string x = s.substr(0,i+1);
            auto it = lower_bound(products.begin(),products.end(),x);
            vector<string>temp;
            for(int i = 0;i<3 && i+it != products.end();i++)
            {
                string sat = *(it+i);
                if(sat.find(x) == string :: npos)
                    break;
                temp.push_back(sat);
            }
            v.push_back(temp);
        }
        return v;
    }
};