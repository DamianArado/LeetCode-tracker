/*

Naive method - O(mn) time and O(1) space

int findPattern(string &text, string &pattern) {
    int n1 = size(text), n2 = size(pattern);
    for(int i = 0; i <= n1 - n2; ++i) {
        int j = 0;
        for( ; j < n2; ++j)
            if(text[i + j] != pattern[j])
                break;
        if(j == n2) return i;
    }
    return -1;
}

*/

/*

Kmp algorithm - the idea behind it is to avoid the comparisons by creating an LPS array (where we mark the positions of the longest prefix which is also a suffix) and here, we also avoid backtracking of i
i will start from 1 and j will start from 0. 
We'll compare text[i] with pattern[j + 1] and if they match, we move both of them forward and if they don't, we move j from its current position to lps[j]. 

Now, how do we pre-compute the LPS array?
https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

vector<int> constructLPS(string &pattern) {
    int n = size(pattern);
    vector<int> lps(n);
    int i = 0, j = 1;
    while(j < n) {
        if(pattern[i] == pattern[j]) {
            lps[j] = i + 1;
            ++i, ++j;
        } else if(i == 0) {
            lps[j] = 0;
            ++j;
        } else i = lps[i - 1];
    }
    return lps;
}

int findPattern(string &text, string &pattern) {
    int n1 = size(text), n2 = size(pattern);
    vector<int> lps = constructLPS(pattern);
    for(int i = 0, j = 0; i < n1; ) {
        if(text[i] == pattern[j]) {
            ++i;
            ++j;
        }
        if(j == n2) return i - j;
        if(text[i] != pattern[j])
            j > 0 ? j = lps[j - 1] : ++i;
    }
    return -1;
}


*/

int main() {
    string text = "geeksforgeeks";
    string pattern = "geek";
    auto indices = findPattern(text, pattern);
    for(int i : indices) cout << i << " ";
    return 0;
}
