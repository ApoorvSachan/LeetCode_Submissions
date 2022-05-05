class MyStack {
public:
    queue<int> q, rq;  
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
       int t;
       while(q.size()!=1)
       {
           rq.push(q.front());
           q.pop();
       }
       t=q.front();
       q=rq;
       while(!rq.empty()) rq.pop();
       return t;
    }
    
    int top() {
         while(q.size()!=1)
       {
           rq.push(q.front());
           q.pop();
       }
       int t=q.front();
       rq.push(q.front());
       q=rq;
       while(!rq.empty()) rq.pop();
        return t;
    }
    
    bool empty() {
       return q.empty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */