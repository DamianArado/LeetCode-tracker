class Solution:
    def edgeScore(self, edges: List[int]) -> int:
        n, maxScore, ansNode = len(edges), 0, -1
        score = [0] * (n)
        for i in range (n):
            score[edges[i]] += i
            maxScore = max(maxScore, score[edges[i]])
        for i in range (n):
            if score[i] == maxScore:
                ansNode = i
                break
        return ansNode