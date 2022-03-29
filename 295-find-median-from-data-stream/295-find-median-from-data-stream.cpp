class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    double median;
    void addNum(int num) {
      if(maxheap.size()==0)
        {
          maxheap.push(num);
          median=num;
          return;
        }
      int l=maxheap.size(), r=minheap.size();
      if(l==r)
         {
             if(num<median)
             {maxheap.push(num);
              median=maxheap.top();
             }
             else
             {minheap.push(num);
              median=minheap.top();
             }
          }
      else if(l>r)
          {
            if(num>median)
            {
               minheap.push(num); 
            }
            else
            {
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
            }
            median=(minheap.top()+maxheap.top())/2.0;
          }
      else
          {
            if(num<median)
            {
               maxheap.push(num); 
            }
            else
            {
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(num);
            }
            median=(minheap.top()+maxheap.top())/2.0;
          }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */