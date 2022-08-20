class Solution {
public:
   int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
      int i=0;
      int a;
      priority_queue<int , vector<int>> pq;  
      
      for(a = 0 ; startFuel<target ; a++)
      {
          while(i<stations.size() && stations[i][0] <= startFuel) pq.push(stations[i++][1]);
          if(pq.empty())return -1;      
          startFuel+=pq.top();
          pq.pop();
      }
      return a;
  }
};