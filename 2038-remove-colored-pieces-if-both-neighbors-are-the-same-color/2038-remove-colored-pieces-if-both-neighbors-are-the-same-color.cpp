class Solution {
public:
   bool winnerOfGame(string col) {
       int c1=0,c2=0,i=0;
       while(i<col.size()){
           int cl=0;
           while(col[i]=='A'){
               cl++;
               i++;
           }
           if(cl>2)
               c1+=cl-2;
           cl=0;
           while(col[i]=='B'){
               cl++;
               i++;
           }
           if(cl>2)
               c2+=cl-2;
       }
       return c1>c2?true:false;
   }
};