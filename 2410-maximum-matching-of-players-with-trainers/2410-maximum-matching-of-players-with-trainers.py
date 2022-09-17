class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players, trainers = sorted(players), sorted(trainers)
        i, j, matchings = len(players) - 1, len(trainers) - 1, 0
        while i >= 0 and j >= 0:
            if players[i] > trainers[j]:
                 i -= 1
            else:
                matchings, i, j = matchings + 1, i - 1, j - 1
        return matchings