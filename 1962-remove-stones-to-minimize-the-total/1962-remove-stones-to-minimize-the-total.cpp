class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap(begin(piles), end(piles));
        while(k--) {
            int max = maxHeap.top();
            maxHeap.pop();
            int reduced = (max % 2 == 0 ? max / 2 : max / 2 + 1);
            maxHeap.emplace(reduced);
        }
        int minSum = 0;
        while(!maxHeap.empty()) {
            minSum += maxHeap.top();
            maxHeap.pop();
        }
        return minSum;
    }
};