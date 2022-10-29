class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words[0].size();
        vector<int> majArr;
        for(int i = 0; i < n - 1; ++i)
            majArr.emplace_back(words[0][i + 1] - words[0][i]);
        int count = 0;
        for(string &word : words) {
            vector<int> diff;
            for(int i = 0; i < n - 1; ++i) {
                diff.emplace_back(word[i + 1] - word[i]);
            }
            if(count == 0) majArr = diff;
            if(majArr == diff) count++;
            else count--;
        }
        string nonMajority;
        for(string &word : words) {
            vector<int> diff;
            for(int i = 0; i < n - 1; ++i) {
                diff.emplace_back(word[i + 1] - word[i]);
            }
            if(diff != majArr) {
                nonMajority = word;
                break;
            }
        }
        return nonMajority;
    }
};