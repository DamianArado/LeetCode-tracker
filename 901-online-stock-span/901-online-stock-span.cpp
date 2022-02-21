/*

Push every pair of <price, result> to a stack.
Pop lower price from the stack and accumulate the count.

One price will be pushed once and popped once.
So 2 * N times stack operations and N times calls.
I'll say time complexity is amortized O(1)

*/

class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    stack<pair<int, int>> s;
    
    int next(int price) {
        int res = 1;
        while (!s.empty() && s.top().first <= price) {
            res += s.top().second;
            s.pop();
        }
        s.push({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */