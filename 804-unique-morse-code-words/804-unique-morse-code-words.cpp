class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string>s;
        vector<string> vec ={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	    
        string str;
        for(int i=0;i<words.size();i++){
            str="";
            for(int j=0;j<words[i].length();j++)
                str+=vec[words[i][j]-'a'];
                
            s.insert(str);
        }
        return s.size();
    }
};