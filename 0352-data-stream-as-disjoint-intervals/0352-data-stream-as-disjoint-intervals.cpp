// TC: O(nlogn), SC: O(n)

// class SummaryRanges {
// private:
//     set<int> s;
// public:
//     SummaryRanges() {
//         s.clear();
//     }
    
//     void addNum(int value) {
//         s.insert(value);
//     }
    
//     vector<vector<int>> getIntervals() {
//         vector<vector<int>> intervals;
//         vector<int> arr(begin(s), end(s));
//         int n = size(s);
//         for(int i = 0; i < n; ++i) {
//             int left = arr[i];
//             while(i < n - 1 and arr[i] + 1 == arr[i + 1]) ++i;
//             intervals.push_back({left, arr[i]});
//         }
//         return intervals;
//     }
// };

class SummaryRanges {
private:
    map<int, int> mp;
public:
    SummaryRanges() {
        mp.clear();
    }
    
    void addNum(int value) {
        int left = value, right = value;
        auto justGreater = mp.upper_bound(value);
        if(justGreater != begin(mp)) {
            auto justLesser = justGreater;
            --justLesser;
            if(justLesser->second >= value) 
                return;
            if(justLesser->second == value - 1) 
                left = justLesser->first;
        }
        if(justGreater != end(mp) and justGreater->first == value + 1) {
            right = justGreater->second;
            mp.erase(justGreater);
        }
        mp[left] = right;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        for(auto &[key, value] : mp) intervals.push_back({key, value});
        return intervals;
    }
};


/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */