class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1000000007;
        int numSeats = 0, numPlants = 0;
        long dividers = 1;
        
        for(char &item : corridor) {
            if(item == 'S') 
                numSeats += 1;
            if(numSeats == 2 and item == 'P')
                numPlants += 1;
            if(numSeats == 3) {
                dividers *= (numPlants + 1);
                dividers %= mod;
                numPlants = 0;
                numSeats = 1;
            }
        }
        
        if(numSeats < 2) return 0;
        return dividers;
    }
};