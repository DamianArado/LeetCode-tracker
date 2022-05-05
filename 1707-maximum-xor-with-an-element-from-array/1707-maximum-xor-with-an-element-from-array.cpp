/*

The brute force approach involves scanning the whole of the q queries and n nums everytime giving us O(q*n) time complexity.

Let's learn a new concept here, of "Offline Queries" -- Intuition developed as follows:

We need to xor nums[j] with x[i] such that nums[j] <= m[i]. What if we construct a trie data structure
using elements in nums which are added only if they are less than or equal to m[i] at a time, if they are at the moment greater than m[i], they are not added at all.

Hence, using the above approach we add the elements in trie, then we take x[i] and figure out the max bit 
that we can extract from the trie. So, here essentially we are making sure in each step that our trie
only contains elements not greater than m[i], then we'll give it x[i] and they will give back to us, the maxVal (similar to maxXOR of 2 numbers in a single array). This is where, Offline Queries come into picture.

For example, nums: [1, 3, 2, 5, 4], queries: [[3, 4], [5, 2], [2, 5], [3, 1]]
Generally, we solve the queries on-line like, solving it for queries[0] storing in ans, moving forward to
solve for queries[1] and again storing in ans, and so on..and then we return the ans (We return the ans
in the order of queries being asked).
What if we jumble up the queries, and we sort the queries[i] according to m[i]. 

The queries now become: [[3, 1], [5, 2], [3, 4], [2, 5]] and then to make sure we returned the answer in
correct sequence of queries, we do make an array of size = queries.size(), and then we paste the answer
at the right positions according to query[i]. We maintained query number also, hence we implemented offline queries.

Now, to solve, first sort the nums array: [1, 2, 3, 4, 5]
query no.1 - [3, 1, 3]        ---  [1, 2, 3, 4, 5]
                                 |                      // add only 1 to the trie
To calculate the answer for this, stand there and call the trie to get the max bits for 3: getMax(3) which will return back 2 as answer as max(3^1) = 2. -> ans[3] = 2;

query no.2 - [5, 2, 1]        ---   [1, 2, 3, 4, 5]
                                     |                  // add 2 to the trie
Call getMax(5) which returns 5^2 = 7 as maxXOR       -> ans[1] = 7;

query no.3 - [3, 4, 0]        ---   [1, 2, 3, 4, 5]
                                              |         // add 3 and 4 to the trie
Call getMax(3) which returns 3^4 = 7 as maxXOR       -> ans[0] = 7;

query no.4 - [2, 5, 2]        ---   [1, 2, 3, 4, 5]
                                                 |      // add 5 to the trie
Call getMax(2) which returns 2^4 = 6 as maxXOR       -> ans[2] = 6;

Hence, answer = [7, 7, 6, 2]

TC = O(nums.size() log nums.size() + query.size() log query.size())

SC - O(trie nodes + query.size())

*/

struct Node {
    Node* linkNext[2];
    
    bool containsKey(int bit) {
        return (linkNext[bit] != nullptr);
    }
    
    Node* getNext(int bit) {
        return (linkNext[bit]);
    }
    
    void put(int bit, Node* newNode) {
        linkNext[bit] = newNode;
    }
};

class Trie {
    private: Node* root;
    
    public:
        Trie() {
            root = new Node();
        }
    
        void insert(int number) {
            Node* current = root;
            for(int i = 31; i >= 0; --i) {
                int bit = (number >> i) & 1;
                if(!current->containsKey(bit)) {
                    current->put(bit, new Node());
                }
                current = current->getNext(bit);
            }
        }
    
        int getMax(int number) {
            Node* current = root;
            int maxXOR = 0;
            for(int i = 31; i >= 0; --i) {
                int bit = (number >> i) & 1;
                if(current->containsKey(!bit)) {
                    maxXOR = maxXOR | (1 << i);
                    current = current->getNext(!bit);
                } else {
                    current = current->getNext(bit);
                }
            }
            return maxXOR;
        }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // Base case
        if(nums.size() == 1 && queries.size() == 1) {
            if(nums[0] <= queries[0][1]) {
                return {queries[0][0] ^ nums[0]};
            } else return {-1};
        }
        
        // sort the nums array : O(n*log n)
        sort(nums.begin(), nums.end());
        // [m[i], [x[i], query[i]]]
        vector<pair<int, pair<int, int>>> offlineQueries;
        int n = queries.size();
        
        // O(q)
        for(int i = 0; i < n; i++) {
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }
        
        // sort the offline-queries array according to m[i] : O(q log q)
        sort(offlineQueries.begin(), offlineQueries.end());
        vector<int> ans(n, 0);
        Trie trieObj;
        
        // traversing in offline-queries now
        int index = 0;
        // O((n + q) * 32)
        for(int i = 0; i < n; ++i) {
            int xi = offlineQueries[i].second.first;
            int mi = offlineQueries[i].first;
            int queryIndex = offlineQueries[i].second.second;
            
            // making sure we do 1 pass over nums and necessary condition is also met
            while(index < nums.size() && nums[index] <= mi) {
                trieObj.insert(nums[index++]);
            }
            
            if(index != 0) ans[queryIndex] = trieObj.getMax(xi);
            else ans[queryIndex] = -1;
        }
        return ans;
    }
};