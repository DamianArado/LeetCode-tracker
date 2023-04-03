class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int i = 0, j = people.length - 1, boats = 0;
        Arrays.sort(people);
        while(i <= j) {
            if(people[i] + people[j] <= limit) {
                ++i;
                --j;
            } else --j;
            ++boats;
        }
        return boats;
    }
}