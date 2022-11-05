class Solution {
public:
    int nextGreaterElement(int num) {
        string no = to_string(num);
        int n = size(no);
        if(n == 1) return -1;
        
        int suffixStart = n - 1;
        while(suffixStart > 0 and no[suffixStart - 1] >= no[suffixStart])
            --suffixStart;
        if(suffixStart == 0 and no[0] >= no[1])
            reverse(begin(no), end(no));
        else {
            int pivot = suffixStart - 1, rightmostGreater = n - 1;
            while(no[pivot] >= no[rightmostGreater])
                --rightmostGreater;
            swap(no[pivot], no[rightmostGreater]);
            reverse(begin(no) + suffixStart, end(no));
        }
        
        return stoll(no) > INT_MAX or stoll(no) <= num ? -1 : stoll(no);
    }
};