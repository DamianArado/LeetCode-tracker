class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        heap, total = [], 0
        courses.sort(key = lambda x : x[1])
        for i in range (len(courses)):
            heappush(heap, -courses[i][0])
            total += courses[i][0]
            if total > courses[i][1]:
                total -= -heap[0]
                heappop(heap)
        return len(heap)