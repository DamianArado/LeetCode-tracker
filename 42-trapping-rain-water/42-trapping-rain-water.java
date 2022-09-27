class Solution {
    public int trap(int[] height) {
        int n = height.length, trappedWater = 0;
        if(n <= 2) return 0;
        
        int left = 1, right = n - 2, maxFromLeft = height[0], maxFromRight = height[n - 1];
        
        while(left <= right) {
            if(maxFromLeft < maxFromRight) {
                if(height[left] > maxFromLeft)
                    maxFromLeft = height[left];
                else
                    trappedWater += maxFromLeft - height[left];
                ++left;
            } else {
                if(height[right] > maxFromRight)
                    maxFromRight = height[right];
                else 
                    trappedWater += maxFromRight - height[right];
                --right;
            }
        }
        
        return trappedWater;
    }
}