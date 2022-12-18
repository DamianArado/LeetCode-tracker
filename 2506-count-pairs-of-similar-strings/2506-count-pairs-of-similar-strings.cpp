class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0, n = words.size();
        for(int i = 0; i < n - 1; ++i) {
            // use a map to count frequency of the current word
            unordered_map<char, int> mp1;
            for(char &c : words[i]) 
                mp1[c] = 1;
            for(int j = i + 1; j < n; ++j) {
                // use this map to compare
                unordered_map<char, int> mp2;
                for(char &c : words[j]) mp2[c] = 1;
                // if same 
                if(mp1 == mp2) 
                    ans++;
            }
        }
        return ans;
    }
};