class Solution {
public:
    // TC -> O(n) SC -> O(n)
	int longestWPI(vector<int>& hours) {
		 int sum = 0, ans = 0;
		 // sum to index mapping
		 unordered_map<int,int> mp;
		 for(int i = 0; i < hours.size(); ++i) {
			 sum += hours[i] > 8 ? 1 : -1;
			 // if sum till index i is greater than 0 means we have more 1 (tiring days) than non-tiring days (-1)
			 if(sum > 0) ans = max(ans, i + 1);
			 else if(mp.find(sum) == mp.end()) mp[sum] = i;
			 if(mp.find(sum - 1) != mp.end()) ans = max(ans, i - mp[sum - 1]);   
		 }
		return ans;
	}
};