class MinStack {
    int m;
    vector<int> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push_back(val);
        if(s.size()==1) m=s[0];
        else
            m=min(m,val);
    }
    
    void pop() {
        s.pop_back();   
        m=*min_element(s.begin(),s.end());
    }
    
    int top() {
       return s[s.size()-1]; 
    }
    
    int getMin() {
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */