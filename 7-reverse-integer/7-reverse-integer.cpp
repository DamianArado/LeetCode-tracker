class Solution {
public:
    int reverse(int x) {
        int upperLimit =  (pow(2, 31) - 1) / 10, lowerLimit = - (pow(2, 31) / 10), ans = 0;
        while(x) { 
            int lastDigit = x % 10;
			// Checking if ans will be there in integer range only.
            if(ans <= upperLimit && ans >= lowerLimit) { 
                 int temp = ans * 10 + lastDigit;
                 ans = temp;
                 x /= 10;  
            // ans would exceed the int if multiplied by 10. Thus integer overflow occur
            } else return 0;
        }
        return ans;
    }
};