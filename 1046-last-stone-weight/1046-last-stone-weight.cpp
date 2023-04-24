class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(begin(stones), end(stones));
        while(size(maxHeap) > 1) {
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();
            if(stone1 == stone2) continue;
            else {
                if(stone1 > stone2) {
                    stone1 -= stone2;
                    maxHeap.emplace(stone1);
                } else {
                    stone2 -= stone1;
                    maxHeap.emplace(stone2);
                }
            }
        }
        return !maxHeap.empty() ? maxHeap.top() : 0;
    }
};