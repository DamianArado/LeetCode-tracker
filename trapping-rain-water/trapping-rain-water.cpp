// O(n) approach   ^_^

class Solution {
public:
    int trap(vector<int>& height) {
        // number of bars
        int n = height.size();
        
        // edge case
        if(n == 1 || n == 2)
            return 0;
        
        // maintain 2 variables to track both ends
        int left = 0, right = n-1;
        
        int waterStored = 0;
        
        // store max elements on both ends
        int maxLeft = 0, maxRight = 0;
        
        // left should not cross over right
        while(left <= right) {
            
            // in this case height of right is greater or equal to that of left
            if(height[left] <= height[right]) {
                
                // so water stored depends on the left side (lower heighted portion)
                // maxLeft is the max height element we get until we reach right variable
                if(height[left] >= maxLeft)
                    maxLeft = height[left];
                else
                    
                    // water trapped += maximum element yet (from L) - height of current bar
                    waterStored += maxLeft - height[left];
                
                // increment to the next position (L -> R)
                left++;
                
            // in this case height of left is more than that of right
            } else {
                
                // so water stored depends on the right side (lower heighted portion)
                // collecting max height element from the right side now
                if(height[right] >= maxRight)
                    maxRight = height[right];
                else
                    // water trapped += maximum element yet (from R) - height of current bar
                    waterStored += maxRight - height[right];
                
                // incrementing (L <- R)
                right--;
            }
        }
        return waterStored;
    }
};