You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Example 1:

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:

Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

Constraints:

The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1

Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?

ALGO

# inorder

# requires 3 nodes

# check if first node is empty and prev node us also empty if yes first = prev

# check if first is not empty ans prev is >= current node then second = node

# swap first and second

# from left first out of order node will always be bigger than next node

# from right second out of order node will always be less than prev node

/\*\*

-   Definition for a binary tree node.
-   struct TreeNode {
-       int val;
-       TreeNode *left;
-       TreeNode *right;
-       TreeNode() : val(0), left(nullptr), right(nullptr) {}
-       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
-       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
-   };
    _/
    class Solution {
    public:
    TreeNode_ tmp1 = NULL;
    TreeNode* tmp2 = NULL;
    TreeNode* prev = NULL;
        void inorder(TreeNode *node){
            if(node == NULL) return;

            inorder(node->left);

            if(tmp1 == NULL && (prev == NULL || prev->val >= node->val)){
                tmp1 = prev;
            }

            if(tmp1 != NULL && prev->val >= node->val){
                tmp2 = node;
            }

            prev = node;

            inorder(node->right);
        }

        void recoverTree(TreeNode* root) {
            inorder(root);
            swap(tmp1->val, tmp2->val);
        }
    };
