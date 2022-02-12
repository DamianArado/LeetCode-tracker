class BrowserHistory {
public:
    list<string> historyPages;  // the pages that are present in my browser history
    list<string> :: iterator it;
    BrowserHistory(string homepage) {
        historyPages.emplace_back(homepage);
        it = historyPages.begin();
    }
    
    void visit(string url) {
        auto del = it; 
        del++;  // delete the history: (here, last]
        historyPages.erase(del, historyPages.end()); 
        historyPages.emplace_back(url);  // add a new page after here
        it++;  
    }
    
    string back(int steps) {  // at most we can reach start of list
        while(it != historyPages.begin() && steps--) it--;
        return *it;  // return value by dereferencing the pointer/iterator
    }
    
    string forward(int steps) {  // at most we can reach the end of list
        while(it != (--historyPages.end()) && steps--) it++;
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */