class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1000000007;
        int numSeats = 0, numPlants = 0;
        long dividers = 1;
        
        for(char &item : corridor) {
            if(item == 'S') 
                numSeats += 1;
            // as we only care about plants when we crossed 2 seats
            if(numSeats == 2 and item == 'P')
                numPlants += 1;
            // its time to divide as we got a 3rd seat
            if(numSeats == 3) {
                // + 1 as we count the position of the 3rd seat as well
                // number of dividers installed till now will be reused in future for total number of dividers
                dividers *= (numPlants + 1);
                dividers %= mod;
                numPlants = 0;
                // after installing a divider before or on the 3rd seat, its considered as our 1st seat now
                numSeats = 1;
            }
        }
        
        // no need to divide
        if(numSeats < 2) return 0;
        
        return dividers;
    }
};