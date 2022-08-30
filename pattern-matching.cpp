#include <bits/stdc++.h>
using namespace std;
/*

Naive method - O(mn) time and O(1) space

bool isEquals(string &pattern, string &text, int l, int r) {
    for(int i = l; i <= r; ++i) {
        if(pattern[i - l] != text[i])
            return false;
    }
    return true;
}

vector<int> findPattern(string &text, string &pattern) {
    int i = 0, j = pattern.size() - 1;
    vector<int> ans;
    while(j < text.size()) {
        if(isEquals(pattern, text, i, j))
            ans.push_back(i);
        i++;
        j++;
    }
    return ans;
}

*/

/*

Kmp algorithm - the idea behind it is to avoid the comparisons by creating an LPS array (where we mark the positions of the longest prefix which is also a suffix) and here, we also avoid backtracking of i
i will start from 1 and j will start from 0. 
We'll compare text[i] with pattern[j + 1] and if they match, we move both of them forward and if they don't, we move j from its current position to lps[j]. 

Now, how do we pre-compute the LPS array?
https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

*/

int main() {
    string text = "geeksforgeeks";
    string pattern = "geek";
    auto indices = findPattern(text, pattern);
    for(int i : indices) cout << i << " ";
    return 0;
}
