class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), sum = 0, mx = 0;
		
		// Find sum of first 'k' elements in input
        for(int i = 0; i < k; i++){
            mx += cardPoints[i];
        }
		
        sum = mx;
        
        for(int i = 0; i < k; i++){
            sum = sum + cardPoints[n - i - 1] - cardPoints[k - i - 1]; // find the difference
            mx = max(mx, sum);
        }
        
        // cardPoints = [100,40,17,9,73,75], k = 3 ; n = 6 ; sum = 157 [100 + 40 + 17 ] ; max = 157
        // i   n-i-1   k-i-1 (sum + cardPoints[n-i-1] - cardPoints[k-i-1])   sum      max
        // 0   5       2      215  [157 + 75 - 17]                           215      215
        // 1   4       1      248  [215 + 73 - 40]                           248      248
        // 2   3       0      157  [248 + 9 - 100]                           157      248
        
        
        return mx;
    }
};