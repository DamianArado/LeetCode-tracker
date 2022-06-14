// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    // tc: O(nlogn), sc: O(1)
    static bool comparator(Item a, Item b) {
        return ((double)a.value / (double)a.weight) > ((double)b.value / (double)b.weight);
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Step 1: sort arr according to decreasing order of value / weight
        sort(arr, arr + n, comparator);
        // Step 2: iterate and add into our knapsack, complete or fractional amounts
        int currentWt = 0;
        double totalVal = 0.0;
        for(int i = 0; i < n; ++i) {
            // check if we can take the complete value
            if(currentWt + arr[i].weight <= W) {
                currentWt += arr[i].weight;
                totalVal += arr[i].value;
            } else {
                // take only a fractional amount
                int remWt = W - currentWt;
                totalVal += ((arr[i].value / (double)arr[i].weight) * (double)remWt);
                break;  // can't add more weight now
            }
        }
        return totalVal;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends