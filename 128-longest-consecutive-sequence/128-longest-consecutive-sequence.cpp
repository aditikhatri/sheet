class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> st; 
        
        for(auto it: nums){
            st.insert(it); 
        }
        
        int longestStreak = 0; 
        
        for(auto s: st){
            if(!st.count(s-1)){
                int currNum = s; 
                int currStreak = 1; 
                
                while(st.count(currNum + 1)){
                    currStreak += 1; 
                    currNum += 1;
                } 
                longestStreak = max(longestStreak, currStreak) ;
            }
            
        }
        
        return longestStreak; 
    }
};