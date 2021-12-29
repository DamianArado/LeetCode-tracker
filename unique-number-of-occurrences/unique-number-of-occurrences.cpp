class Solution {
public:
    // Count occurences of each number using a hash map. Insert all occurences into a hash set. If, after the insert, the 
   // sizes of hash map and set are equal, then all occurences are unique.
/*
    bool uniqueOccurrences(vector<int>& arr) {
      unordered_map<int, int> m;
      unordered_set<int> s;
      for (auto n : arr) ++m[n];
      for (auto& p : m) s.insert(p.second);
      return m.size() == s.size();
    }
    We can improve this for the average case by checking the result of s.insert(), which returns false if an element is already there.
    Complexity Analysis
Time: O(n), where n is the size of input array.
Memory: O(m), where m is the number of unique elements (we store counts in hash map and set).

*/

    bool uniqueOccurrences(vector<int>& arr) {
      unordered_map<int, int> m;
      unordered_set<int> s;
      for (auto n : arr) ++m[n];
      for (auto& p : m)
          if (!s.insert(p.second).second) return false;
      return true;
    }
};