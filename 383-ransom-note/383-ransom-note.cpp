class Solution {
public:
   bool canConstruct(string ransomNote, string magazine) {
        
        
        unordered_map<char,int>mp;
        for(int i=0;i<magazine.size();i++){
            // store frequrncy of character of magazine
            mp[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            // If character from ransomNote is not present in map then return false
            if(mp[ransomNote[i]]==0)return false;
            
            //If character is present then decrease its value by 1
            mp[ransomNote[i]]--;
        }
        return true;
    }
};