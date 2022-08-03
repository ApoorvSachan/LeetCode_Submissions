class MyCalendar {
public:
    set<pair<int,int>> s;
    bool book(int start, int end) {
       auto p=s.lower_bound({start,end});
       if((p!=s.end() && p->first<end) || (p!=s.begin() && (--p)->second>start))
               return false;
       s.insert({start,end});
       return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */