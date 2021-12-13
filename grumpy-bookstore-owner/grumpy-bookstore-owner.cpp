class Solution {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
		auto totalGrumpySum = 0, windowNonGrumpySum = 0, result = 0;

		for (int i = 0; i < customers.size(); i++) {

			totalGrumpySum +=  grumpy[i] ? 0 : customers[i];
			windowNonGrumpySum += grumpy[i] ? customers[i] : 0;

			if (i >= minutes) {
				windowNonGrumpySum -= grumpy[i - minutes] ? customers[i - minutes] : 0;
			}
            
			result = max(result, windowNonGrumpySum);
		}
		return totalGrumpySum + result;
	}
};