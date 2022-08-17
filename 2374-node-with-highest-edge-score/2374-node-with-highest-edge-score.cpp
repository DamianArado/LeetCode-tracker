class Solution {
public:
    int edgeScore(vector<int>& edges) {
        double n = edges.size(), maxScore = 0, ansNode = n + 1;
        vector<double> score(n);
        for(int i = 0; i < n; ++i) {
            score[edges[i]] += i;
            maxScore = max(maxScore, score[edges[i]]);
        }
        for(int i = 0; i < n; ++i) {
            if(score[i] == maxScore) {
                ansNode = i;
                break;
            }
        }
        return (int)ansNode;
    }
};