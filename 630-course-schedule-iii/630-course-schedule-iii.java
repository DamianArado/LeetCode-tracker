class Solution {
    public int scheduleCourse(int[][] courses) {
        var maxHeap = new PriorityQueue<Integer>(Comparator.reverseOrder());
        Arrays.sort(courses, Comparator.comparingInt(course -> course[1]));
        for(int i = 0, total = 0; i < courses.length; ++i) {
            maxHeap.add(courses[i][0]);
            if((total += courses[i][0]) > courses[i][1])
                total -= maxHeap.poll();
        }
        return maxHeap.size();
    }
}