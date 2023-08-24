class Solution {
public:
    string reorganizeString(string s) {
        vector<int> charCount(26);
        for (const char &c : s)
            ++charCount[c - 'a'];
        // max heap for character count
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < 26; ++i) 
            if (charCount[i] > 0)
                maxHeap.emplace(charCount[i], 'a' + i);
        string ans;
        while (!maxHeap.empty()) {
            auto [cnt1, char1] = maxHeap.top();
            maxHeap.pop();
            
            if (ans.empty() or char1 != ans.back()) {
                ans += char1;
                if (--cnt1 > 0)
                    maxHeap.emplace(cnt1, char1);
            } else {
                if (maxHeap.empty()) 
                    return "";
                auto [cnt2, char2] = maxHeap.top();
                maxHeap.pop();
                ans += char2;
                if (--cnt2 > 0)
                    maxHeap.emplace(cnt2, char2);
                maxHeap.emplace(cnt1, char1);
            }
        }
        return ans;
    }
};