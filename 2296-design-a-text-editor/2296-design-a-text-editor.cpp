class TextEditor {
public:
    string left, right;
    TextEditor() {
        left="";
        right="";
    }
    
    void addText(string text) {
        left+=text;
    }
    
    int deleteText(int k) {
        int c=k;
        if(k>left.size())
        {
            c=left.size();
            left="";
            return c;
        }
        while(k)
        {
            left.pop_back();
            k--;
        }
        return c;
    }
    
    string cursorLeft(int k) {
       int l=left.size();
       if(k>l)
       {
           reverse(left.begin(),left.end());
           right=right+left;
           left="";
           return left;
       }
        int c=k;
       while(c)
       {
           char p=left[left.length()-1];
           left.pop_back();
           right+=p;
           c--;
       }
        
       if(left.size()>10)
           return left.substr(left.size()-10);
        else
            return left;
    }
    
    string cursorRight(int k) {
       int l=right.size();
       if(k>l)
       {
           reverse(right.begin(),right.end());
           left=left+right;
           right="";
       }
        else{
        int c=k;
       while(c)
       {
           char p=right[right.length()-1];
           right.pop_back();
           left+=p;
           c--;
       }
        }
        
       if(left.size()>10)
           return left.substr(left.size()-10);
        else
            return left;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */