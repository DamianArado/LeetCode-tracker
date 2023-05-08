class StockSpanner {
private:
    stack<pair<int, int>> s;  // < price, numDays >: for price, online stock span = numDays
public:
    StockSpanner() {}
    
    int next(int price) {
        int numDays = 1;
        while(!s.empty() and price >= s.top().first) {
            numDays += s.top().second;  // adding up the stock span for prev element in stack
            s.pop();  // consecutive so we can pop
        }
        s.emplace(price, numDays);
        return numDays;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */