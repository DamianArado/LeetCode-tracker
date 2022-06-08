class Solution {
public:
    struct comparator {
        bool operator() (string &a, string &b) {
            if(a.size() != b.size()) return a.size() > b.size();
            // both length are same, we got to iterate over one of them and compare digits
            for(int i = 0; i < a.size(); ++i) {
                if(a[i] - '0' > b[i] - '0') return true;
                else if(a[i] - '0' < b[i] - '0') return false;
            }
            return false;
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, comparator> pq;
        for(int i = 0; i < nums.size(); ++i) {
            pq.push(nums[i]);
            if(pq.size() > k) 
                pq.pop();
        }
        return pq.top();
    }
};