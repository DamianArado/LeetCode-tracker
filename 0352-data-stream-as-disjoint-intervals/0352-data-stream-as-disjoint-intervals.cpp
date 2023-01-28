class SummaryRanges {
private:
    set<int> s;
public:
    SummaryRanges() {
        s.clear();
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        vector<int> arr(begin(s), end(s));
        int n = size(s);
        for(int i = 0; i < n; ++i) {
            int left = arr[i];
            while(i < n - 1 and arr[i] + 1 == arr[i + 1]) ++i;
            intervals.push_back({left, arr[i]});
        }
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */