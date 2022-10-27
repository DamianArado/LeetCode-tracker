//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        int i = 0, j = n - 1;
        // check for potential celebrity
        while(i < j) {
            if(M[i][j]) ++i;
            else --j;
        }
        int celebIdx = i;
        // check if we have a valid celebrity or not
        for(int i = 0; i < n; ++i)
            if(i != celebIdx and (M[celebIdx][i] or !M[i][celebIdx]))
                return -1;
        return celebIdx;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends