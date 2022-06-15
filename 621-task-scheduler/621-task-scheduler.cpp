class Solution {
public:
    // tc - O(n), sc - O(1)
    int leastInterval(vector<char>& tasks, int n) {
        // for counting occurrences of a task
        int count[26] = {0};
        // what is the occurrence of the max element, no. of elements having max occurrences
        int maxOccurrences = 0, maxOccurringElem = 0;
        for(char task : tasks) {
            count[task - 'A']++;
            // another element having max occurrences
            if(maxOccurrences == count[task - 'A'])
                maxOccurringElem++;
            // updating the max occurrences
            else if(maxOccurrences < count[task - 'A']) {
                maxOccurrences = count[task - 'A'];
                maxOccurringElem = 1;
            }
        }
        // Example: [A,A,A,B,B,C,C,C,C,C] and n = 2
        // number of cooldown periods between the element having the most number of occurrences
        // ---    C ? ? C ? ? C ? ? C ? ? C   ---   coolPeriods = 5 - 1 = 4
        int coolPeriods = maxOccurrences - 1;
        // ---    ? ?     ---   coolPeriodLength = 2 - 0 = 2
        int coolPeriodLength = n - (maxOccurringElem - 1);
        // ---    ? ? ? ? ? ? ? ?   ---  emptySlots = 4 * 2 = 8
        int emptySlots = coolPeriods * coolPeriodLength;
        // ---    A,A,A,B,B   ---  availableTasks = 10 - (5 * 1) = 5
        int availableTasks = tasks.size() - (maxOccurrences * maxOccurringElem);
        // ---    # # #   ---  idles = 8 - 5 = 3
        int idles = max(0, emptySlots - availableTasks);
        // ---    C,A,B,C,A,B,C,A,#,C,#,#,C  --- ans = 10 + 3 = 13
        return (tasks.size() + idles);
    }
};