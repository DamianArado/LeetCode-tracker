class Solution {

struct SegmentTree {
    SegmentTree* left;
    SegmentTree* right;
    int count;
    long min;
    long max;
    
    // nums is sorted
    SegmentTree(vector<long>& nums, int l, int r):left(NULL),right(NULL) {
        if (l>r) {
            return;
        }
        min = nums[l];
        max = nums[r];
        count=0;
        
        if (l==r) {
            return;
        }
        
        int m = (l+r)/2;
        if (l<=m) {
            left = new SegmentTree(nums, l,m);
        } else {
            left=NULL;
        }
        if (m+1<=r) {
            right = new SegmentTree(nums, m+1, r);
        } else {
            right = NULL;
        }
    }
    
    void add(long value) {
        if (value<min || value>max) {
            return;
        }
        if (value==0) {
            // cout<<"add value"<<endl;
        }
        count++;
        if (left && value<=left->max) {
            left->add(value);
        } else if (right && value>=right->min) {
            right->add(value);
        }
    }
    
    int getCount(long minValue, long maxValue) {
        if (minValue<=min && max<=maxValue) {
            // cout<<minValue<<","<<maxValue<<endl;
            return count;
        }
        
        if (maxValue<min || minValue>max) {
            return 0;
        }
        
        int leftCount = left ? left->getCount(minValue, maxValue) : 0;
        int rightCount = right ? right->getCount(minValue, maxValue) : 0;
        
        return leftCount+rightCount;
    }
    
};
    
    
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.size()==0) {
            return 0;
        }
        
        unordered_set<long> values;
        long sum = 0;
        for(int i=0;i<nums.size();++i) {
            sum+=nums[i];
            values.insert(sum);
        }

        vector<long> sums;
        for(auto& v : values) {
            sums.push_back(v);
        }

        sort(sums.begin(), sums.end());
        
        SegmentTree* tree = new SegmentTree(sums, 0, sums.size()-1);

        int count = 0;
        for(int i=nums.size()-1;i>=0;i--) {
            tree->add(sum);
            sum-=nums[i];
            // lower<= sum[i]-sum[j]<=upper
            count += tree->getCount(lower+sum, upper+sum);
        }
        
        return count;
        
    }
};