class Solution {
public:
    bool winnerOfGame(string colors) {
        int AAA = 0, BBB = 0;
        for (int i = 1; i < size(colors) - 1; ++i) {
            if (colors[i] == colors[i - 1] and colors[i] == colors[i + 1]) 
                if (colors[i] == 'A')
                    ++AAA;
                else 
                    ++BBB;
        }
        return AAA > BBB;
    }
};