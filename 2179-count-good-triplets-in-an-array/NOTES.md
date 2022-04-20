We first use two arrays to get a single array with indexes:
​
A number in the first array is replaced with an index of that number in the second one.
Then, we compute good triplets in that array, such as i < j < k and nums1[i] < nums1[j] < nums1[k]. This is similar to 1534. Count Good Triplets.
​
For that, we go through each middle element, and count smaller elements on the left, and greater on the right. That middle element can form smaller * greater good triplets.
​
We can use BIT (AKA Fenwick Tree) to count elements smaller (sm) than the middle element in O(n log n). Because we have n - 1 unique numbers, figuring out greater (gr) elements on the right is easy.
​
[Demo](https://assets.leetcode.com/users/images/65fa535c-37d5-4cce-b5ce-9e525e50e8df_1645383957.253021.png)
​