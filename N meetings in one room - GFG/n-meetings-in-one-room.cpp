// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    // TC - O(nlogn), SC - O(n)
    
    struct meeting { int start, end, position; };
    
    static bool comparator(struct meeting m1, meeting m2) {
        if(m1.end < m2.end) return true;
        else if(m1.end > m2.end) return false;
        else if(m1.position < m2.position) return true;
        return false;
    }
    
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n) {
        // Step 1: create an array of structures of size n
        struct meeting meet[n];
        for(int i = 0; i < n; ++i)
            meet[i].start = start[i], meet[i].end = end[i], meet[i].position = i + 1;
        
        // Step 2: sort the meet array on the basis of increasing order of end[]
        sort(meet, meet + n, comparator);
        
        // Step 3: add the meeting which ends first in the answer
        int maxMeets = 1;
        int limit = meet[0].end;  // all the other meetings start when the first one ends
        
        // Step 4: count the number of meets
        for(int i = 1; i < n; ++i) {
            if(meet[i].start > limit) {
                limit = meet[i].end;
                maxMeets += 1;
            }
        }
        return maxMeets;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends