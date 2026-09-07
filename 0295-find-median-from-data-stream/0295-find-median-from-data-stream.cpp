class MedianFinder {
public:
priority_queue<int>p1;
priority_queue<int,vector<int>,greater<int>>p2;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(p1.empty() || num< p1.top()) p1.push(num);
        else p2.push(num);
        if(p1.size()>p2.size()+1){
            p2.push(p1.top());
            p1.pop();
        }
        else if(p1.size()<p2.size()){
            p1.push(p2.top());
            p2.pop();
        }
    }
    
    double findMedian() {
        if(p1.size()==p2.size()){
            return (p1.top() + p2.top())/2.0;
        }
        else return p1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */