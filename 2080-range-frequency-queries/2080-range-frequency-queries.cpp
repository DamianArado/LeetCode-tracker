class RangeFreqQuery {
public:
    vector<int> ids[10001] = {};
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i)
            ids[arr[i]].push_back(i);
    }
    int query(int left, int right, int v) {
        return upper_bound(begin(ids[v]), end(ids[v]), right) - 
            lower_bound(begin(ids[v]), end(ids[v]), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */