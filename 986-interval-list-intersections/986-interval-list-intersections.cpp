class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        // edge case
        if(firstList.size() == 0 || secondList.size() == 0) {
            return result;
        }
        // i : index for firstList, j : index for secondList
        // moving i fwd if end of firstList > secondList and v-v
        for(int i = 0, j = 0; i < firstList.size() && j < secondList.size(); firstList[i][1] < secondList[j][1] ? ++i : ++j) {
            // [start, end] for each intersecting interval
            auto start = max(firstList[i][0], secondList[j][0]);
            auto end = min(firstList[i][1], secondList[j][1]);
            if (start <= end)
                result.push_back({start, end});
        }
        return result;
    }
};