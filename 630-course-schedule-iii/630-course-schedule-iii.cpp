/* 

This solution fails on this testcase: [[[5,5],[4,6],[2,6]]], making you realize that it's a hard labelled question!! and hence won't be having a straightforward solution
class Solution {
private:
    static bool comparator(vector<int> &c1, vector<int> &c2) {
        if(c1[1] <= c2[1]) return true;
        else if(c1[1] > c2[1]) return false;
        else if(c1[0] <= c2[0]) return true;
        return false;
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size(), start = 0, coursesDone = 0;
        sort(courses.begin(), courses.begin(), comparator);
        for(int i = 0; i < n; ++i) {
            if(start + courses[i][0] <= courses[i][1]) {
                coursesDone += 1;
                start += courses[i][0];
            }
        }
        return coursesDone;
    }
}; 

To say the least, we'll use the same approach that we did earlier but we will also use a max heap to keep 
a track of the longer course that we took earlier and that should not have been taken and thus we add the
shorter one to the max heap (exchanging longer one with the shorter one so that we can do the max no. of courses)

*/

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> maxHeap;
        // sorting courses on the basis of early ending time
        sort(courses.begin(), courses.end(), [] (const vector<int> &c1, const vector<int> &c2) {
            return c1[1] < c2[1];
        });
        // total means the total duration taken by use to complete the max no. of courses
        for(int i = 0, total = 0; i < courses.size(); ++i) {
            // at each step add the current course's duration inside the max heap
            maxHeap.push(courses[i][0]);
            // if the total duration exceeds the last day of the current course
            // we need to pop the max heap which will help us to exchange the longer duration course with the
            // shorter duration course that we are doing currently
            if((total += courses[i][0]) > courses[i][1]) {
                total -= maxHeap.top();
                maxHeap.pop();
            }
        }
        // the max heap contains the max no. of courses that we can take
        return maxHeap.size();
    }
};