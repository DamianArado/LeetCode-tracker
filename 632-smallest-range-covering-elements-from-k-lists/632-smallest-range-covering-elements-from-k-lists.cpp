class Solution {
// TC - O(nklogk), SC - O(k)
public:
    struct node {
        int data, row, column;
        node(int value, int i, int j) : data(value), row(i), column(j) {}
    };
    struct comparator {
        bool operator() (node a, node b) {
            return a.data > b.data;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        // this approach will use min heap of size k
        priority_queue<node, vector<node>, comparator> minHeap;
        int currMin = INT_MAX, currMax = INT_MIN, currRange = INT_MAX;
        // run a loop for k times and build the min heap
        for(int i = 0; i < k; ++i) {
            currMax = max(currMax, nums[i][0]);
            node temp(nums[i][0], i, 0);
            minHeap.push(temp);
        }
        // the start and end range of our answer
        int start = currMin, end = currMax;
        while(true) {
            node min = minHeap.top();
            minHeap.pop();
            currMin = min.data;
            // if we got a smaller range
            if(currMax - currMin < currRange) {
                start = currMin;
                end = currMax;
                currRange = currMax - currMin;
            }
            // if we don't have anymore elements in the row of min element, we're done
            if(min.column + 1 == nums[min.row].size())
                break;
            // if we still have atleast one element push it inside the min heap
            node next(nums[min.row][min.column + 1], min.row, min.column + 1);
            minHeap.push(next);
            // update the currMax if the next element is bigger than this
            if(next.data > currMax)
                currMax = next.data;
        }
        return {start, end};
    }
};