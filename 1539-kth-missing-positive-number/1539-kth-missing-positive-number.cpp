class Solution {
public:
    // int findKthPositive(vector<int>& arr, int k) {
    //     // brute force
    //     unordered_map<int, int> mp;
    //     for(int &i : arr) mp[i]++;
    //     int current = 1;
    //     while(k > 0) {
    //         if(!mp.count(current)) --k;
    //         ++current;
    //     }
    //     return current - 1;
    // }
    int findKthPositive(vector<int>& arr, int k) {
        // find the 1st index where the no. of missing elements is greater than k
        // we are virtually considering an array which stores the no. of missing elements till an index i
        // element in each index: vArr[i] = arr[i] - i - 1
        int start = 0, end = size(arr); // end till last index + 1 coz it may happen that we didnt have any missing no. till last index in array
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(arr[mid] - mid - 1 < k)
                start = mid + 1;
            else 
                end = mid;
        }
        // Answer = arr[end] - (vArr[end] - k + 1) = end + k 
        return end + k;
    }
};