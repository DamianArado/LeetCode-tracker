class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        // step1 : sort on the basis of end times
        sort(begin(tasks), end(tasks), [&] (auto a, auto b) { return a[1] < b[1]; }); 
        unordered_map<int, bool> isOn;
        for(const auto &task : tasks) {
            int start = task[0], end = task[1], duration = task[2];
            // step2: try to fill the starting positions
            for(int time = start; time <= end; ++time)
                if(isOn.count(time)) --duration;
            // step3: if the duration remains fill from the end positions
            for(int time = end; duration > 0; --time) {
                if(isOn.count(time)) continue;
                isOn[time] = true;
                --duration;
            }
        }
        // step4: count all the time the PC was ON
        return size(isOn);
    }
};