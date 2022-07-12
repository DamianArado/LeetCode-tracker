class Solution {
    public int longestMountain(int[] arr) {
        int maxMountain = 0, idx = 1, up = 0, down = 0, n = arr.length;
        while(idx < n) {
            while(idx < n && arr[idx - 1] == arr[idx])
                ++idx;
            up = 0;
            while(idx < n && arr[idx - 1] < arr[idx]) {
                ++up;
                ++idx;
            }
            down = 0;
            while(idx < n && arr[idx - 1] > arr[idx]) {
                ++down;
                ++idx;
            }
            if(up > 0 && down > 0)
                maxMountain = Math.max(maxMountain, up + down + 1);
        }
        return maxMountain;
    }
}