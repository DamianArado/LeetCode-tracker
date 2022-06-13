// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
    	// Step 1: sort act arrival times
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	// Step 2: until one of the arr or dep exhausts count the max platforms required
    	int currentPF = 1, minPF = 0, i = 1, j = 0;
    	while(i < n and j < n) {
    	    if(arr[i] <= dep[j]) {
    	        currentPF += 1;
    	        i++;
    	    }
    	    else if(dep[j] < arr[i]) {
    	        currentPF -= 1;
    	        j++;
    	    }
    	    minPF = max(minPF, currentPF);
    	}
    	return minPF;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends