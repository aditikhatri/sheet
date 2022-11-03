class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int length = words.size();
        unordered_map<string,int> freq;
        for(auto val:words) freq[val]++;
        int flag1 = 0, count = 0;
        for(auto val:freq){
           if(val.first[0]==val.first[1]){
              if(val.second % 2 == 0) {
                  count = count + (2 * val.second);
                  continue;
              }
              if(flag1){
                  count = count + (2 * (val.second - 1));
              }else{
                  count = count + (2 * (val.second));
                  flag1 = 1;
              }
              continue;
            }
           string temp = val.first;
           reverse(temp.begin(),temp.end());
           if(freq.find(temp)!=freq.end()){
              int x = min(val.second,freq[temp]);
              count = count + (x * 4);
              freq.erase(temp);
           }
        }
        return count;
    }
};