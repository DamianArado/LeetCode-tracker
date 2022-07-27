class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // sliding window length = k, total length moved would be n
        int n = s.size(), k = p.size(), i = 0, j = 0;
        // an unordered map to store freq of occurrence of chars in pattern
        unordered_map<char, int> mp;
        for(char &c : p) mp[c]++;
        int chars = mp.size();
        vector<int> ans;
        while(j < n) {
            // do the calculations required while first visiting each index
            // if we can find s[j] inside our map
            if(mp.find(s[j]) != mp.end()) {
                // decrease the occurrences, here its used as a sort of matching 
                mp[s[j]]--;
                // if it becomes zero, decrease the number of chars as well
                if(mp[s[j]] == 0) chars--;
            }
            // if we still didn't hit the window size
            if(j - i + 1 < k) j++;
            // when we hit the window size
            else if(j - i + 1 == k) {
                // check if all the characters matched, if yes add the starting index to the answer
                if(chars == 0)
                    ans.push_back(i);
                // here you need to make sure before sliding the window add the character occurrence back into map
                if(mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if(mp[s[i]] == 1) chars++;
                }
                // now slide the window
                i++; j++;
            }
        }
        return ans;
    }
};