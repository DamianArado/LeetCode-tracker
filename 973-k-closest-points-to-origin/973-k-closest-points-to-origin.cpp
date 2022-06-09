// TC - O(nlogk + k) = O(nlogk), SC - O(k) for maxHeap
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // firstly create a max heap of type [distanceFromOrigin, xi, yi]
        priority_queue<vector<int>> maxHeap;
        for(auto point : points) {
            int x = point[0], y = point[1];
            maxHeap.push({x*x + y*y, x, y});
            if(maxHeap.size() > k)
                maxHeap.pop();
        }
        // now we have only the k points inside the maxHeap that are closest to the origin
        vector<vector<int>> ans(k);
        for(int i = 0; i < k; ++i) {
            vector<int> topElem = maxHeap.top();
            maxHeap.pop();
            ans[i] = {topElem[1], topElem[2]};
        }
        return ans;
    }
};