class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        row, col = len(dungeon), len(dungeon[0])
        hp = [1e9] * (col + 1)
        hp[col] = hp[col - 1] = 1
        print(hp)
        if row == 1 and col == 1 and dungeon[0][0] >= 0: return 1
        for i in range (row - 1, -1, -1):
            temp = [1e9] * (col + 1)
            for j in range (col - 1, -1, -1):
                minHP = -dungeon[i][j] + min(temp[j + 1], hp[j])
                temp[j] = 1 if minHP <= 0 else minHP
            hp = temp
        return hp[0]