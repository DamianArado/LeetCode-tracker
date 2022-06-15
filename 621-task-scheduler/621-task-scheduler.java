class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] count = new int[26];
        int maxOccurrences = 0, maxOccurringElem = 0;
        for(char task : tasks) {
            count[task - 'A']++;
            if(maxOccurrences == count[task - 'A'])
                maxOccurringElem++;
            else if(maxOccurrences < count[task - 'A']) {
                maxOccurrences = count[task - 'A'];
                maxOccurringElem = 1;
            }
        }
        int coolPeriods = maxOccurrences - 1;
        int coolPeriodLength = n - (maxOccurringElem - 1);
        int emptySlots = coolPeriods * coolPeriodLength;
        int availableTasks = tasks.length - (maxOccurrences * maxOccurringElem);
        int idles = Math.max(0, emptySlots - availableTasks);
        
        return (tasks.length + idles);
    }
}