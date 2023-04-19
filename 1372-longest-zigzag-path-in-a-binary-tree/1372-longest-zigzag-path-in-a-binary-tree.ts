/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */
function dfs(root: TreeNode | null, l: number, r: number, ans: number[]) {
    if(root === null) return;
    ans[0] = Math.max(ans[0], Math.max(l, r));
    dfs(root.left, r + 1, 0, ans);
    dfs(root.right, 0, l + 1, ans);
}
function longestZigZag(root: TreeNode | null): number {
    let left: number = 0;
    let right: number = 0;
    let ans: number[] = [0];
    dfs(root, left, right, ans);
    return ans[0];
};