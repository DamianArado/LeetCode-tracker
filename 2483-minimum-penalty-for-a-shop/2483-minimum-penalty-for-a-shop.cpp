class Solution {
public:
    int bestClosingTime(string customers) {
        int n = size(customers);
        // closed at the start
        int currentPenalty = count(begin(customers), end(customers), 'Y');
        int minPenalty = currentPenalty, earliestHour = 0;
        
        for (int i = 0; i < n; ++i) {
            // keeping it open till hour i
            if (customers[i] == 'Y')
                --currentPenalty;
            else 
                ++currentPenalty;
            if (currentPenalty < minPenalty) {
                earliestHour = i + 1;
                minPenalty = currentPenalty;
            }
        }
        return earliestHour;
    }
};