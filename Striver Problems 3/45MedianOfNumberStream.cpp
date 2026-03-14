#include<bits/stdc++.h>
using namespace std;

// I couldn't come up with this solution 
// AddNum O(log n) FindMedian O(1)
class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size()>maxHeap.size()){ 
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size()==maxHeap.size()) return ((double)minHeap.top()+(double)maxHeap.top())/2;
        else return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */