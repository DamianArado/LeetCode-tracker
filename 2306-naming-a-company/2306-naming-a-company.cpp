typedef long long ll;
class Solution {
public:
    ll distinctNames(vector<string>& ideas) {
        ll ans = 0;
        unordered_set<string> suffix[26];
        // Add all the suffixed inside the set
        for(const string &idea : ideas)
            suffix[idea[0] - 'a'].insert(idea.substr(1));
        for(int i = 0; i < 26; ++i) {
            for(int j = i + 1; j < 26; ++j) {
                ll same = 0;
                for(const string &ideaA : suffix[i])
                    // if it is the same suffix
                    if(suffix[j].count(ideaA)) ++same;
                // add the no. of distinct valid names to the answer
                ans += (2 * (size(suffix[i]) - same) * (size(suffix[j]) - same));
            }
        }
        return ans;
    }
};