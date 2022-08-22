class BrowserHistory {
public:
    vector<string> history;
    int curr_pos;
    BrowserHistory(string homepage) {
     history.push_back(homepage);
     curr_pos=0;
    }
    
    void visit(string url) {
     history.resize(curr_pos+1);
     history.push_back(url);
     curr_pos++;
    }
    
    string back(int steps) {
     if(steps>curr_pos) curr_pos=0;
     else curr_pos-=steps;
     return history[curr_pos];
    }
    
    string forward(int steps) {
      if(steps+curr_pos>=history.size()) curr_pos=history.size()-1;
      else curr_pos=steps+curr_pos;
      return history[curr_pos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */