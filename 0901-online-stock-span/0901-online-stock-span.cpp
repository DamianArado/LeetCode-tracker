class StockSpanner {
private:
    stack<pair<int, int>> s;
public:
    StockSpanner() {}
    
    int next(int price) {
        int counter = 1;
        while(!s.empty() and price >= s.top().first) {
            counter += s.top().second;
            s.pop();
        }
        s.emplace(price, counter);
        return counter;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */