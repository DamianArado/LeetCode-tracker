//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
     private:
        vector<int> construct(const string &pat, int n1) {
            vector<int> lps(n1);
            int i = 0, j = 1;
            while(j < n1) {
                if(pat[i] == pat[j]) lps[j] = ++i, ++j;
                else if(i == 0) ++j;
                else i = lps[i - 1];
            }
            return lps;
        }
    public:
        vector <int> search(string pat, string txt)
        {
            int n1 = pat.size(), n2 = txt.size();
            vector<int> lps = construct(pat, n1), ans;
            for(int i = 0, j = 0; i < n2; ) {
                if(txt[i] == pat[j]) ++j, ++i;
                else j > 0 ? j = lps[j - 1] : ++i;
                if(j == n1) ans.emplace_back(i - j + 1);
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends