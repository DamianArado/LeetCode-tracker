class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> maxHeap(begin(nums), end(nums));
        double operations = 0;
        double sum = 0;
        for(int &i : nums) sum += i;
        //if(size(nums) == sum) return sum;
        double half = sum;
        while(half > sum / 2) {
            double max = maxHeap.top();
            maxHeap.pop();
            double reduced = max / 2;
            half -= reduced;
            maxHeap.emplace(reduced);
            operations++;
        }
        return (int)operations;
    }
};