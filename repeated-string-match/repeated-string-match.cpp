class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        for (auto i = 0, j = 0; i < A.size(); ++i) {
            for (j = 0; j < B.size() && A[(i + j) % A.size()] == B[j]; ++j);
            if (j == B.size()) 
                return (i + j - 1) / A.size() + 1;
        }
        return -1;
    }
};

/*
int repeatedStringMatch(string a, string b) {
    vector<int> prefTable(b.size() + 1); // 1-based to avoid extra checks.
    for (auto sp = 1, pp = 0; sp < b.size();)
        if (b[pp] == b[sp] || pp == 0)  {
            pp = b[pp] == b[sp] ? pp + 1 : 0;
            prefTable[++sp] = pp;
        }
        else
            pp = prefTable[pp];
    for (auto i = 0, j = 0; i < a.size(); ) {
        while (j < b.size() && a[(i + j) % a.size()] == b[j]) 
            ++j;
        if (j == b.size()) 
            return (i + j - 1) / a.size() + 1;
        j = prefTable[j];
        i += max(1, j - prefTable[j]);
    }
    return -1;
}
*/