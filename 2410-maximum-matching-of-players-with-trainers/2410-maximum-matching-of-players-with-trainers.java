class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(players);
        Arrays.sort(trainers);
        int i = players.length - 1, j = trainers.length - 1, matchings = 0;
        while(i >= 0 && j >= 0) {
            if(players[i] > trainers[j])
                --i;
            else {
                ++matchings;
                --i;
                --j;
            }
        }
        return matchings;
    }
}