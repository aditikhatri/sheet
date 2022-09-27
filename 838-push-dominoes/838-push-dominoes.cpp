class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n = dominoes.size();
        int leftTimes[n+1];
        int rightTimes[n+1];
        // memset(leftTimes, 0, sizeof leftTimes);
        // memset(rightTimes, 0, sizeof rightTimes);
        stack<int> minStack;
        
        for(int i=0; i<n; i++){
            
            while(!minStack.empty() && dominoes[i] != '.'){
                int topIndex = minStack.top();
                minStack.pop();
                if(dominoes[i] == 'L')
                leftTimes[topIndex] = i-topIndex;
            }
            
            if(dominoes[i] == '.')minStack.push(i);
            leftTimes[i] = INT_MAX;
            rightTimes[i] = INT_MAX;
        }
        
        while(!minStack.empty())minStack.pop();
        
        for(int i=n-1; i>=0; i--){
            while(!minStack.empty() && dominoes[i] != '.'){
                int topIndex = minStack.top();
                minStack.pop();
                if(dominoes[i] == 'R')
                rightTimes[topIndex] = topIndex - i;
            }
            if(dominoes[i] == '.')minStack.push(i);
        }
        
        for(int i=0; i<n; i++){
            if(leftTimes[i]>rightTimes[i])dominoes[i] = 'R';
            else if(leftTimes[i] < rightTimes[i])dominoes[i] = 'L';
        }
        
        return dominoes;
    }
};