/*

Solution (Vector of Index & Binary Search)

We just need to maintain a vector of indices for each element in the order they occur.
Then querying for frequency between a range [L, R] is simply finding highest index and lowest index of that element within the given range and returning number of elements between them in the vector of indices.
The highest and lowest index can be found using binary search (upper_bound and lower_bound) in O(logN) time.

Time Complexity :
RangeFreqQuery: O(N), where N is the number of elements in arr.
query: O(logN)

Space Complexity : O(N), required for maintaining hashmap

*/

class RangeFreqQuery {
    map<int, vector<int>> mp;
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < size(arr); i++) 
            mp[arr[i]].push_back(i);
    }
    
    int query(int L, int R, int V) {
        return upper_bound(begin(mp[V]), end(mp[V]), R) 
             - lower_bound(begin(mp[V]), end(mp[V]), L); 
    }
};