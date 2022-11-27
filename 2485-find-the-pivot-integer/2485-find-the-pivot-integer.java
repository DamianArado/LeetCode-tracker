class Solution {
    public int pivotInteger(int n) {
        if(n == 1) return 1;
        int sum = n * (n + 1) / 2, start = 0, end = n;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(mid * mid == sum) return mid;
            else if(mid * mid > sum) end = mid - 1;
            else start = mid + 1;
        }
        return -1;
    }
}