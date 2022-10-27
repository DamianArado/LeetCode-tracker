//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    vector<int> help_classmate(vector<int> arr, int n)  { 
        if(n == 1) return {-1};
        vector<int> ans(n);
        stack<pair<int, int>> s;
        s.push(make_pair(arr[0], 0));
        int x = arr[1];
        for(int i = 1; i < n; ++i) {
            x = arr[i];
            if(x >= s.top().first) s.push(make_pair(x, i));
            else {
                while(!s.empty() and x < s.top().first) {
                    ans[s.top().second] = x;
                    s.pop();
                    if(s.empty()) s.push(make_pair(x, i));
                }
                if(x >= s.top().first) s.push(make_pair(x, i));
            }
        }
        while(!s.empty()) {
            ans[s.top().second] = -1;
            s.pop();
        }
        return ans;
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
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends