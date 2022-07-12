/**

Approach 1: Calculate the up slope and down slope: TC -> O(n) SC -> O(n)

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> up(n, 0), down(n, 0);
        int longestMnt = 0;
        // down[i] tells us about the length of the downwards slope starting at i + 1
        for(int i = n - 2; i >= 0; --i)
            if(arr[i] > arr[i + 1])
                down[i] = down[i + 1] + 1;
        // up[i] tells us about the length of the upwards slope ending at i - 1
        for(int i = 1; i < n; ++i) {
            if(arr[i] > arr[i - 1])
                up[i] = up[i - 1] + 1;
            // should not be zero and both should be processed in order to find the peak of the longest mountain
            if(down[i] and up[i])
                longestMnt = max(longestMnt, up[i] + down[i] + 1);
        }
        return longestMnt;
    }
};

Approach 2: A O(n) time and O(1) space one-pass solution

*/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int maxMountain = 0, n = arr.size(), idx = 1, up = 0, down = 0;
        while (idx < n) {
            while(idx < n && arr[idx - 1] == arr[idx])
                ++idx;
            // start looking further in array for a possible mountain
            up = 0;
            while(idx < n && arr[idx - 1] < arr[idx])
                ++up, ++idx;
            down = 0;
            while(idx < n && arr[idx - 1] > arr[idx])
                ++down, ++idx;
            if(up && down)  
                // + 1 as we do add the peak itself
                maxMountain = max(maxMountain, up + down + 1);
        }
        return maxMountain;
    }
};