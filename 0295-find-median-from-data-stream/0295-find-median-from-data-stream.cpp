class MedianFinder {
public:
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
    int len;
    MedianFinder() {
        len = 0;
    }
    
    void addNum(int num) {
        len++;
        // empty
        if(maxH.empty() && minH.empty()) {
            maxH.push(num);
            return;
        }
        // when len is same
        if(maxH.size() == minH.size()) {
            if(num > minH.top()) {
                int curr = minH.top();
                minH.pop();
                maxH.push(curr);
                minH.push(num);
            }
            else maxH.push(num);
            return;
        }
        // when len is one more then minH
        if(maxH.size() - minH.size() == 1) {
            if(num <= maxH.top()) {
                int curr = maxH.top();
                maxH.pop();
                minH.push(curr);
                maxH.push(num);
            }
            else minH.push(num);
            return;
        }
    }
    
    double findMedian() {
        if(len&1) {
            return double(maxH.top());
        }
        return (double(maxH.top()) + double(minH.top())) / 2;
    }
};