/*

General Idea:
We greedily take the smallest digit in the range of remaining k from the current index we are filling (start from 1st position) and swap it all the way left to the current index. We make sure that we have the right updated cost to take a digit by using BIT to store how many digits have been taken to the left of that digit. The actual cost of taking that digit to the current index is its position subtracted by how many digits have been taken to the left of this digit.

The remaining digts not taken is then put to the back of the answer string.

Explanation of getting the actual cost of taking a digit and swapping it all the way to the current index:
When there are no swaps done, the cost of taking a digit and swapping it to the first position is its position (subtracted by 1). Say we take the digit in position x for the first index. When we move to the next index (2nd position), the cost for all digits in front of x (to the left) is still its position (since they were all shifted right during the swapping and their distance from the current index stays the same). However, all digits to the right of x will cost less (since the current index is closer by 1, but their positions have not changed).

This continues for the rest and the actual cost of taking a digit x to the current index is its position subtracted by how many digits to the left of x has been taken. We keep track of this efficiently using the Fenwick tree.

Implementation:
In the code above, I first store the positions for each digit in priority queues (Can be done in a vector and sorted after as well).

Then, while I am still taking digits (ctr < n) and I still have remaining swaps (k > 0), I will look for the smallest affordable digit by looking at each priority queue for each digit, then if the furthest left untaken digit's actual cost is affordable, I will take it and update the Fenwick tree.

The last sorting using resort empties out the priority queues since they are filled with digits that have not been taken and I will append them to the string according to their positions since their ordering stays the same throughout all the swapping.

*/

class Solution {
    vector<pair<int, int>> resort;
    
    priority_queue<int, vector<int>, greater<int>> nums[10];
    int used[30001];
    int n;
    int getSum(int index)  {
        int sum = 0;
        while (index > 0) { 
            sum += used[index];
            index -= index & (-index); 
        } 
        return sum; 
    } 
    
    void updateBIT(int index, int val) 
    { 
        while (index <= n) 
        { 
        used[index] += val;
        index += index & (-index); 
        } 
    }
    
public:
    string minInteger(string num, int k) {
        memset(used, 0, sizeof(used));
        
        int ctr = 0;
        n = num.size();
        for (int i = 0; i < n; i++) {
            nums[num[i] - '0'].push(i + 1);
        }
        string res;
        while (ctr < n && k > 0) {
            for (int i = 0; i <= 9; i++) {
                if (!nums[i].empty()) {
                    int cur = nums[i].top();
                    
                    int holes = getSum(cur - 1);
                    int act = cur - holes;
                    if (act - 1 <= k) {
                        res += ('0' + i);
                        k -= (act - 1);
                        updateBIT(cur, 1);
                        nums[i].pop();
                        break;
                    }
                }
            }
            ctr++;
        }
        
        for(int i = 0; i <= 9; i++) {
            while (!nums[i].empty()) {
                resort.emplace_back(nums[i].top(), i);
                nums[i].pop();
            }
        }
        
        sort(resort.begin(), resort.end());
        for (auto &p : resort) {
            res += ('0' + p.second);
        }
        return res;
    }
};