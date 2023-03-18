class BrowserHistory {
private:
    list<string> historyPages;
    list<string> :: iterator it;
public:
    BrowserHistory(string homepage) {
        historyPages.emplace_back(homepage);
        it = begin(historyPages);
    }
    
    void visit(string url) {
        list<string> :: iterator deleted = it;
        ++deleted;
        historyPages.erase(deleted, end(historyPages));
        historyPages.emplace_back(url);
        ++it;
        
    }
    
    string back(int steps) {
        while(it != begin(historyPages) and steps--)
            --it;
        return *it;
    }
    
    string forward(int steps) {
        while(it != (--end(historyPages)) and steps--)
            ++it;
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