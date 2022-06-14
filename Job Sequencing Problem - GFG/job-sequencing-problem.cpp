// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool comparator(Job a, Job b) {
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
        // Step 1: We have to sort the jobs according to decreasing order of profit
        sort(arr, arr + n, comparator);
        // Step 2: find the max deadline date
        int maxP = arr[0].dead;
        for(int i = 1; i < n; ++i) 
            maxP = max(maxP, arr[i].dead);
        // Step 3: Create an array of slots
        int slot[maxP + 1];
        for(int i = 0; i <= maxP; ++i)
            slot[i] = -1;
        // Step 4: finish a max profit job on the last day of its deadline and mark slots with its id
        // if its already marked check to its left
        int numJobs = 0, maxJobsProfit = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = arr[i].dead; j > 0; --j) {
                if(slot[j] == -1) {
                    slot[j] = i;
                    numJobs += 1;
                    maxJobsProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {numJobs, maxJobsProfit};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends