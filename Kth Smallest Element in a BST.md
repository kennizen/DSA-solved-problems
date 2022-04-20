Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

ALGO:
# keep a global count
# increment when in inorder traversal
# if count == k that is the number return it
# at every left and right call check if the return val is >= 0 if yes then return it

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int count = 0;
public: 
    int kthSmallest(TreeNode *root, int k) {
        if(root == NULL) return -1;
        
        int res = kthSmallest(root->left, k);
        
        if(res >= 0) return res;
        
        count++;
        
        if(count == k) return root->val;
        
        res = kthSmallest(root->right, k);
        
        if(res >= 0) return res;
        
        return -1;
    }
};