class Solution {
private:
    bool check(int x, vector<int> &price, int k) {
        int i = 1, count = 1, last = price[0];
        while(i < size(price) and count < k) {
            if(price[i] - last >= x)
                last = price[i], ++count;
            ++i;
        }
        return count == k;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(begin(price), end(price));
        // first and last element will always be in our range 
        // as it can give us our answer
        int start = 0, end = price.back() - price.front() + 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            // can i create a sequence of k - 2 length using mid?
            // keep exploring bigger values
            if(check(mid, price, k)) start = mid + 1;
            else end = mid;
        }
        return start - 1;
    }
};