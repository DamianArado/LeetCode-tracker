/**
 So my approach followed basically these 2 bits of logic, doing a composition of a DFS based tree traversal and at each iteration checking if the very last value mins the targetSum were already spotted; I used a vector initially, then moved up to an array to keep track of the already seen values with a huge performance boost.

In my approach I use 3 class variables:

my typical accumulator variable res initialised to 0 to count the number of matching occurrences;
sum that takes the values of targetSum and replaces it in all of my recursive calls (so that I do not have to pass it as a parameter)
seen, as mentioned to keep track of the values I spotted so far and created to hold 1001 values (an initial 0 at root level, plus other potential 1000 different ones, as specified in the specs).
Inside my main function I initialise the values and then, provided the tree is not empty (ie: !root), I call dfs.

This function receives 3 parameters:

a mandatory root, which is the node we are currently exploring;
an optional partialSum value, defaulted to 0 and keeping track of our current partial sum going down a specific branch;
an optional pos to tell us where to put out next value in seen and up to which point browse it (muuuch faster than expanding and reducing a vector, try the alternative code down below!)
We are looking for all the occurrences of values in seen which are partialSum - sum, because it means that said value n plus partialSum would equal sum, and for each such instance we increase res by one.

If we have a ->left branch we do the same with it, passing the update root, partialSum and pos (increased by 1) down as parameters; same thing with a ->right branch, if it exists.

When we are done, we just return res
 */
class Solution {
public:
    int res = 0, sum;
    int seen[1001];
    void dfs(TreeNode* root, long partialSum = 0, int pos = 1) {
        // updating partialSum with the current node
        partialSum += root->val;
        // checking if we already found an interval summing up to that
        for (int i = 0; i < pos; i++) if (seen[i] == partialSum - sum) res++;
        // updating seen
        seen[pos] = partialSum;
        // searching potential left and right branches
        if (root->left) dfs(root->left, partialSum, pos + 1);
        if (root->right) dfs(root->right, partialSum, pos + 1);
    }
    int pathSum(TreeNode* root, int targetSum) {
        sum = targetSum;
        // seen set with initial value 0 will help us match from the root
        seen[0] = 0;
        if (!root) return res;
        dfs(root);
        return res;
    }
};