class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> minheap;
    priority_queue<int,vector<int>> maxheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(minheap.size()==maxheap.size()){
           if(maxheap.size()==0){
               maxheap.push(num);
           }
           else if(maxheap.top()<=num){
               minheap.push(num);
           }
           else{
               maxheap.push(num);
           }
       }
       else if(maxheap.size()>minheap.size()){
           if(num>=maxheap.top()){
               minheap.push(num);
           }
           else{
               minheap.push(maxheap.top());
               maxheap.pop();
               maxheap.push(num);
           }
       }
       else{
           if(num<=minheap.top()){
               maxheap.push(num);
           }
           else{
               maxheap.push(minheap.top());
               minheap.pop();
               minheap.push(num);
           }
       }
    }
    
    double findMedian() {
        if(maxheap.size()==minheap.size()) return (maxheap.top()+minheap.top())*1.0/2;
        else if(maxheap.size()>minheap.size()) return maxheap.top();
        else return minheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */