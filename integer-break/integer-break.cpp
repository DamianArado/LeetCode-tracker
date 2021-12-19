class Solution {
public:
    long int integerBreak(int n) {
        // edge cases
        switch(n) {
            case 2:
                return 1;
                break;
            case 3:
                return 2;
                break;
            case 4:
                return 4;
                break;
            case 5:
                return 6;
                break;
        }
        
        long int ans = 1;
        
        if(n % 3 == 0) {
            int times = n / 3;
            for(int i = 1; i <= times; ++i)
                ans *= 3;
            return ans;
        } 
        else if(n % 3 == 2) {
            int times = n / 3;
            for(int i = 1; i <= times; ++i)
                ans *= 3;
            return ans*2;
        } 
        else {
            int times = n / 3 - 1;
            for(int i = 1; i <= times; ++i)
                ans *= 3;
            return ans*4; 
        }
            
        
        
    }
};