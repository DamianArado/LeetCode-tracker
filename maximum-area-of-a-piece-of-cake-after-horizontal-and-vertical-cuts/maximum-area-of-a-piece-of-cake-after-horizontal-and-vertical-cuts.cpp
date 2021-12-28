class Solution {
    int getMax(int hh, vector<int> &h) {
        sort(h.begin(), h.end()); 
        int nh = h.size();
        int maxHeight = max(hh-h[nh-1], h[0]);
        for (int i=1; i<nh; i++) {
            maxHeight = max(maxHeight, h[i]-h[i-1]);
        }
        return maxHeight;
    }
public:
    int maxArea(int hh, int ww, vector<int>& h, vector<int>& v) {
        return (int)((long)getMax(hh, h)*getMax(ww, v)%1000000007);
    }
};