class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        arr = [0] + arr
        stack = [0]
        n = len(arr)
        res = [0] * n
        
        for i in range (n):
            while arr[stack[-1]] > arr[i]:
                stack.pop()
            j = stack[-1]
            res[i] = res[j] + (i - j) * arr[i]
            stack.append(i)
        
        ans = sum(res)
        return ans % (10 ** 9 + 7)
            