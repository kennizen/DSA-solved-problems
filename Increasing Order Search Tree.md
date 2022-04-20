Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

 

Example 1:


Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
Example 2:


Input: root = [5,1,7]
Output: [1,null,5,null,7]
 

Constraints:

The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000

sol - 1
tc - O(n)
sc - O(n)

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
    void inorder(TreeNode *root, vector<int> &store){
        if(root == NULL) return;
        inorder(root->left,store);
        store.push_back(root->val);
        inorder(root->right,store);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> store;
        inorder(root,store);
        
        TreeNode *tmp = NULL;
        TreeNode *pt = NULL;
        
        for(int i = 0; i<store.size(); i++){
            TreeNode *tmp1 = new TreeNode();
            tmp1->val = store[i];
            if(tmp == NULL) tmp = tmp1;
            else pt->right = tmp1;
            pt = tmp1;
        }
        
        return tmp;
    }
};

sol - 2
tc - O(n)
sc - O(1) + mem stack

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root, TreeNode* next=NULL) {
        if(root == NULL) return next;  
        root->right = increasingBST(root->right, next);  
        TreeNode *temp = increasingBST(root->left, root);  
        root->left = NULL; 
        return temp;
    }
};

sol - 3
tc - O(n)
sc - O(h), h: height of the bst

class Solution {
    TreeNode cur;
    public TreeNode increasingBST(TreeNode root) {
        TreeNode ans = new TreeNode(0);
        cur = ans;
        inorder(root);
        return ans.right;
    }

    public void inorder(TreeNode node) {
        if (node == null) return;
        inorder(node.left);
        node.left = null;
        cur.right = node;
        cur = node;
        inorder(node.right);
    }
}